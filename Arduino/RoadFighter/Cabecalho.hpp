#ifndef CABECALHO
#define CABECALHO

// Para operações nas classes
#include "Arduino.h"
#include <ArxContainer.h>

// Parametos default para o jogo
#define PONTO_POR_SEG 4.5 
#define PROGRESSO_POR_SEG 0.05  // 5% por seg.
#define TEMPO_SPAWN 2.5 // seg.

#define V_CARRO_COMUM 1.0 // Led por seg.
#define V_CARRO_ZIGZAG 1.5 // Led por seg.
#define V_CAMINHAO  0.5 // Led por seg.

#define VX_JOGADOR 2.0 // Led por seg.
#define VY_JOGADOR 1.5 // Led por seg.

#define QNTDINIMIGOS 5
#define DANO 10.0
#define ATRASO 1.0

#endif
