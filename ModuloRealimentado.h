#ifndef MODULOREALIMENTADO_H
#define MODULOREALIMENTADO_H

#include "Sinal.h"
#include "Amplificador.h"
#include "Somador.h"
#include "Modulo.h"
#include "ModuloEmSerie.h"
#include "CircuitoSISO.h"
#include <list>

class ModuloRealimentado : public Modulo {
    private:
    ModuloEmSerie *mod;
    Amplificador *amp;
    Somador *sum;
    Sinal *saidaInvertida;
    double vInicial = 0;
    Sinal *diferenca;
    Sinal *saida;
    

    public:
    ModuloRealimentado();
    virtual ~ModuloRealimentado();
    Sinal* processar(Sinal* sinalIN);

    void adicionar(CircuitoSISO* circ);
    list<CircuitoSISO*>* getCircuitos();
};


#endif