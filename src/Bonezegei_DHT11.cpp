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
    return 1;
  }
}

char Bonezegei_DHT11::getData() {
  data[0] = data[1] = data[2] = data[3] = data[4] = 0;


  return 0;
}

float Bonezegei_DHT11::getTemperature() {

  return 0;
}

float Bonezegei_DHT11::getHumidity() {
  return 0;
}
