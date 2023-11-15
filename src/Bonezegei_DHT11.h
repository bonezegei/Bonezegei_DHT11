/*
  DHT11 Library
  Author: Bonezegei (Jofel Batutay)
  Date : November 2023
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
  float getTemperature(bool fahrenheit);
  int getHumidity();

  int8_t _pin;
  uint8_t data[6];
  unsigned long prevtime;

  int _humidity;
  float _temperatureDeg;
  float _temperatureFar;
};

#endif
