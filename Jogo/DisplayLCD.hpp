#ifndef H_DISPLAY_LCD
#define H_DISPLAY_LCD

#include "Cabecalho.hpp"

class DisplayLCD {
  public:
    DisplayLCD();
    ~DisplayLCD();

    void Setup();
    void imprimeCentralizado(string texto, int linha); // Linha 0 ou 1
    void imprimeStatusFase(int pontos, int segundos, float progressoCorrida); // Pontos 0 - 999, tempo 0 à 999 s., progressoCorrida 0.0 - 1.0
};

#endif
