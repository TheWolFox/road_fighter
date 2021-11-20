#include "Inimigo.hpp"

Inimigo::Inimigo(float xi, float yi, float vxi, float vyi, float danoTempo, float danoPonto, int comprimento) :
    Veiculo(xi, yi, vxi, vyi, comprimento),
    danoPonto(danoPonto),
    danoTempo(danoTempo),
{

}

Inimigo::~Inimigo()
{

}

bool Inimigo::colideX(Inimigo* inimigo)
{
    
}


bool Inimigo::colide(Inimigo* inimigo)
{

    if( this->x != inimigo->getX() ) return false;

    for(float i = this->y; i < this->y + this->comprimento; i++){
        for(float j = inimigo->getY(); j < inimigo->getY() + inimigo->getComprimento(); j++)
            if(i == j)
                return true;
    }
    
    return false;
}