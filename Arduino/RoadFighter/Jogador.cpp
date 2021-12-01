#include "Jogador.hpp"

Jogador::Jogador(float xi, float yi) :
  Veiculo(3.0, 0.0, 1)
{
  resetar();
}

Jogador::~Jogador()
{

}

void Jogador::resetar()
{
  this->setTempoRestante(30.0);
  this->setPontuacao(0.0);
  this->setX(3.0);
  this->setY(0.0);
  this->setVX(0.0);
  this->setVY(0.0);
}

void Jogador::verificarColisao(Pista *pPista, float dt) 
{
  int xFuturo = this->x + this->vx * dt;

  if ( xFuturo <= pPista->getXi() || xFuturo >= pPista->getXf() ) {
    this->diminuirPontuacao(DANO_PONTUACAO);
    this->diminuirTempoRestante(DANO_TEMPO);
    this->setVX(0.0);
  }
}

void Jogador::atualizar(float dt)
{
  this->diminuirTempoRestante(dt);
  this->somarPontuacao(dt * PONTO_POR_SEG * this->vy);
}

void Jogador::setPontuacao(float pontuacao)
{
  this->pontuacao = pontuacao;
  
  if(pontuacao > MAX_PONTUACAO)
    setPontuacao(MAX_PONTUACAO);
  else if(pontuacao < 0.0)
    setPontuacao(0.0);
}

void Jogador::somarPontuacao(float valor) 
{
  this->pontuacao += valor;
  if(this->pontuacao > MAX_PONTUACAO)
    setPontuacao(MAX_PONTUACAO); 
}

void Jogador::diminuirPontuacao(float valor)
{
  this->pontuacao -= valor;
  if(this->pontuacao < 0.0)
    setPontuacao(0.0);
}

void Jogador::setTempoRestante(float tempo)
{
  this->tempoRestante = tempo;
  if(this->tempoRestante < 0.0)
    this->tempoRestante = 0.0;
}

void Jogador::diminuirTempoRestante(float tempo)
{
  this->tempoRestante -= tempo;
  if(this->tempoRestante < 0.0)
    setTempoRestante(0.0);
}
