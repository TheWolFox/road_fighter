#include "Joystick.hpp"

Joystick::Joystick() {
}

Joystick::~Joystick() {
}

void Joystick::Setup() {
  cout << "Joystick: Inicializou!" << endl;
}

int Joystick::eixoX() {
  char tecla;

  // Verifica entrada do teclado
  if(_kbhit()) {
    //Captura entrada
    tecla = _getch();
  }

  if(tecla == 'a' || tecla == 'A')
    return -1;
  else if(tecla == 'd' || tecla == 'D')
    return 1;
  else
    return 0;
}

int Joystick::eixoY() {
  char tecla;

  // Verifica entrada do teclado
  if(_kbhit()) {
    //Captura entrada
    tecla = _getch();
  }
  
  if(tecla == 'w' || tecla == 'W')
    return -1;
  else if(tecla == 's' || tecla == 'S')
    return 1;
  else
    return 0;
}

bool Joystick::cliqueZ() {
  char tecla;

  // Verifica entrada do teclado
  if(_kbhit()) {
    //Captura entrada
    tecla = _getch();
  }

  if(tecla == 'z' || tecla == 'Z')
    return true;
  else
    return false;
}
