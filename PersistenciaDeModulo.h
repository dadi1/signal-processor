#ifndef PERSISTENCIADEMODULO_H
#define PERSISTENCIADEMODULO_H

#include "Modulo.h"
#include <fstream>
#include "CircuitoSISO.h"
using namespace std;

class PersistenciaDeModulo  {

private:
    string nomeDoArquivo;
    int auxDeLeitura = 0;
public:

    PersistenciaDeModulo(string nomeDoArquivo);
    virtual ~PersistenciaDeModulo();
    void salvarEmArquivo(Modulo* mod);
    Modulo* lerDeArquivo();

    CircuitoSISO* aux(ifstream& input, char a);
    Modulo* auxModulo(ifstream& input, char a);
    void salvarEmArquivoAUX(Modulo*, ofstream& output);
};
#endif