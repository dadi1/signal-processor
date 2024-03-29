#ifndef MODULO_H
#define MODULO_H
#include "CircuitoSISO.h"
#include <list>

using namespace std;

class Modulo : public CircuitoSISO {
private:

protected:
    list<CircuitoSISO*>* circuitos;

public:
    Modulo();
    virtual ~Modulo();
    virtual void adicionar(CircuitoSISO* circ);
    virtual list<CircuitoSISO*>* getCircuitos();
    void imprimir();

};

#endif