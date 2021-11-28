#ifndef H_JOYSTICK
#define H_JOYSTICK

#include "Cabecalho.hpp"

#define P_EIXO_X A7 // 0 - 517 - 1023
#define P_EIXO_Y A6 // 0 - 495 - 1023
#define P_EIXO_Z 9 // true or false
#define EIXO_MAX 1023 //Valor maximo do analogico
#define ZONA_MORTA 100 //Valor onde não ocorrre acoes do joystick

class Joystick
{
  private:
    bool zClicado;
    bool zLiberado;

  public:
    Joystick();
    ~Joystick();

    void Setup();

    int eixoX();  // -1 -> Esquerda   0 -> Neutro   1 -> Direita
    int eixoY();  // -1 -> Baixo      0 -> Neutro   1 -> Cima
    bool cliqueZ();  //  true -> Ao soltar o botao
};

#endif
