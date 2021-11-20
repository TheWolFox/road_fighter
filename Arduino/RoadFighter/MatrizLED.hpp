#ifndef H_MATRIZ_LED
#define H_MATRIZ_LED

#include "Cabecalho.hpp"
#include <MD_MAX72xx.h>

#define P_CLK 13
#define P_DATA 11
#define P_CS 10
#define N_MODULOS 2

class MatrizLED :
  public MD_MAX72XX
{
  public:
    MatrizLED();
    ~MatrizLED();

    void Setup();

    void led(int linha, int coluna, int ligado); //0 -> Desligado, != 0 -> Ligado
    void todosLeds(int ligado); //0-> apagar todos, != -> Ligar todos
    void ledIntervalo(int li, int lf, int ci, int cf, int ligado); // li: Linha inicial, lf: Linha final, ci: Coluna inicial, cf: Coluna final, ligado: 0 -> Desligado ou != 0 -> Ligado.
};

#endif
