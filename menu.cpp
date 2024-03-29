#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <string>
#include "Sinal.h"
#include "Amplificador.h"
#include "Somador.h"
#include "Derivador.h"
#include "Integrador.h"
#include "ModuloRealimentado.h"
#include "PersistenciaDeModulo.h"
#include "Modulo.h"
#include "CircuitoSISO.h"
#include "ModuloEmParalelo.h"
#include "ModuloEmSerie.h"
#include <stdexcept>

using namespace std;

Sinal* novoSinal() {
    int escolha;
    Sinal *sinalOUT;
    cout << "Qual sinal voce gostaria de utilizar como entrada de sua simulacao?" << endl;
    cout << "1) 5+3*cos(n*pi/8)" << endl;
    cout << "2) constante" << endl;
    cout << "3) rampa" << endl;
    cout << "Escolha: ";
    cin >> escolha;
    cout << endl;

    if(escolha == 1) {
        double *seq = new double[60];
        for(int n = 0; n < 60; n++) {
            seq[n] = 5+3*cos((n*M_PI)/8);
        } 
        sinalOUT = new Sinal(seq, 60);
        delete[] seq;
        
    }

    if(escolha == 2) {
        double cte;
        
        cout << "Qual o valor dessa constante?" << endl;
        cout << "C = ";
        cin >> cte;
        cout << endl;

        double *seq = new double[60];
        for(int i = 0; i < 60; i++) {
            seq[i] = cte;
        }

        sinalOUT = new Sinal(seq, 60);
        delete[] seq;
        
    }

    if(escolha == 3) {
        double a;
        cout << "Qual a inclinacao dessa rampa?" << endl;
        cout << "a = ";
        cin >> a;
        cout << endl;
        double *seq = new double[60];
        for(int i = 0; i < 60; i++) {
            seq[i] = a*i;
        }

        sinalOUT = new Sinal(seq, 60);
        delete[] seq;
        

    }
    return sinalOUT;
}

void novaOperacao(Modulo* mod) {
    double g;
    int escolha2;
    cout << "Qual operacao voce gostaria de fazer?" << endl;

    cout << "1) Amplificar" << endl << "2) Derivar" << endl << "3) Integrar" << endl;
    
    cout << "Escolha: ";
    cin >> escolha2;
    cout << endl;

    if(escolha2 == 1) {
            
        cout << "Qual o ganho dessa amplificacao?" << endl;
        cout << "g = ";
        cin >> g;
        cout << endl;
        mod->adicionar(new Amplificador(g));
    }

    if(escolha2 == 2) mod->adicionar(new Derivador());
        
        
    

    if(escolha2 == 3) mod->adicionar(new Integrador());

    

    cout << "O que voce quer fazer agora?" << endl;
    cout << "1) Realizar mais uma operacao no resultado" << endl;
    cout << "2) Imprimir o resultado" << endl;
    cout << "Escolha: "; 
    cin >> escolha2;
    cout << endl;

    if(escolha2 == 1) {
        novaOperacao(mod);
    }
    }




void menu() {
    Sinal *sinalIN;
    Modulo* mod;
    int escolha;
    cout << "   Simulink em C++" << endl;
    cout << "Qual simulacao voce gostaria de fazer?" << endl;
    cout << "1) Circuito advindo de arquivo" << endl;
    cout << "2) Sua propria sequencia de operacoes" << endl;
    cout << "Escolha: ";
    cin >> escolha;
    cout << endl;

    sinalIN = novoSinal();
    
    if(escolha == 1) {
        string nome;
        cout << "Qual o nome do arquivo a ser lido?" << endl;
        cout << "Nome: ";
        cin >> nome;
        cout << endl;
         
        PersistenciaDeModulo* per = new PersistenciaDeModulo(nome);
        try {
            mod = per->lerDeArquivo();
        }
        catch (logic_error *e){
            cout << e->what() << endl;
            delete e;
        }
        

        delete per;
        
    }

    if(escolha == 2) {
        int opc;
        cout << "Qual estrutura de operacoes voce deseja ter como base?" << endl;
        cout << "1) Operacoes em serie nao realimentadas" << endl;
        cout << "2) Operacoes em paralelo nao realimentadas" << endl;
        cout << "1) Operacoes em serie realimentadas" << endl;
        cout << "Escolha: ";
        cin >> opc;
        cout << endl;

        if (opc == 1) {
            mod = new ModuloEmSerie();
            novaOperacao(mod);
        }

        if (opc == 2) {
            mod = new ModuloEmParalelo();
            novaOperacao(mod);
        }
        
        if (opc == 3) {
            mod = new ModuloRealimentado();
            novaOperacao(mod);
        }
        
    }

    try {
        mod->processar(sinalIN)->imprimir("Resultado final"); //testando
    }
    catch (logic_error *e) {
        cout << e->what() << endl;
        delete e;
    }


    cout << "Voce gostaria de salvar o circuito em um novo arquivo?" << endl;
    cout << "1) Sim" << endl;
    cout << "2) Nao" << endl;
    cout << "Escolha: ";
    cin >> escolha;
    cout << endl;

    if (escolha == 1) {
        string fileName;
        cout << "Qual o nome do arquivo a ser escrito?" << endl;
        cout << "Nome: ";
        cin >> fileName;
        cout << endl;
        PersistenciaDeModulo* persistencia = new PersistenciaDeModulo(fileName);
        persistencia->salvarEmArquivo(mod);
        delete persistencia;
    }

    delete mod; 
}

