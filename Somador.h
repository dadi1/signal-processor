#ifndef SOMADOR_H
#define SOMADOR_H 
#include "CircuitoMISO.h"
#include "Sinal.h"

class Somador : public CircuitoMISO{
    private:
    double *sequenciaOUT;
    int comprimentoOUT;

    public:

    Somador();
    virtual ~Somador();
    Sinal* processar(Sinal* sinalIN1, Sinal* sinalIN2);

};

#endif