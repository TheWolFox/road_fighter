#include "MatrizLED.hpp"

MatrizLED::MatrizLED():
  MD_MAX72XX(MD_MAX72XX::GENERIC_HW, P_DIN, P_CLK, P_CS, N_MODULOS)
{
  
}

MatrizLED::~MatrizLED()
{

}

void MatrizLED::Setup()
{
  begin(); //Inicializa
  clear(); //Limpa matriz
  control(MD_MAX72XX::INTENSITY, 0); //Define intensidade como 0 (Pode ser 1 e 2 mas fica muito forte)
}

void MatrizLED::led(int linha, int coluna, int ligado)
{
  if (linha >= 0 && linha < 16 && coluna >= 0 && coluna < 8)
  {
    if (ligado == 0)
      setPoint(coluna, linha, LOW);
    else
      setPoint(coluna, linha, HIGH);
  }
}
void MatrizLED::todosLeds(int ligado)
{
  for(int i = 0; i <= 15; i++) {
    for(int j = 0; j <= 7; j++) {
      led(i, j, ligado);
    }
  }
}

void MatrizLED::ledInimigo(Inimigo *pInimigo, int ligado)
{
  for(int i = 0; i < pInimigo->getComprimento(); i++)
    led(pInimigo->getY() + i, pInimigo->getX(), ligado); 
}

void MatrizLED::ledJogador(Jogador *pJogador, int ligado)
{
  led(15.0, pJogador->getX(), ligado);
}

void MatrizLED::ledPista(Pista *pPista, int ligado)
{
  for(int i = 0; i < 16; i++)
  {
    led(i, pPista->getXi(), ligado);
    led(i, pPista->getXf(), ligado);
  }
}
