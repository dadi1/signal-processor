#include "Circuito.h"
#include <iostream>

using namespace std;


int Circuito::ID = 0;

Circuito::Circuito() {
    Circuito::ID++;
    this->idUnico = getUltimoID();
}

Circuito::~Circuito() {

}

int Circuito::getID() {
    return this->idUnico;
}
int Circuito::getUltimoID() {
    return Circuito::ID;
}

void Circuito::imprimir() {
    cout << "Circuito com ID " << getID() << endl;
}

