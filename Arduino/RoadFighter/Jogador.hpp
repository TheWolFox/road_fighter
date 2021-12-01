#ifndef H_JOGADOR
#define H_JOGADOR

#include "Cabecalho.hpp"
#include "Veiculo.hpp"

#define MAX_PONTUACAO 999.9 // Pontuacao maxima

class Jogador :
  public Veiculo
{
  private:
    float pontuacao; // 0.0 - 999.9
    float tempoRestante; // minimo 0.0
  
  public:
    Jogador(float xi = 3.0, float yi = 15.0);
    ~Jogador();

    void resetar(); // Reseta o player com os valores padrões
    void verificarColisao(Pista *pPista, float dt) override; // Colisão com a pista
    void atualizar(float dt); // Atualiza variaveis conforme o dt
    
    void setPontuacao(float pontuacao); // Seta pontuacao do jogador
    float getPontuacao() { return this->pontuacao; } // Retorna a pontuacao do Jogador
    void somarPontuacao(float valor); // Pode somar valores negativos!
    void diminuirPontuacao(float valor); // Diminui pontuacao
    
    void setTempoRestante(float tempo); // Seta o tempo restante em segundos
    float getTempoRestante() { return tempoRestante; } // Retorna o tempo restante
    void diminuirTempoRestante(float tempo); // Diminui o tempo do jogador
};

#endif
