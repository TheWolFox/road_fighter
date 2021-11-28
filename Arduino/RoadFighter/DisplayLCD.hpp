#ifndef H_DISPLAY_LCD
#define H_DISPLAY_LCD

#include "Cabecalho.hpp"
#include <LiquidCrystal_I2C.h>

#define DISP_LINHAS 2
#define DISP_COLUNAS 16
#define DISP_ENDERECO 0x27 //Endereço do display para o módulo I2C
// P_SDA (SDA - UNO R3 - Perto das portas digitais) - (A4 - Nano)
// P_SCL (SCL - UNO R3 - Perto das portas digitais) - (A5 - Nano)

class DisplayLCD:
  public LiquidCrystal_I2C
{
  public:
    DisplayLCD();
    ~DisplayLCD();

    void Setup();
    void imprimeCentralizado(String texto, int linha); // Linha 0 ou 1
    void imprimeStatusFase(int pontos, int segundos, float progressoCorrida); // Pontos 0 - 999, tempo 0 à 999 s., progressoCorrida 0.0 - 1.0
};

#endif
