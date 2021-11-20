#ifndef PISTA_H
#define PISTA_H

class Pista
{
private:
    int xi;
    int xf;
    int comprimento; // qnt de Leds na vertical

public:
    Pista(int xi = 0, int xf = 7, int comprimento = 50);
    ~Pista();

    int getXi() {return this->xi;}
    int getXf() {return this->xf;}
    int getComprimento(){ return this->comprimento; }
};

#endif
