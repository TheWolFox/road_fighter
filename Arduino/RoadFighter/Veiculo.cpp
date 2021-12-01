#include "Veiculo.hpp"

Veiculo::Veiculo(float xi, float yi, int comprimento) :
  x(xi), y(yi), vx(0.0), vy(0.0), comprimento(comprimento)
{

}

Veiculo::~Veiculo()
{

}

void Veiculo::mover(float dt)
{
  this->x += this->vx * dt;
  this->y += this->vy * dt;
}