#include <Arduino.h>
#include <IRremote.h>
#include "rotina.h"


#define botao1 16753245
#define botao2 16736925
/* Valores HEX convertidos para decimal e
definidos como bot�es do controle  */

int const PINO_RECEPTOR = 2;
IRrecv receptor(PINO_RECEPTOR);
decode_results valorSaida;

void iniciarreceptor()
{
	receptor.enableIRIn();
}  

  
void rotina(int rele)
{
   //Inicia o receptor
  if (receptor.decode(&valorSaida)) 
  {
    receptor.resume(); // Recebe o pr�ximo valor
    if (valorSaida.value == botao1)
    {
      digitalWrite(rele, HIGH);
    }
    else if (valorSaida.value == botao2) 
    {
      digitalWrite(rele, LOW);
    }
    Serial.println(valorSaida.value);
    /* Linha para verificar o HEX do bot�o
    que esta sendo apertado caso necess�rio
    trocar valor HEX das condicionais*/
  }
}