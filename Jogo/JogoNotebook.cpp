#include "JogoNotebook.h"

JogoNotebook::JogoNotebook() {
    setup();
}

JogoNotebook::~JogoNotebook() {

    delete jogador;
    delete m;
}

void JogoNotebook::setup(){

    srand(time(NULL));
    /* Declarar jogador, matriz e inimigos iniciais */
    /* Qual será a primeira velocidade? */

    jogador = new Jogador(4, 0, 1, 1);
    m = new Matriz(1);

    int px, py;

    cout << jogador->getIdentificador();
    //posicionaVeiculo(jogador, 18, 5);
    //m->imprimeMatriz();

    /* Vou assumir que começamos por 5 kekeke*/
    /* int i =0;
    while (i < 5){
        px = rand()%16;
        py = rand()%8;
        Inimigo *x = geradorInimigo();
        if(varrerColuna(px, py, x->getComprimento())){
            posicionaVeiculo(x, px, py);
            i++;
        } 
    } */

}

/* Posiciona o veículo na matriz. */
void JogoNotebook::posicionaVeiculo(Veiculo* v, int x, int y){
    
    int i,j, c = v->getComprimento();
    for(i = y, j = 0; j < c; j++, i--){
        m->setPosiMatriz(x, i, v->getIdentificador());
    }
}

bool JogoNotebook::varrerColuna(int x, int y, int comprimento){

    int i = y;
    if(y - comprimento < 0) return false;
    while(i >= y - comprimento){
        if(m->getPosiMatriz(x, i) != 0) return false;
        i--;
    }

    return true;
}

/* Verifica tempo, pontuação e posição do jogador para ver se é possível encerrar o jogo */
bool JogoNotebook::encerrarPartida(){
    return (tempo <= 0 || m->fimDaMatriz() || jogador->getPontuacao() <=0 ) ? true : false ;
    
}