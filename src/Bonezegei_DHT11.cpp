/*
  DHT11 Library
  Author: Bonezegei (Jofel Batutay)
  Date : November 2023
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
  data[0] = data[1] = data[2] = data[3] = data[4] = 0;
  digitalWrite(_pin, HIGH);
  delay(250);

  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  delay(18);
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

  data[5] = (data[0] + data[1] + data[2] + data[3]) & 0xff;
  if (data[4] == data[5]) {
    float t=(float)data[3] / 10;
    _temperatureDeg = data[2] + t;
    _temperatureFar = _temperatureDeg * 9 / 5 + 32;
    _humidity = data[0];
    return 1;
  }

  return 0;
}

float Bonezegei_DHT11::getTemperature() {
  return _temperatureDeg;
}

float Bonezegei_DHT11::getTemperature(bool fahrenheit){
  if(fahrenheit){
    return _temperatureFar;
  }
  else{
    return _temperatureDeg;
  }
}

int Bonezegei_DHT11::getHumidity() {
   return _humidity;
}
