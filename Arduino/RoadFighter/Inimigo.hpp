#ifndef H_INIMIGO
#define H_INIMIGO

#include "Cabecalho.hpp"
#include "Veiculo.hpp"

class Inimigo :
  public Veiculo
{
protected:
    float danoTempo; // Dano em segundos.
    float danoPonto; // Dano na pontuacao do jogador.
    int id; // 1: CarroComum, 2: CarroZigZag, 3: Caminhao

public:
    Inimigo(float xi, float yi, float vxi, float vyi, float danoTempo, float danoPonto, int comprimento);
    ~Inimigo();

    float getDanoTempo() { return this->danoTempo; }
    float getDanoPonto() { return this->danoPonto; }
    int getID() { return this->id; }

};

#endif
