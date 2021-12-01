#ifndef H_MATRIZ_LED
#define H_MATRIZ_LED

#include "Cabecalho.hpp"
#include <MD_MAX72xx.h>
#include "Inimigo.hpp"
#include "Jogador.hpp"
#include "Pista.hpp"

#define P_CLK 10
#define P_CS 11
#define P_DIN 12
#define N_MODULOS 2

class MatrizLED :
  public MD_MAX72XX
{
  public:
    MatrizLED();
    ~MatrizLED();

    void Setup();

    void led(int linha, int coluna, int ligado); //0 -> Desligado, != 0 -> Ligado
    void todosLeds(int ligado);
    void ledInimigo(Inimigo *pInimigo, int ligado);
    void ledJogador(Jogador *pJogador, int ligado);
    void ledPista(Pista *pPista, int ligado);
};

#endif
