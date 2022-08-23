#include <Arduino.h>
#include <IRremote.h>
#include "rotina.h"

int rele = 4;

void setup()
{
  iniciarreceptor();
  pinMode(rele, OUTPUT);
  Serial.begin(9600);
  pinMode(rele, OUTPUT);
}

void loop()
{
  rotina(rele);
  delay(100);
}
