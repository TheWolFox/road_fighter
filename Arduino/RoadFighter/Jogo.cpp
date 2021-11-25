#include "Jogo.hpp"

Jogo::Jogo()
{
  dificuldade = 1;
  fimDaFase = false;
  vitoria = false;
  tempoDaFase = 0.0;
  dt = 0.0;
  pJogador = NULL;
  pPista = NULL;
  count = 0;
  spawn = 0.0;
}

Jogo::~Jogo()
{
  // Desaloca memoria
  desalocarElementos();
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

void Jogo::executar()
{
  // Variaveis para controle de clock
  float tAnterior, tAtual;

  rodarIntroJogo();
  selecionaDificuldade();
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
    if (tempoDaFase < 0.0)
    {
      vitoria = false;
      fimDaFase = true;
    }
    else if (pJogador->getY() >= pPista->getComprimento())
    {
      vitoria = true;
      fimDaFase = true;
    }
    else
      tAnterior = tAtual; // Reseta o tempo do tick
  }

  // Teste de vitoria
  if (vitoria)
    acoesVitoria();
  else
    acoesDerrota();

  // Desalocação de memoria
  desalocarElementos();

  //Espera dois segundos para Reiniciar o jogo
  delay(2000);
}

void Jogo::rodarIntroJogo()
{
  matrizLED.todosLeds(1);
  displayLCD.imprimeCentralizado("Road", 0);
  displayLCD.imprimeCentralizado("Fighter", 1);
  matrizLED.todosLeds(0);
  delay(1500);
}

void Jogo::selecionaDificuldade()
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
  vitoria = false;
  fimDaFase = false;
  pJogador->setPontuacao(0.0);

  // Definicao dos atributos da fase
  tempoDaFase = 30.0;
  pPista = new Pista(0, 7);

  qntdInimigos = QNTDINIMIGOS * dificuldade;
  spawn = TEMPO_SPAWN / dificuldade;

  if (dificuldade == 3)
    qntdInimigos = QNTDINIMIGOS * 2 + 2;

  // Inicializacao da pista
  inicializarPista();

  // Alocacao do jogador
  pJogador = new Jogador(0.0, 0.0, 0.0, 0.0);
  inicializarJogador();

  /* esta parte deve funcionar, se funcionar, dá pra colocar no atualizar */
  int i = 0;
  while (i < qntdInimigos) {
    int id = 1; //(int) random(1, 4);
    float px = (float) random(1, 7); // no código do Arduíno ele usa long
    float py = (float) random(0, 13);

    float vy = 0;
    float vx = 0;

    switch (id)
    {
      case 1:
        vy = V_CARRO_COMUM;
        vx = 0;
        break;
      case 2:
        vy = V_CARRO_ZIGZAG;
        vx = V_CAMINHAO;
        break;
      case 3:
        vy = V_CAMINHAO;
        vx = 0;
        break;
      default:
        break;
    }

    Inimigo *inim = new Inimigo(px, py, vx, vy, ATRASO * id, DANO * id, id);

    if (!colisaoInimigos(inim, i)) {
      inimigos.push_back(inim);
      i++;
    } else {
      delete inim;
    }
  }

}

bool Jogo::colisaoInimigos(Inimigo *pInimigo, int j) {

  for (int i = 0; i < inimigos.size(); i++) {
    if (pInimigo->colide(inimigos[i]) && i != j)
      return true;
  }

  return false;
}

void Jogo::capturarEntrada()
{
  // Seta velocidade X do Jogador
  switch (joystick.eixoX())
  {
    case -1:
      pJogador->setVX(-1.0 * VX_JOGADOR);
      break;
    case 1:
      pJogador->setVX( 1.0 * VX_JOGADOR);
      break;
    default:
      pJogador->setVX( 0.0 * VX_JOGADOR);
      break;
  }

  // Seta velocidade Y do Jogador
  switch (joystick.eixoY())
  {
    case -1:
      pJogador->setVY(1.0 * VY_JOGADOR);
      break;
    case 1:
      pJogador->setVY(3.0 * VY_JOGADOR);
      break;
    default:
      pJogador->setVY(2.0 * VY_JOGADOR);
      break;
  }
}

void Jogo::atualizar()
{
  // Atualiza tempos de acordo com o dt
  tempoDaFase -= dt;
  pJogador->somaPontuacao(dt * PONTO_POR_SEG * pJogador->getVY()); // Conforme a velocidade do Jogador

  // Apagar os leds de cada corpo
  matrizLED.led(15, pJogador->getX(), LOW);
  for (int i = 0; i < inimigos.size(); i++) {
    for (int j = inimigos[i]->getY(); j < inimigos[i]->getY() + inimigos[i]->getComprimento(); j++) {
      matrizLED.led(j, inimigos[i]->getX(), LOW);
    }
  }

  // Verifica colisão jogador com parede
  if ( pJogador->getX() + pJogador->getVX() * dt <= pPista->getXi() + 1  ||
       pJogador->getX() + pJogador->getVX() * dt >= pPista->getXf())
  {
    // Seta a velocidade em X do jogador como 0.0 Led/seg
    pJogador->setVX(0.0);

    // Colidiu com a parede se ferrou c;
    pJogador->somaPontuacao(-10.0);
    this->tempoDaFase -= ATRASO;
  }

  // Move o personagem
  pJogador->mover(pJogador->getVX() *  dt, pJogador->getVY() * dt);

  // Verifica colisão dos inimigos com a parede
  // Verifica colisão com os outros inimigos. Se colidir, seta velocidade vy como 0. se não, pode se mover.
  for (int i = 0; i < inimigos.size(); i++) {
    if (colisaoInimigos(inimigos[i], i)) {
      inimigos[i]->setVY(0.0);
      inimigos[i]->setVX(0.0);
    }
    // Seta velocidade de inimigos
    else {
      switch (inimigos[i]->getComprimento())
      {
        case 1:
          inimigos[i]->setVY(V_CARRO_COMUM * pJogador->getVY());
          inimigos[i]->setVX(0.0);
          break;
        case 2:
          inimigos[i]->setVY(V_CARRO_ZIGZAG * pJogador->getVY());
          inimigos[i]->setVX(V_CAMINHAO);
          break;
        case 3:
          inimigos[i]->setVY(V_CAMINHAO * pJogador->getVY());
          inimigos[i]->setVX(0.0);
          break;
        default:
          break;
      }
    }
    if (inimigos[i]->getX() + inimigos[i]->getVX() * dt <= pPista->getXi() + 1 ||
        inimigos[i]->getX() + inimigos[i]->getVX() * dt >= pPista->getXf())
    {
      // Carrinho zigzag muda direção em x apos colidir.
      if (inimigos[i]->getComprimento() == 2)
        inimigos[i]->setVX(inimigos[i]->getVX() * (-1));
      else inimigos[i]->setVX(0.0);
    }
    // Verifica colisão com o player
    if (pJogador->colide(inimigos[i]))
    {
      pJogador->somaPontuacao(-(inimigos[i]->getDanoPonto()));
      this->tempoDaFase -= inimigos[i]->getDanoTempo();
    }

    // Mover inimigos
    inimigos[i]->mover(inimigos[i]->getVX() *  dt, inimigos[i]->getVY() * dt);

    // Verifica se inimigo saiu da tela e deleta ele
    if (inimigos[i]->getY() > 15) {
      delete inimigos[i];
      inimigos[i] = NULL;
    }
  }

  /* Gerador de Inimigos */
  if (spawn <= 0){
    if (inimigos.size() < qntdInimigos){
      geradorInimigos();
      spawn = TEMPO_SPAWN/dificuldade;
    }
  } else spawn = spawn - dt;


  // Acender os leds de cada corpo
  matrizLED.led(15, pJogador->getX(), HIGH);
  for (int i = 0; i < inimigos.size(); i++) {
    if(inimigos[i] != NULL){
      for (int j = inimigos[i]->getY(); j < (inimigos[i]->getY()) + (inimigos[i]->getComprimento()); j++) {
        matrizLED.led(j, inimigos[i]->getX(), HIGH);
      }
    }
  }

  /* Remoção dos Inimigos do vetor */
  for (int i = 0; i < inimigos.size(); i++){
    if (inimigos[i] == NULL)
      inimigos.erase(inimigos.begin() + i);
  }

  /* Linha de Chegada */
  if ((pJogador->getY() + 15) >= pPista->getComprimento()){
    matrizLED.ledIntervalo(count, count, 1, 6, 1);
    count++;
  }
}

void Jogo::geradorInimigos(){

  int i = 0;
  int max = inimigos.size();
  float px, py, vy, vx;
  
  while (max < this->qntdInimigos && i < 1) {
    int id = 1; //(int) random(1, 4);
    px = (float) random(1, 7); // no código do Arduíno ele usa long
    py = -3.0;

    vy = 0;
    vx = 0;

    switch (id)
    {
      case 1:
        vy = V_CARRO_COMUM;
        vx = 0;
        break;
      case 2:
        vy = V_CARRO_ZIGZAG;
        vx = V_CAMINHAO;
        break;
      case 3:
        vy = V_CAMINHAO;
        vx = 0;
        break;
      default:
        break;
    }

    Inimigo *inim = new Inimigo(px, py, vx, vy, ATRASO * id, DANO * id, id);

    if (!colisaoInimigos(inim, -1)) {
      inimigos.push_back(inim);
      i++;
    } else {
      delete inim;
    }
    
  }

}

/* Renderiza o texto no Display LCD */
void Jogo::renderizar()
{
  displayLCD.imprimeStatusFase(pJogador->getPontuacao(), tempoDaFase, pJogador->getY() / pPista->getComprimento());
}

void Jogo::acoesVitoria()
{
  // Sequencia de ações que vão ocorrer com a vitória do jogador
  String pontos;
  pontos.concat(pJogador->getPontuacao());
  displayLCD.imprimeCentralizado("Vitoria!", 0);
  displayLCD.imprimeCentralizado("Pontos: " + pontos, 1);
}

void Jogo::acoesDerrota()
{
  // Sequencia de ações que vão ocorrer com a derrota do jogador
  String pontos;
  pontos.concat(pJogador->getPontuacao());
  displayLCD.imprimeCentralizado("Derrota!", 0);
  displayLCD.imprimeCentralizado("Pontos: " + pontos, 1);
}

void Jogo::inicializarPista()
{
  if (pPista == NULL) {
    // Mensagem de erro
    displayLCD.imprimeCentralizado("Err pista=NULL", 0);
    displayLCD.imprimeCentralizado("inicializaFase()", 1);
    delay(5000);
  }
  else {
    // Acende a Pista
    matrizLED.ledIntervalo(0, 15, 0, pPista->getXi(), HIGH);
    matrizLED.ledIntervalo(0, 15, pPista->getXf(), 7, HIGH);
  }
}

void Jogo::inicializarJogador()
{
  if (pJogador == NULL) {
    // Mensagem de erro
    displayLCD.imprimeCentralizado("Err jogador=NULL", 0);
    displayLCD.imprimeCentralizado("inicializaFase()", 1);
    delay(5000);
  }
  else {
    // Acende o jogador
    pJogador->setX(3.0); // Coluna do meio da matriz
    pJogador->setY(0.0); // Linha final da matriz
    matrizLED.led((int) 15.0, (int)pJogador->getX(), HIGH);
  }
}

void Jogo::desalocarElementos()
{
  if (pJogador) {
    delete(pJogador);
    pJogador = NULL;
  }

  if (pPista) {
    delete(pPista);
    pPista = NULL;
  }

  // Desalocar os inimigos
  /* -- Tem que ser iterator?? -- */
  for ( int i = 0; i < inimigos.size(); i++ )
    desalocarInimigo(inimigos[i]);
  inimigos.clear();
}

void Jogo::desalocarInimigo(Inimigo *pInimigo)
{
  if (pInimigo)
  {
    delete(pInimigo);
    pInimigo = NULL;
  }
}
