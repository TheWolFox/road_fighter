#include "Jogador.h"

Jogador::Jogador(int xi, int yi, int vxi, int comprimento, int id):Veiculo (xi, yi, vxi, comprimento, id){
    this->pontuacao = 0;
    this->tecla = NULL;
    this->id = 1;
}

void Jogador::mover(char tecla) {

    switch (tecla)
    {
    case 'a':
        this->x = x - 1;
        break;

    case 'd':
        this->x = x + 1;
        break;

    case 's':
        if (this->v > 1)
            this->v = v - 1;
        break;

    case 'w':
        if (this->v < VMAX)
            this->v = v + 1;
        break;
    
    default:
        break;
    }
    this->tecla = NULL;
}

void Jogador::mover(int x, int y){
    setCoordenadas(this->x + x, this->y);

    if(y == -1)
        setVelocidade(VELOCIDADE_MIN);
    else if(y == 1)
        setVelocidade(VELOCIDADE_MXM);
    else
        setVelocidade(VELOCIDADE_PADRAO);

}

int Jogador::colide(Matriz* M, float tempo){
    int pos = M->getPosiMatriz(this->x, this->y), i = 0;
    if (pos != 0){
        while (M->getPosiMatriz(this->x, this->y + i) != 0){
            M->setPosiMatriz(this->x, this->y + i, 0);
            i++;
        }

        i = 1;

        while (M->getPosiMatriz(this->x, this->y - i) != 0){
            M->setPosiMatriz(this->x, this->y - i, 0);
            i++;
        }
        return 10*pos;
    } else return 0;
}
