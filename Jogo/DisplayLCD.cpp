#include "DisplayLCD.hpp"

DisplayLCD::DisplayLCD() {
}

DisplayLCD::~DisplayLCD() {
}

void DisplayLCD::Setup() {
  cout << "Display LCD: Inicializou, Ligou luz do fundo, Limpou a tela!" << endl;
}

void DisplayLCD::imprimeCentralizado(string texto, int linha) {
  cout << "Display LCD: \" " << texto << " \" na linha " << linha << endl;
}

void DisplayLCD::imprimeStatusFase(int pontos, int segundos, float progressoCorrida) {
  int progressoCheio;

  //Imprime pontuacao
  cout << "Display: " << endl;
  cout << "Pts: ";
  
  if (pontos > 999)
    cout << 999;
  else
    cout << pontos;

  cout << "\t";

  //Imprime tempo
  cout << "Tmp: ";

  if (segundos > 999)
    cout << 999;
  else
    cout << segundos;

  cout << " s.\t" << endl;

  //Imprime progresso
  progressoCheio = 16 * progressoCorrida;

  if (progressoCheio > 16)
    progressoCheio = 16;

  cout << "Progresso: " << progressoCorrida * 100 << "% :"; 

  for (int i = 0; i < progressoCheio; i++)
    cout << "|"; 
  for (int i = progressoCheio; i < 16; i++)
    cout << " ";

  cout << endl;
}
