#ifndef CARRO2_H
#define CARRO2_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Inimigo.h"

class Carro2 : public Inimigo
{
    /*private:
        int velocidadex;*/
    public:
        Carro2(int xi, int yi, int vxi, int comprimento, int id, int dano, int atraso);
        ~Carro2();

        void mover(Matriz* M);
        int evitaColisao(int x, int y, Matriz* M); /* Verifica se haverá colisão caso seja movido para posiçaõ xy */
};

#endif
