#include "Jogo.hpp"

Jogo::Jogo()
{
  resetar();
}

Jogo::~Jogo()
{
  inimigos.clear();
}

void Jogo::Setup()
{
  displayLCD.Setup();
  joystick.Setup();
  matrizLED.Setup();
  pinMode(P_LED_G, OUTPUT);
  pinMode(P_LED_Y, OUTPUT);
  pinMode(P_LED_R, OUTPUT);
}

void Jogo::resetar()
{
  jogador.resetar();
  inimigos.clear();
  fimDaFase = false;
  vitoria = false;
}

void Jogo::executar()
{
  // Variaveis para controle de clock
  float tAnterior, tAtual;

  rodarIntroJogo();
  resetar();
  selecionarDificuldade();
  inicializarFase();

  // Inicialização do controle do tempo
  dt = 0.0;
  tAnterior = (float) millis() / 1000;

  // Loop do jogo
  while (!fimDaFase)
  {
    // Atualiza a variacao do tempo
    tAtual = (float) millis() / 1000;
    dt = tAtual - tAnterior ;

    // Sequencia de jogo
    capturarEntrada();
    atualizar();
    renderizar();

    // Verifica fim de jogo
    if ( jogador.getTempoRestante() == 0.0)
    {
      vitoria = false;
      fimDaFase = true;
    }
    else if (jogador.getY() >= pista.getComprimento())
    {
      vitoria = true;
      fimDaFase = true;
    }
    else
      tAnterior = tAtual; // Reseta o tempo do tick
  }

  // Apaga matriz
  matrizLED.todosLeds(LOW);

  // Teste de vitoria
  if (vitoria)
    acoesVitoria();
  else
    acoesDerrota();

  //Espera dois segundos para Reiniciar o jogo
  delay(2000);
}

void Jogo::rodarIntroJogo()
{
  displayLCD.imprimeCentralizado("Road", 0);
  displayLCD.imprimeCentralizado("Fighter", 1);
  delay(1500);
}

void Jogo::selecionarDificuldade()
{
  displayLCD.imprimeCentralizado("Selecione a", 0);
  displayLCD.imprimeCentralizado("dificuldade", 1);
  delay(2000);

  //Inicia com dificuldade facil
  dificuldade = 1;
  digitalWrite(P_LED_G, HIGH);
  digitalWrite(P_LED_Y, LOW);
  digitalWrite(P_LED_R, LOW);

  displayLCD.imprimeCentralizado("Facil", 0); //linha 0 ou 1
  displayLCD.imprimeCentralizado("", 1); //linha 0 ou 1

  //Enquanto o jogador não clica com o Z
  while ( !joystick.cliqueZ() )
  {
    if ( joystick.eixoX() == -1 && dificuldade == 2)
    {
      digitalWrite(P_LED_G, HIGH);
      digitalWrite(P_LED_Y, LOW);
      digitalWrite(P_LED_R, LOW);

      displayLCD.imprimeCentralizado("Facil", 0);
      displayLCD.imprimeCentralizado("", 1);

      this->dificuldade = 1;
    }
    else if ( joystick.eixoX() == 1 && dificuldade == 1 || joystick.eixoX() == -1 && dificuldade == 3)
    {
      digitalWrite(P_LED_G, LOW);
      digitalWrite(P_LED_Y, HIGH);
      digitalWrite(P_LED_R, LOW);

      displayLCD.imprimeCentralizado("Medio", 0);
      displayLCD.imprimeCentralizado("", 1);

      this->dificuldade = 2;
    }
    else if ( joystick.eixoX() == 1 && dificuldade == 2)
    {
      digitalWrite(P_LED_G, LOW);
      digitalWrite(P_LED_Y, LOW);
      digitalWrite(P_LED_R, HIGH);

      displayLCD.imprimeCentralizado("Dificil", 0);
      displayLCD.imprimeCentralizado("", 1);

      this->dificuldade = 3;
    }
    delay(200);
  }

  // Mostra informacao ao jogador
  displayLCD.imprimeCentralizado("Selecionado:", 0);
  if (dificuldade == 1)
    displayLCD.imprimeCentralizado("Facil", 1);
  else if (dificuldade == 2)
    displayLCD.imprimeCentralizado("Medio", 1);
  else
    displayLCD.imprimeCentralizado("Dificil", 1);
  delay(2000);
}

void Jogo::inicializarFase()
{
  // Inicializacao das variaveis de controle
  this->resetar();
  matrizLED.todosLeds(LOW);

  switch (dificuldade)
  {
    case 1:
      qntMaxInimigos = QNT_MAX_INIMIGOS * dificuldade;
      tempoPadraoSpawn = TEMPO_SPAWN / dificuldade;
      vxInimigos = 1.0; // VX_INIMIGO;
      vyInimigos = 1.0; // VY_INIMIGO;
      pista.setXi(0);
      pista.setXf(7);
      jogador.setTempoRestante(30.0);
      break;

    case 2:
      qntMaxInimigos = QNT_MAX_INIMIGOS * dificuldade;
      tempoPadraoSpawn = TEMPO_SPAWN / dificuldade;
      vxInimigos = 1.0; //VX_INIMIGO;
      vyInimigos = 2.0; //VY_INIMIGO + 2;
      pista.setXi(1);
      pista.setXf(7);
      jogador.setTempoRestante(15.0);
      break;

    default:
      qntMaxInimigos = QNT_MAX_INIMIGOS * dificuldade;
      tempoPadraoSpawn = TEMPO_SPAWN / dificuldade;
      vxInimigos = 1.5; //VX_INIMIGO;
      vyInimigos = 2.5; //VY_INIMIGO;
      pista.setXi(1);
      pista.setXf(6);
      jogador.setTempoRestante(20.0);
      break;
  }
  tempoDeSpawn = tempoPadraoSpawn;

  // Cria o primeiro inimigos
  gerarInimigo();

  // Acende os leds iniciais
  matrizLED.ledPista(&pista, HIGH);
  matrizLED.ledJogador(&jogador, HIGH);
  matrizLED.ledInimigo(&inimigos[0], HIGH);
}

void Jogo::capturarEntrada()
{
  // Seta velocidade X do Jogador
  switch (joystick.eixoX())
  {
    case -1:
      jogador.setVX(-1.0 * VX_JOGADOR);
      break;
    case 1:
      jogador.setVX( 1.0 * VX_JOGADOR);
      break;
    default:
      jogador.setVX( 0.0 * VX_JOGADOR);
      break;
  }

  // Seta velocidade Y do Jogador
  switch (joystick.eixoY())
  {
    case -1:
      jogador.setVY(1.0 * VY_JOGADOR);
      break;
    case 1:
      jogador.setVY(3.0 * VY_JOGADOR);
      break;
    default:
      jogador.setVY(2.0 * VY_JOGADOR);
      break;
  }

  // Seta velocidade dos inimigos
  for (int i = 0; i < inimigos.size(); i++)
  {
    // Seta VY
    inimigos[i].setVY(jogador.getVY() * vyInimigos);

    // Seta VX se for zig zag
    if (inimigos[i].getComprimento() == 2) {
      if (inimigos[i].getVX() < 0.0) {
        inimigos[i].setVX(-vxInimigos);
      }
      else {
        inimigos[i].setVX(vxInimigos);
      }
    }
    else {
      inimigos[i].setVX(0.0);
    }
  }
}

void Jogo::atualizar()
{
  // Verifica se ocorrera colisão jogador com parede
  jogador.verificarColisao(&pista, dt);

  // Verifica se ocorrea colisao dos inimigos com a parede
  for (int i = 0; i < inimigos.size(); i++) {
    inimigos[i].verificarColisao(&pista, dt);
  }

  // Apaga o led do jogador, move e acende novamente
  matrizLED.ledJogador(&jogador, LOW);
  jogador.mover(dt);

  // Apaga os leds, move e acende novamente
  for (int i = 0; i < inimigos.size(); i++) {
    matrizLED.ledInimigo(&inimigos[i], LOW);
    inimigos[i].mover(dt);

    // Verifica se o inimigo saiu da tela ou colidiu com o jogador
    if (inimigos[i].getY() > 15.0 || inimigos[i].verificarColisao(&jogador)) {
      inimigos.erase(inimigos.begin() + i);
      i--;
    }
    else {
      matrizLED.ledInimigo(&inimigos[i], HIGH);
    }
  }
  matrizLED.ledJogador(&jogador, HIGH);

  // Atualiza o Jogador
  jogador.atualizar(dt);

  // Verifica se insere novo inimigo
  if (tempoDeSpawn < 0.0 && inimigos.size() < qntMaxInimigos) {
    gerarInimigo();
    tempoDeSpawn = tempoPadraoSpawn;
  }
  else {
    tempoDeSpawn -= dt;
  }
}

void Jogo::gerarInimigo()
{
  int xi = random(pista.getXi() + 1, pista.getXf());
  int comprimento = random(1, 4);
  inimigos.push_back(Inimigo(xi, comprimento));
}

void Jogo::renderizar()
{
  displayLCD.imprimeStatusFase(jogador.getPontuacao(), jogador.getTempoRestante(), jogador.getY() / pista.getComprimento());
}

void Jogo::acoesVitoria()
{
  // Sequencia de ações que vão ocorrer com a vitória do jogador
  String pontos;
  pontos.concat(jogador.getPontuacao());
  displayLCD.imprimeCentralizado("Vitoria!", 0);
  displayLCD.imprimeCentralizado("Pontos: " + pontos, 1);
}

void Jogo::acoesDerrota()
{
  // Sequencia de ações que vão ocorrer com a derrota do jogador
  String pontos;
  pontos.concat(jogador.getPontuacao());
  displayLCD.imprimeCentralizado("Derrota!", 0);
  displayLCD.imprimeCentralizado("Pontos: " + pontos, 1);
}
