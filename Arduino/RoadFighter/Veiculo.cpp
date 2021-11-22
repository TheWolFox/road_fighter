#include "Veiculo.hpp"

Veiculo::Veiculo(float xi, float yi, float vxi, float vyi, int comprimento) :
  x(xi), y(yi), vx(vxi), vy(vyi), comprimento(comprimento)
{

}

Veiculo::~Veiculo()
{

}

void Veiculo::mover(float dx, float dy)
{
  this->x += dx;
  this->y += dy;
}

bool Veiculo::colide(Veiculo* inimigo)
{

    if( this->x != inimigo->getX() ) return false;

    for(float i = this->y; i < this->y + this->comprimento; i++){
        for(float j = inimigo->getY(); j < inimigo->getY() + inimigo->getComprimento(); j++)
            if(i == j)
                return true;
    }
    
    return false;
}