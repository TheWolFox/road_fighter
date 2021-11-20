#ifndef H_MATRIZ_LED
#define H_MATRIZ_LED

#include "Cabecalho.hpp"

class MatrizLED {
  // TEMPORARIO PARA TESTES NO TERMINAL ==========
  private:
    int matriz[16][8];
  // =============================================

  public:
    MatrizLED();
    ~MatrizLED();

    void Setup();

    void led(int linha, int coluna, int ligado); //0 -> Desligado, != 0 -> Ligado
    void todosLeds(int ligado); //0-> apagar todos, != -> Ligar todos
    void ledIntervalo(int li, int lf, int ci, int cf, int ligado); // li: Linha inicial, lf: Linha final, ci: Coluna inicial, cf: Coluna final, ligado: 0 -> Desligado ou != 0 -> Ligado.

    // TEMPORARIO PARA TESTES NO TERMINAL ==========
    void renderizar();
    // =============================================
};

#endif
