#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdio.h>
#include <iostream>
using namespace std;


class Matriz 
{
protected:
    int m[19][8]; /* Para evitar carros aparecerem brotados */
    int dificuldade;
    int tam;
    int posicao; /* A matriz vai ter no máximo tam - 1 + (metade da matriz) atualizações, como o jogador se mantem sempre na mesma posicao, não há como identificar quando ele chegou na linha de chegada... */

public:
    Matriz(int dificuldade, int tam_pista = 0, int posicao = 0);
    ~Matriz();
    
    void imprimeMatriz(); /* Imprimir a partir da linha 3 para baixo */
    void atualizar(); /* Pega a posição do Jogador e reimprime a matriz */
    
    void setPosiMatriz(int x, int y, int valor) {this->m[x][y] = valor;} /* Modifica o valor em uma dada posição na matriz*/ 
    int getPosiMatriz(int x, int y) {return this->m[x][y];} /* Retorna o valor em uma dada posição na matriz*/ 

    void atualizaMatriz();
    int getPosicao(){ return posicao; }
    bool fimDaMatriz();
};

#endif