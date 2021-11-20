#include "Jogador.hpp"

Jogador::Jogador(float xi, float yi, float vxi, float vyi) :
  Veiculo(xi, yi, vxi, vyi, 1)
{
  this->setPontuacao(0.0);
}

Jogador::~Jogador()
{

}

void Jogador::setPontuacao(float pontuacao)
{
  this->pontuacao = pontuacao;
  
  if(pontuacao > MAX_PONTUACAO)
    setPontuacao(MAX_PONTUACAO);
  else if(pontuacao < 0.0)
    setPontuacao(0.0);
}

void Jogador::somaPontuacao(float valor) 
{
  this->pontuacao += valor;
  
  if(this->pontuacao > MAX_PONTUACAO)
    setPontuacao(MAX_PONTUACAO);
  else if(this->pontuacao < 0.0)
    setPontuacao(0.0);
}
