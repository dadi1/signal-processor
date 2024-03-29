#ifndef MODULOEMPARALELO_H
#define MODULOEMPARALELO_H

#include "Modulo.h"
#include "Sinal.h"
class ModuloEmParalelo : public Modulo {
private:

protected:

public:
ModuloEmParalelo();
virtual ~ModuloEmParalelo();
Sinal* processar(Sinal* sinalIN);

};
#endif