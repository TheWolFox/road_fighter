#include "MatrizLED.hpp"

MatrizLED::MatrizLED():
  MD_MAX72XX(MD_MAX72XX::GENERIC_HW, P_DATA, P_CLK, P_CS, N_MODULOS)
{
  //Constantes estão no arquivo Cabecalho.hpp
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
  for (int i = 0; i < 16; i++)
    for (int j = 0; j < 8; j++)
      led(i, j, ligado);
}

void MatrizLED::ledIntervalo(int li, int lf, int ci, int cf, int ligado)
{
  for (int i = li; i <= lf; i++)
    for (int j = ci; j <= cf; j++)
      led(i, j, ligado);
}
