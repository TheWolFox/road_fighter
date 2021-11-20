#ifndef JOGADOR_H
#define JOGADOR_H

#define VMAX 5
#define VCONST 3

#include "Veiculo.h"

/*
    Veículo do jogador principal.
*/
class Jogador: public Veiculo {
    private:
        char tecla;
        int pontuacao;

    public:
        Jogador(int xi, int yi, int vxi, int comprimento, int id); 
        ~Jogador();

        void mover(char tecla); /* a w s d, 'w' e 's' mudam velocidade */ 
        void mover(int x, int y); /* Recebe o retorno do Joystick */

        int colide(Matriz* M, float tempo); /* Retorna o dano se colidir, se não, retorna 0, se colidir faz o veículo explodir */
        void atualizaPontuacao(int dano) {this->pontuacao = this->pontuacao -dano;} /* Recebe o retorno do colide */
        int getPontuacao(){return this->pontuacao;}
};

#endif
