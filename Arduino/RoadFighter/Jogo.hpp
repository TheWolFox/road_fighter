#ifndef H_JOGO
#define H_JOGO

#include "Cabecalho.hpp"
#include "DisplayLCD.hpp"
#include "Joystick.hpp"
#include "MatrizLED.hpp"
#include "Jogador.hpp"
#include "Pista.hpp"
#include "Inimigo.hpp"

// LEDS
#define P_LED_G 8
#define P_LED_Y 7
#define P_LED_R 6

class Jogo
{
  private:
    int dificuldade; // Variavel de contole da dificuldade do jogo
    bool fimDaFase; // Variável de controle do loop da fase
    bool vitoria; // Variável de controle da vitória do jogador
    float dt; // Tempo de tick do loop do jogo
    int qntMaxInimigos; // Variável de controle de inimigos
    float vxInimigos; // Variável de controle da velocidade em X dos inimigos
    float vyInimigos; // Veriável de controle da velocidade em Y dos inimigos
    float tempoDeSpawn; // Controle de tempo de spawn de inimigos
    float tempoPadraoSpawn; // Variável com o tempo de spawn padrão

    DisplayLCD displayLCD;
    Joystick joystick;
    MatrizLED matrizLED;

    Jogador jogador;
    Pista pista;
    arx::vector<Inimigo> inimigos;// Vetor de inimigos

  public:
    Jogo();
    ~Jogo();

    void Setup(); // Setup do Hardware
    void resetar(); // Reseta variaveis do jogo
    void executar(); // Execução do jogo (Não é o loop da fase!)
    void rodarIntroJogo(); // Executa intro do jogo
    void selecionarDificuldade(); // Jogador seleciona a dificultade do jogo
    void inicializarFase(); // Inicializa elementos
    void capturarEntrada(); // Captura entrada do joystick e altera velocidade do jogador
    void atualizar(); // Atualiza os elementos do jogo
    void gerarInimigo(); // Cria um inimigo no jogo
    void renderizar(); // Renderiza no Display e Matriz
    void acoesVitoria(); // Acoes quando o jogador Vencer
    void acoesDerrota(); // Acoes quadno o jogador Perder

};

#endif
