#ifndef CIRCUITOMISO_H
#define CIRCUITOMISO_H

#include "Sinal.h"
#include "Circuito.h"

class CircuitoMISO : public Circuito {
    private:

    protected:

    public:
    
        CircuitoMISO();
        virtual ~CircuitoMISO();
        virtual Sinal* processar(Sinal* sinalIN1, Sinal* sinalIN2) = 0;
};

#endif