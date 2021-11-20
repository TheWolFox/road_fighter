#include "Jogo.hpp"

Jogo jogo;

void setup() {
  //Temporario para testes
  Serial.begin(9600);
  jogo.Setup();
}

void loop() {
  jogo.executar();
}
