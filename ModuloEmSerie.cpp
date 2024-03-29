#include "Modulo.h"
#include "ModuloEmSerie.h"
#include <stdexcept>
#include "Sinal.h"

using namespace std;

ModuloEmSerie::ModuloEmSerie() : Modulo() {}

ModuloEmSerie::~ModuloEmSerie() {

}

Sinal* ModuloEmSerie::processar(Sinal* sinalIN) {
    int aux = 0;
    Sinal* sinalOUT = sinalIN;

    for(list<CircuitoSISO*>::iterator i = circuitos->begin(); i != circuitos->end(); i++) {
        if(dynamic_cast<CircuitoSISO*>((*i)) != NULL){
        sinalOUT = (*i)->processar(sinalOUT);
        aux++;
        }
        
    }

    if(aux == 0) throw new logic_error("");

    return sinalOUT;

}

