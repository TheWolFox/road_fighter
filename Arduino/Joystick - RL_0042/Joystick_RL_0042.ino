/* 
Projeto Arduino - Como ligar um joystick no Arduino
----------------------------------------
--=<| www.ComoFazerAsCoisas.com.br |>=--
----------------------------------------
*/

#define ENTRADA_A_EIXO_X A0
#define ENTRADA_A_EIXO_Y A1
//#define ENTRADA_D_EIXO_Z 2
#define MS_ESPERA 100
 
void setup() {
  //Definindo as entradas
  pinMode(ENTRADA_A_EIXO_X, INPUT);
  pinMode(ENTRADA_A_EIXO_Y, INPUT);
  //pinMode(ENTRADA_D_EIXO_Z, INPUT);
 
  //Ativando o Serial Monitor que exibirá os valores lidos no Joystick
  Serial.begin(9600);
}
 
void loop() {
  //imprime direcao do eixoX
  if(analogRead(ENTRADA_A_EIXO_X) > 530)
  {
    Serial.print(" Direita");
    Serial.print("\n");
  }
  else if(analogRead(ENTRADA_A_EIXO_X) < 480)
  {
    Serial.print(" Esquerda");
    Serial.print("\n");
  } 
 
  //imprime direcao do eixoY 
  if(analogRead(ENTRADA_A_EIXO_Y) < 480)
  {
    Serial.print(" Cima");
    Serial.print("\n");
  }  
  else if(analogRead(ENTRADA_A_EIXO_Y) > 530)
  {
    Serial.print(" Baixo");
    Serial.print("\n");
  } 
 
  //imprime clique eixoZ
  /*
  if(digitalRead(ENTRADA_D_EIXO_Z) == HIGH)
  {
    Serial.print(" Clique");
    Serial.print("\n");
  }
  */
    
  //espera n milisegundos.
  delay(MS_ESPERA); 
}
