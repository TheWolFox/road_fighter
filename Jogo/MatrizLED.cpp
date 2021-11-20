#include "MatrizLED.hpp"

MatrizLED::MatrizLED() {
  //Constantes estão no arquivo Cabecalho.hpp
  //Inicializa com 0 a matriz
  ledIntervalo(0, 15, 0, 7, 0);
}

MatrizLED::~MatrizLED() {
}

void MatrizLED::Setup() {
  cout << "Matriz: Inicializou, Desligou leds, Setou intensidade" << endl;
}

void MatrizLED::led(int linha, int coluna, int ligado) {
  if (linha >= 0 && linha < 16 && coluna >= 0 && coluna < 8)
    matriz[linha][coluna] = ligado;
}

void MatrizLED::todosLeds(int ligado) {
  for (int i = 0; i < 16; i++)
    for (int j = 0; j < 8; j++)
      led(i, j, ligado);
}

void MatrizLED::ledIntervalo(int li, int lf, int ci, int cf, int ligado) {
  for (int i = li; i <= lf; i++)
    for (int j = ci; j <= cf; j++)
      led(i, j, ligado);
}

void MatrizLED::renderizar() {
  for(int i = 0; i < 16; i++) {
    for(int j = 0; j < 8; j++)
      cout << matriz[i][j] << " ";
    cout << endl;
  }
}