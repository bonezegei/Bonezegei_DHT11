/*
  DHT11 Library
  Author: Bonezegei (Jofel Batutay)
  Date : 
*/

#include <Arduino.h>

#ifndef _BONEZEGEI_DHT11_H_
#define _BONEZEGEI_DHT11_H_

class Bonezegei_DHT11 {
public:
  Bonezegei_DHT11();
  Bonezegei_DHT11(int8_t pin);
  char begin();
  char getData();
  float getTemperature();
  float getHumidity();

  int8_t _pin;
  uint8_t data[5];
  unsigned long prevtime;
};

#endif
