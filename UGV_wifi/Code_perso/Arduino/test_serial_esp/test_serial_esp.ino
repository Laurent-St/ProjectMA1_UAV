#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(10);
}

void loop() {
  delay(1000);
  Serial.println("Hello world");
  delay(2000);
}

