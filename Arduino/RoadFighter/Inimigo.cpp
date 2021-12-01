#include "Inimigo.hpp"

Inimigo::Inimigo(float xi, int comprimento) :
    Veiculo(xi, -(comprimento + 1), comprimento),
    danoTempo(DANO_TEMPO * comprimento), 
    danoPonto(DANO_PONTUACAO * comprimento)
{

}

Inimigo::~Inimigo()
{

}

bool Inimigo::verificarColisao(Jogador *pJogador)
{
    // Verifica posicoes futuras
    bool colidiu = false;

    if((int) pJogador->getX() == (int) this->x ) 
    {
        for(int i = 0; i < this->comprimento && !colidiu; i++)
        {
            if( (int) this->y + i == 15) {
                pJogador->diminuirPontuacao(this->danoPonto);
                pJogador->diminuirTempoRestante(this->danoTempo);
                colidiu = true;
            }
        }
    }
    return colidiu;
}

void Inimigo::verificarColisao(Pista *pPista, float dt)
{
    int xFuturo = this->x + this->vx * dt;
    bool colidira = false;
  
    // Verifica inversao de velocidade do carrinho zigzag
    if(comprimento == 2) {
        if( xFuturo <= pPista->getXi() || xFuturo >= pPista->getXf() ) {
            this->vx = this->vx * (-1);
        }
    }
}
