#ifndef H_INIMIGO
#define H_INIMIGO

#include "Cabecalho.hpp"
#include "Jogador.hpp"
#include "Veiculo.hpp"

class Inimigo :
  public Veiculo
{
protected:
    float danoTempo; // Dano em segundos.
    float danoPonto; // Dano na pontuacao do jogador.

public:
    Inimigo(float xi = 3.0, int comprimento = 1);
    ~Inimigo();

    bool verificarColisao(Jogador *pJogador); // Colisao com o jogador depois de se movimentarem(Retorna true se colidir)
    void verificarColisao(Pista *pPista, float dt) override; // Colisão com a pista
};

#endif
