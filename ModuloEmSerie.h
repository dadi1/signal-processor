#ifndef MODULOEMSERIE_H
#define MODULOEMSERIE_H

#include "Modulo.h"
#include "Sinal.h"
class ModuloEmSerie : public Modulo {
private:

protected:

public:
ModuloEmSerie();
virtual ~ModuloEmSerie();
Sinal* processar(Sinal* sinalIN);

};
#endif