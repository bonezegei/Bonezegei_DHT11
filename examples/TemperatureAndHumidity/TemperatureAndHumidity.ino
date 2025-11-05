/*
  Read Temperature and Humidity
  DHT11 Library
  Author: Bonezegei (Jofel Batutay)
  Date : November 2023

  Tested using ESP32-WROOM32
*/

#include <Bonezegei_DHT11.h>

//param = DHT11 signal pin (Digital)
Bonezegei_DHT11 dht(14);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {

  float humAdjust = 0.85;  //DHT11 & DHT22 are known to be "off" - use this to adjust to your experience
  float tempAdjust = 1.0;  //This is less-known to be off but included in case you want to use it.
  
  String str = ""
  
  if (dht.getData()) {                         // get All data from DHT11
    float tempDeg = dht.getTemperature();      // return temperature in celsius
    float tempFar = dht.getTemperature(true);  // return temperature in fahrenheit if true celsius of false
    int hum = dht.getHumidity();               // return humidity

    //Apply Adjustments
    tempDeg *= tempAdjust;
    tempFar *= tempAdjust;
    hum *= humAdjust;
    
    str += "Temperature: ";
    str += tempDeg;
    str += "°C  ";
    str += tempFar;
    str += "°F  Humidity:";
    str += hum;
    Serial.println(str.c_str());
    //Serial.printf("Temperature: %0.1lf°C  %0.1lf°F Humidity:%d \n", tempDeg, tempFar, hum);
  } else {
    str += "No response from sensor!"
  };
  Serial.println(str.c_str());

  delay(2000);  //delay atleast 2 seconds for DHT11 to read tha data
}
