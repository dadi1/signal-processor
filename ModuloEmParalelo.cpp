#include "Modulo.h"
#include "ModuloEmParalelo.h"
#include <stdexcept>
#include "Sinal.h"
#include "Somador.h"

using namespace std;

ModuloEmParalelo::ModuloEmParalelo() : Modulo() {}

ModuloEmParalelo::~ModuloEmParalelo() {

}

Sinal* ModuloEmParalelo::processar(Sinal* sinalIN) {
    Sinal* sinalOUT = new Sinal(0.0, 60);
    Somador* sum = new Somador();
    if(circuitos->empty()) throw new logic_error("");
    
    for(list<CircuitoSISO*>::iterator i = circuitos->begin(); i != circuitos->end(); i++) {
        Sinal* aux = (*i)->processar(sinalIN);
        sinalOUT = sum->processar(aux, sinalOUT);
        delete aux;
    }
   
    delete sum;
    return sinalOUT;
    
}

