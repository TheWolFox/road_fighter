#include "Jogo.hpp"

Jogo::Jogo() {
}

Jogo::~Jogo() {
}

void Jogo::executar() {
    //Inicializa os dispositivos
    displayLCD.reset(); //Reseta o display LCD
    matrizLED.reset(); //Reseta a matriz de LED

    //selecao de dificuldade
        //Acende led Verde
        //Inicia info no display como facil
        //Se o usuario meche no eixo X, altera a dificuldade e cor do led
        //Altera informacao no display
        //Espera o usuario clicar com Z do Joystick

    //Inicializa elementos de acordo com a dificuldade (atributo do jogo)
        //Acende led
        //Determina tamanho da pista
        //Posiciona jogador
    
    printf("Executou o jogo!\n"); //TEMPORARIO

    //loop do jogo
    fimDoJogo = true; //NECESSARIO ALTERAR PARA FALSE PARA QUE O JOGO ENTRE EM LOOP
    vitoria = true;
    do {
        capturaEntrada();
        atualizar();
        renderizar();
    } while(!fimDoJogo);
    
    //Executa acao de vitoria ou derrota
    if(vitoria)
        acoesVitoria();
    else
        acoesDerrota();
}

void Jogo::capturaEntrada() {
    //Altera velocidade do jogador de acordo com a entrada do joystick
    printf("Capturou\n"); //TEMPORARIO
}

void Jogo::atualizar() {
    //Movimenta
    //Verifica colisao
    //Remove elemento caso tenha colidido
    //Insere novo elemento se houver espaço no cenario
    
    //NAO ESQUECER DE ALTERAR AS VARIAVEIS FIM DE JOGO E VITORIA CASO OCORRA O FIM DO JOGO OU
    //NAO IRA SAIR DO LOOP!
    printf("Atualizou\n"); //TEMPORARIO
}

void Jogo::renderizar() {
    displayLCD.renderizar();
    matrizLED.renderizar();
}

void Jogo::acoesVitoria() {
    //LCD mostra pontos
    printf("Jogador Venceu\n"); //TEMPORARIO
}

/*teeeeeeeeeeeeeeeeeeste*/

void Jogo::acoesDerrota() {
    //LCD Mostra Game Over
    printf("Jogador Perdeu\n"); //TEMPORARIO
}
