#include "Amplificador.h"
#include "Sinal.h"
#include "CircuitoSISO.h"

void Amplificador::setGanho(double ganho) {
    this->ganho = ganho;
}

Amplificador::Amplificador(double ganho) : CircuitoSISO() {
    this->setGanho(ganho);
}

Amplificador::~Amplificador() {
    
}

Sinal* Amplificador::processar(Sinal* sinalIN) {

    this->sequenciaOUT = new double[sinalIN->getComprimento()];
    
    for(int i =0; i < sinalIN->getComprimento(); i++) {
        sequenciaOUT[i] = this->ganho * sinalIN->getSequencia()[i];
    }
    Sinal *sinalOUT = new Sinal(sequenciaOUT, sinalIN->getComprimento());
    delete[] sequenciaOUT;
    return sinalOUT;
    
}

double Amplificador::getGanho() {
    return this->ganho;
}
