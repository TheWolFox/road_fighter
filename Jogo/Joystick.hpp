#ifndef H_JOYSTICK
#define H_JOYSTICK

#include "Cabecalho.hpp"

class Joystick {
  public:
    Joystick();
    ~Joystick();

    void Setup();

    int eixoX();  // -1 -> Esquerda   0 -> Neutro   1 -> Direita
    int eixoY();  // -1 -> Baixo      0 -> Neutro   1 -> Cima
    bool cliqueZ();  //  true -> Ao CLICAR NO BOTAO Z
};

#endif
