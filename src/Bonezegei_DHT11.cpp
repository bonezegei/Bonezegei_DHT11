/*
  DHT11 Library
  Author: Bonezegei (Jofel Batutay)
  Date : 
*/

#include "Bonezegei_DHT11.h"

Bonezegei_DHT11::Bonezegei_DHT11() {
  _pin = -1;
}

Bonezegei_DHT11::Bonezegei_DHT11(int8_t pin) {
  _pin = pin;
}

char Bonezegei_DHT11::begin() {
  if (_pin < 0) {
    return 0;
  } else {
    prevtime = 0;
    pinMode(_pin, INPUT);
    digitalWrite(_pin, HIGH);
    return 1;
  }
}

char Bonezegei_DHT11::getData() {
  //uint8_t prevstate = HIGH;
  int cnt = 0;
  //unsigned long ctime;

  data[0] = data[1] = data[2] = data[3] = data[4] = 0;

  digitalWrite(_pin, HIGH);
  delay(250);

  // now pull it low for ~20 milliseconds
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  delay(20);
  noInterrupts();
  digitalWrite(_pin, HIGH);
  delayMicroseconds(40);
  pinMode(_pin, INPUT);

  if (digitalRead(_pin) == LOW) {
    delayMicroseconds(80);
    if (digitalRead(_pin) == HIGH) {
      delayMicroseconds(80);

      for (int b = 0; b < 5; b++) {
        for (int a = 0; a < 8; a++) {
          while (digitalRead(_pin) == LOW)
            ;
          delayMicroseconds(30);
          if (digitalRead(_pin) == HIGH) {
            data[b] |= (1 << (7 - a));
          }
          while (digitalRead(_pin) == HIGH)
            ;
        }
      }
    }
  }
 

  interrupts();

  return 0;
}

float Bonezegei_DHT11::getTemperature() {

  return 0;
}

float Bonezegei_DHT11::getHumidity() {
  return 0;
}
