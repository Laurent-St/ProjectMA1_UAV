#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "NUMERICABLE_D921";
const char* password = "BEDEESNNGK";

ESP8266WebServer server(80);

MDNSResponder mdns;

String pageTurnOn = "<html><body><h1>LED is ON</h1><a href=\"/turnoff\">Turn Off</a></body></html>";

String pageTurnOff = "<html><body><h1>LED is OFF</h1><a href=\"/turnon\">Turn On</a></body></html>";

void setup() {

  pinMode(LED_BUILTIN, OUTPUT);

  WiFi.begin(ssid, password);
 
  delay(1000);

  while (WiFi.status() != WL_CONNECTED) {
    delay(200);

    //a flashing LED means the ESP is not connected
    digitalWrite(LED_BUILTIN,!digitalRead(LED_BUILTIN));
  }

  //a stable LED on means the ESP is now connected
  digitalWrite(LED_BUILTIN,true);

  mdns.begin("esp8266", WiFi.localIP());

  server.on("/turnon", [](){
   server.send(200, "text/html", pageTurnOn);

   digitalWrite(LED_BUILTIN,HIGH);

 });

 server.on("/turnoff", [](){
   server.send(200, "text/html", pageTurnOff);

   digitalWrite(LED_BUILTIN,LOW);
 });

   server.onNotFound([](){

     server.send(404, "text/html", "Command Not Found");

   });

  server.begin();

}

void loop(void){
  server.handleClient();
}
