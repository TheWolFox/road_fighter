#ifndef H_JOGO
#define H_JOGO

#include <stdio.h>
#include "DisplayLCD.hpp"
#include "MatrizLED.hpp"

#define FACIL 'f'
#define MEDIO 'm'
#define DIFICIL 'd'

class Jogo 
{
private:
    //DisplayLCD displayLCD;
    //MatrizLED matrizLED;

    char dificuldade; // Variavel de controle para criação dos elementos
    bool fimDoJogo; //Variavel de controle do loop do jogo
    bool vitoria; //Variavel de controle da vitoria do jogador

public:
    Jogo();
    ~Jogo();

    void executar(); //Execução do jogo
    void capturaEntrada(); //Captura entrada do joystick e altera velocidade do jogador
    void atualizar(); //Atualiza os elementos do jogo
    void renderizar(); //Renderiza no Display e Matriz
    void acoesVitoria(); //Acoes quando o jogador Vencer
    void acoesDerrota(); //Acoes quadno o jogador Perder
};

#endif