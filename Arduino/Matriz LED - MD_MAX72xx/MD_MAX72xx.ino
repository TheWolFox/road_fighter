#include <MD_MAX72xx.h>

#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW //Tipo do modulo

#define MAX_DEVICES 2  //Quantidade de modulos

#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

#define TEMPO 100

MD_MAX72XX matriz = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup()
{
  matriz.begin();
  matriz.clear();
}

void loop()
{
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
}
