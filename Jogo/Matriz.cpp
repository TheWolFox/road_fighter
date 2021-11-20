#include "Matriz.h"

Matriz::Matriz(int dificuldade, int tam_pista  = 0, int posicao = 0)
{
    this->dificuldade = dificuldade;
    this->tam = tam_pista;
    this->posicao = 0;

    int i, j, gap = 0;

    for(i = 0; i < 16; i++){
        for(j = 0; j < 8; j++){
            this->m[i][j] = 0;
        }
    }

    /* Instala Bordas */
    if(dificuldade > 1) gap = 1;
    
    for(i = 0; i < 19; i++){
        this->m[i][0+gap] = 1;
        this->m[i][7-gap] = 1;
    }
    
}

Matriz::~Matriz(){}

/* Imprime a parte que da matriz que irá ser visível na Matriz LED. */
void Matriz::imprimeMatriz()
{
    int i, j;

    cout << "\n";
    for(i = 3; i < 16; i++){
        for(j = 0; j < 8; j++){
            cout << m[i][j] <<" ";
        }
        cout << "\n";
    }
}

/* Desloca todos os elementos da matriz em uma posição para baixo e zera a primeira linha da matriz */
void Matriz::atualizaMatriz(){

    int i, j;

    for(i = 1; i < 19; i++){
        for(j = 0; j <8; j++){
            this->setPosiMatriz(i, j, this->getPosiMatriz(i, j-1));
        }
    }

    for(i = 0; i<8; i++)
        this->setPosiMatriz(0, i, 0);
    
    posicao++;

}

/* Verifica se o jogador já percorreu toda a pista.*/
bool Matriz::fimDaMatriz(){
    return (posicao == tam - 1 + 8) ? false : true;
 }