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
  
  public:
    Jogador(float xi, float yi, float vxi, float vyi);
    ~Jogador();

    void setPontuacao(float pontuacao);
    void somaPontuacao(float valor); // Pode somar valores negativos!
    float getPontuacao() {return this->pontuacao;}
};

#endif
