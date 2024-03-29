#ifndef CIRCUITO_H
#define CIRCUITO_H

class Circuito {
private:
    static int ID;
    
protected:
    
    int idUnico;


public:
    Circuito();
    virtual ~Circuito() = 0;
    int getID();
    void imprimir();
    static int getUltimoID();
};

#endif