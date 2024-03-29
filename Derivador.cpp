#include "Derivador.h"
#include "Sinal.h"
#include "CircuitoSISO.h"

Derivador::Derivador() : CircuitoSISO() {

}

Derivador::~Derivador() {
    
}

Sinal* Derivador::processar(Sinal* sinalIN) {

    this->comprimentoOUT = sinalIN->getComprimento();
    this->sequenciaAUX = sinalIN->getSequencia();
    this->sequenciaOUT = new double[this->comprimentoOUT];
    this->sequenciaOUT[0] = this->sequenciaAUX[0];

    for(int i = 1; i < this->comprimentoOUT; i ++) 
        this->sequenciaOUT[i] = this->sequenciaAUX[i] - this->sequenciaAUX[i-1];

    Sinal *sinalOUT = new Sinal(this->sequenciaOUT, this->comprimentoOUT);
    delete[] sequenciaOUT;
    delete[] sequenciaAUX;
    return sinalOUT;
}