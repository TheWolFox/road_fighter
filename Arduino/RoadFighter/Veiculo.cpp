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