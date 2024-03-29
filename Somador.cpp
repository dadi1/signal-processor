#include "Somador.h"
#include "Sinal.h"
using namespace std;

Somador::Somador() : CircuitoMISO() {
    
}

Somador::~Somador() {
 
}

Sinal* Somador::processar(Sinal* sinalIN1, Sinal* sinalIN2) {
    double *sequencia1 = sinalIN1->getSequencia();
    double *sequencia2 = sinalIN2->getSequencia();
  
    if(sinalIN1->getComprimento() >= sinalIN2->getComprimento())
        this->comprimentoOUT = sinalIN2->getComprimento();

    else 
        this->comprimentoOUT = sinalIN1->getComprimento();

    this->sequenciaOUT = new double[this->comprimentoOUT];

    for(int i = 0; i < comprimentoOUT; i++) 
        this->sequenciaOUT[i] = sequencia1[i] + sequencia2[i];
    
    Sinal *sinalOUT = new Sinal(this->sequenciaOUT, this->comprimentoOUT);
    
    delete[] sequenciaOUT;
    return sinalOUT;
    

}