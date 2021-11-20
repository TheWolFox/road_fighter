#ifndef CABECALHO
#define CABECALHO

/* // Removido apenas para teste direto no terminal!! ==========
// Para operações nas classes
#include "Arduino.h"
*/

// TEMPORARIO PARA TESTES NO TERMINAL ==========
#include <iostream>
#include <conio.h>
#include "string.h"
#include "time.h"
using namespace std;
// =============================================

// Joystick
#define PIN_A_EIXO_X A0 // 0 - 517 - 1023
#define PIN_A_EIXO_Y A1 // 0 - 495 - 1023
#define PIN_D_EIXO_Z 7 // true or false
#define EIXO_MAX 1023 //Valor maximo do analogico
#define ZONA_MORTA 100 //Valor onde não ocorrre acoes do joystick

// Display
//#define QNT_LINHAS 2
//#define QNT_COLUNAS 16
#define ENDERECO_DISPLAY 0x27 //Endereço do display para o módulo I2C
// PIN_A_SDA A4
// PIN_A_SCL A5

// Matriz
#define PIN_A_CLK 13
#define PIN_A_DATA 11
#define PIN_A_CS 10

// LEDS
#define PIN_D_LED_G 3
#define PIN_D_LED_Y 4
#define PIN_D_LED_R 5

// Dados Jogo
#define PONTO_POR_SEG 4
#define PROGRESSO_POR_SEG 0.02
#define TEMPO_SPAWN 2 //2 seg

//VELOCIDADES
#define VELOCIDADE_PADRAO 3
#define VELOCIDADE_MIN 1
#define VELOCIDADE_MXM 5

#endif
