#include "ModuloRealimentado.h"
#include "Sinal.h"
#include "Amplificador.h"
#include "Somador.h"
#include "CircuitoSISO.h"

    ModuloRealimentado::ModuloRealimentado() : Modulo() {
            
            this->sum = new Somador();
            this->amp = new Amplificador(-1);
            this->mod = new ModuloEmSerie();
    }

    ModuloRealimentado::~ModuloRealimentado() {
        delete this->mod;
        delete this->sum;
        delete this->amp;
        
    }

    Sinal* ModuloRealimentado::processar(Sinal* sinalIN) {

        double *sequenciaSaidaInvertida = new double[sinalIN->getComprimento()];
        sequenciaSaidaInvertida[0] = this->vInicial;
        this->diferenca = new Sinal(sinalIN->getSequencia(), 1);
        this->saida = this->mod->processar(this->diferenca);
        delete diferenca;

        for(int i = 1; i < sinalIN->getComprimento(); i++) {

            this->saida = amp->processar(saida);
            double *aux = this->saida->getSequencia();
            sequenciaSaidaInvertida[i] = aux[i-1];

            this->saidaInvertida = new Sinal(sequenciaSaidaInvertida, i+1);
            this->diferenca = this->sum->processar(sinalIN, saidaInvertida);

            delete saida;
            this->saida = this->mod->processar(diferenca);

            delete this->saidaInvertida;
            delete this->diferenca;
        }

        delete[] sequenciaSaidaInvertida;
        return saida;
    }

    void ModuloRealimentado::adicionar(CircuitoSISO* circ) {
        this->mod->adicionar(circ);
        
    }

    list<CircuitoSISO*>* ModuloRealimentado::getCircuitos() {
        return mod->getCircuitos();
    }