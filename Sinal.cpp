#include <string>
#include "Sinal.h"
#include "Grafico.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Sinal::Sinal(double *sequencia, int comprimento) {
    if(comprimento <= 0) throw new invalid_argument("Comprimento invalido");
    
    else {

    this->comprimento=comprimento;
    this->sequencia = new double[comprimento];
    for(int i = 0; i < comprimento; i++){
     this->sequencia[i] = sequencia[i];
    }
    }
}

Sinal::Sinal(double constante, int comprimento) {
    
    if(comprimento <= 0) throw new invalid_argument("Comprimento invalido");


    else{ 

    this->comprimento=comprimento;
    this->sequencia = new double[comprimento];
    for(int i = 0; i < comprimento; i++){
     this->sequencia[i] = constante;
    }
    }
}

Sinal::~Sinal() {
    delete[] sequencia;
   
}

double* Sinal::getSequencia() {
    return this->sequencia;
}

int Sinal::getComprimento() {
    return this->comprimento;
}

void Sinal::imprimir(string nomeDoSinal) {

    Grafico *graficoI = new Grafico(nomeDoSinal, this->getSequencia(), this->getComprimento());
    graficoI->plot();
    delete graficoI;
}

void Sinal::imprimir() {
    for(int i = 0; i < comprimento; i++) {
        cout << i << "- " << getSequencia()[i] << endl;
    }
    cout << "--" << endl;

}

void Sinal::imprimir(int tamanho) {
    int aux;
    if(tamanho > comprimento) 
        aux = comprimento;
    else
        aux = tamanho;

    for(int i = 0; i < aux; i++) {
        cout << i << "- " << getSequencia()[i] << endl;
    }
    cout << "--" << endl;
}