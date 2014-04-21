/*
Lichtschakelsysteem LdV46
Schakelaars op huiscode 18 (01001)
Afstandsbediening op 9 (10010)
*/

#include "RemoteTransmitter.h"
#include "RemoteReceiver.h"
#include <avr/wdt.h>
ActionTransmitter actionTransmitter(7);
#include "variabelen.h"
#include "remote.h"

void setup()
{
  wdt_reset();
  wdt_enable(WDTO_8S); 
  pinMode(3, OUTPUT);pinMode(5, OUTPUT);pinMode(6, OUTPUT); //(R/G/B)
  pinMode(7, OUTPUT); //433Mhz zender
  pinMode(2, INPUT); //433Mhz ontvanger
  pinMode(4, OUTPUT); //SS SDkaart
  pinMode(10, OUTPUT); //SS Ethernet
  LED('B');
//Lampinit();
//  RemoteReceiver::init(0, 1, translateCode);
}

void loop()
{
  LED('G');
  wdt_reset();
  Lamptest();
}

void LED(char kleur){
  switch (kleur){
    case 'R': //Rood (netwerkfout)
      analogWrite(3, 60); //R
      analogWrite(5, 0); //G
      analogWrite(6, 0); //B
      break;
    case 'G': //Groen (alles OK)
      analogWrite(3, 0); //R
      analogWrite(5, 60); //G
      analogWrite(6, 0); //B
      break;
    case 'B': //Blauw (lamp aan)
      analogWrite(3, 0); //R
      analogWrite(5, 0); //G
      analogWrite(6, 60); //B
      break;
    case 'Y': //Geel (RTC of NTP fout)
      analogWrite(3, 40); //R
      analogWrite(5, 20); //G
      analogWrite(6, 0); //B
      break;
    case 'C': //Cyaan (EEPROM fout)
      analogWrite(3, 0); //R
      analogWrite(5, 30); //G
      analogWrite(6, 30); //B
      break;
    case 'M': //Magenta (SD fout)
      analogWrite(3, 30); //R
      analogWrite(5, 0); //G
      analogWrite(6, 30); //B
      break;
    case 'W': //Wit (netwerk in gebruik)
      analogWrite(3, 20); //R
      analogWrite(5, 20); //G
      analogWrite(6, 20); //B
      break;
    case 'O': //Off (Uit)
      analogWrite(3, 0); //R
      analogWrite(5, 0); //G
      analogWrite(6, 0); //B
      break;
  }
}
