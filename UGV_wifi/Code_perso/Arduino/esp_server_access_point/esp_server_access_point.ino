#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>


const char *ssid = "myESPNetwork";
const char *password = "testprotect"; //the password should be 8 char or more


MDNSResponder mdns;

String pageTurnOn = "<html><body><h1>LED is ON</h1><a href=\"/turnoff\">Turn Off</a></body></html>";

String pageTurnOff = "<html><body><h1>LED is OFF</h1><a href=\"/turnon\">Turn On</a></body></html>";

//setting the addresses
IPAddress ip(192,168,8,1);
IPAddress gateway(192, 168, 8, 1);
IPAddress subnet(255, 255, 255, 0);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  
  WiFi.mode(WIFI_AP); //switching to AP mode
  WiFi.softAP(ssid, password); //initializing the AP with ssid and password. This will create a WPA2-PSK secured AP
  WiFi.config(ip,gateway,subnet);
  WiFi.begin(ssid,password);
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
