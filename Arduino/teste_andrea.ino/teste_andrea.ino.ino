#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW //Tipo do modulo

#define MAX_DEVICES 2  //Quantidade de modulos

#define ROWS_SIZE 8
#define COLUMNS_SIZE 16

// Pinout
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

// Game global variables
#define WIDE 1
#define NARROW 2


MD_MAX72XX LEDmatrix = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setWalls(int spaces){

  /* Even though it seems to be columns written in the matrix, they're actually rows. */
  matrix.setRow(spaces - 1, HIGH);
  matrix.setRow(COLUMNS_SIZE - spaces - 1, HIGH);
  
}

void setup()
{
  matriz.begin();
  matriz.clear();
}

void loop()
{

  setWalls(WIDE);
  /*
  for (uint8_t i=0; i < 8; i++)
  {
    for (uint8_t j=0; j < 16; j++)
    {
      matriz.setPoint(i, j, HIGH);
      delay(TEMPO);
    }
    delay(TEMPO);
  }

  delay(500);

  for (uint8_t i=0; i < 8; i++)
  {
    for (uint8_t j=0; j < 16; j++)
    {
      matriz.setPoint(i, j, LOW);
      delay(TEMPO);
    }
    delay(TEMPO);
  } 
  
  delay(1000);

  */
}
