#include "Carro2.h"

Carro2::Carro2(int xi, int yi, int vxi, int comprimento, int id, int dano, int atraso):Inimigo(xi, yi, vxi, comprimento, id, dano, atraso){
}

Carro2::~Carro2(){
}

void Carro2::mover(Matriz* M){
    if(this->v > 0){
        if(this->y + this->comprimento < 16) //Evita segmentation fault
            setCoordenadas(this->x, this->y + 1);
        else deletarInimigo();
    }
    else{
        if(this->y > 0)
            setCoordenadas(this->x, this->y - 1);
        else deletarInimigo();
    }

    srand(time(NULL));

    int mov = rand()%3;

    if(mov == 1){
        if(this->x > 0 && !evitaColisao(this->x - 1, this->y, M)) //Evita segmentation fault e colisão
            setCoordenadas(this->x - 1, this->y);
        else deletarInimigo();
    } 
    else if (mov == 2){
        if(this->x < 7 && !evitaColisao(this->x + 1, this->y, M)) //Evita segmentation fault e colisão
            setCoordenadas(this->x + 1, this->y);
        else deletarInimigo();
    }
}

int Carro2::evitaColisao(int x, int y, Matriz* M){
    if(M->getPosiMatriz(x, y) != 0)
        return 1;
    else return 0;

}