#include "CircuitoSISO.h"
#include <list>
#include "Modulo.h"
#include <iostream>

using namespace std;

Modulo::Modulo() : CircuitoSISO() {
    circuitos = new list<CircuitoSISO*>();
}

Modulo::~Modulo() {
    if (!circuitos->empty()) for(list<CircuitoSISO*>::iterator i = circuitos->begin(); i != circuitos->end(); i++) {
        delete (*i);
    }
    delete circuitos;
}

void Modulo::imprimir() {
    cout << "Modulo com ID " << this->getID() << " e:" << endl;

    for(list<CircuitoSISO*>::iterator i = circuitos->begin(); i != circuitos->end(); i++) {
        (*i)->imprimir();
    }
}
void Modulo::adicionar(CircuitoSISO* circ) {
    circuitos->push_back(circ);
}

list<CircuitoSISO*>* Modulo::getCircuitos() {
    return circuitos;
}
