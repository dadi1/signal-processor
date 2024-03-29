#include "PersistenciaDeModulo.h"
#include "Modulo.h"
#include <fstream>
#include <stdexcept>
#include "ModuloEmParalelo.h"
#include "ModuloEmSerie.h"
#include "ModuloRealimentado.h"
#include "Modulo.h"
#include <list>
#include "Amplificador.h"
#include "Integrador.h"
#include "Derivador.h"
#include <iostream>
#include "CircuitoSISO.h"

using namespace std;

PersistenciaDeModulo::PersistenciaDeModulo(string nomeDoArquivo) {
    this->nomeDoArquivo = nomeDoArquivo;
}

PersistenciaDeModulo::~PersistenciaDeModulo() {

}

void PersistenciaDeModulo::salvarEmArquivo(Modulo* mod) {
    ofstream output;
    output.open(nomeDoArquivo);
    
    if(dynamic_cast<ModuloEmSerie*>(mod) != NULL) output << "S" << endl;

    if(dynamic_cast<ModuloEmParalelo*>(mod) != NULL) output << "P" << endl;

    if(dynamic_cast<ModuloRealimentado*>(mod)!= NULL) output << "R" << endl;

    for(list<CircuitoSISO*>::iterator i = mod->getCircuitos()->begin(); i != mod->getCircuitos()->end(); i ++) {
        if(dynamic_cast<Amplificador*>((*i))!= NULL) {
            output << "A " << dynamic_cast<Amplificador*>((*i))->getGanho() << endl;
        }

        if(dynamic_cast<Integrador*>((*i))!= NULL) output << "I" << endl;

        if(dynamic_cast<Derivador*>((*i))!= NULL) output << "D" << endl;

        if(dynamic_cast<Modulo*>((*i))!= NULL) {
            salvarEmArquivoAUX(dynamic_cast<Modulo*>((*i)), output);
        }

    }
    output << "f" << endl;
    output.close();
}


void PersistenciaDeModulo::salvarEmArquivoAUX(Modulo* mod, ofstream& output) {

    if(dynamic_cast<ModuloEmSerie*>(mod) != NULL) output << "S" << endl;

    if(dynamic_cast<ModuloEmParalelo*>(mod) != NULL) output << "P" << endl;

    if(dynamic_cast<ModuloRealimentado*>(mod)!= NULL) output << "R" << endl;

    for(list<CircuitoSISO*>::iterator i = mod->getCircuitos()->begin(); i != mod->getCircuitos()->end(); i ++) {
        if(dynamic_cast<Amplificador*>((*i))!= NULL) {
            output << "A " << dynamic_cast<Amplificador*>((*i))->getGanho() << endl;
        }

        if(dynamic_cast<Integrador*>((*i))!= NULL) output << "I" << endl;

        if(dynamic_cast<Derivador*>((*i))!= NULL) output << "D" << endl;

        if(dynamic_cast<Modulo*>((*i))!= NULL) {
            salvarEmArquivoAUX(dynamic_cast<Modulo*>((*i)), output);
        }

    }
    output << "f" << endl;
}


Modulo* PersistenciaDeModulo::lerDeArquivo() {
    ifstream input;
    ofstream output;
    char a;
    
    Modulo* mod;
    

    input.open(nomeDoArquivo);

    if (input.fail()) throw new invalid_argument("A");
        
    input >> a;

    mod = auxModulo(input, a);
    
    input.close();
    return mod;


}

CircuitoSISO* PersistenciaDeModulo::aux(ifstream& input, char a) {
    
    int obs = 0;
        
        


        if (a == 'A') {
            double b;
            input >> b;
            
            return new Amplificador(b);
            obs++;
        }

        if (a == 'I') {
            return new Integrador();
            obs++;
            }

        if (a == 'D') {
            return new Derivador();
            obs++;
            }

        if (a == 'S' || a == 'P' || a == 'R') {
            return auxModulo(input, a);
            obs++;
        }

        if(!input) throw new logic_error("B");

        if(obs == 0) throw new logic_error("C");
        return nullptr;
}

    Modulo* PersistenciaDeModulo::auxModulo(ifstream& input, char a) {
        Modulo* mod;

        if (a == 'S') mod = new ModuloEmSerie();

        if (a == 'P') mod = new ModuloEmParalelo();

        if (a == 'R') mod = new ModuloRealimentado();

        
        while (input >> a && a != 'f') mod->adicionar(aux(input, a));

        return mod;
    }