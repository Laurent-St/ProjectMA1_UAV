#include <ESP8266.h>  //librairy from github: https://github.com/Diaoul/arduino-ESP8266
#include <ESP8266Client.h> //librairy from github
//#include <SoftwareSerial.h>

#include<string>
#include<stdio.h>
#include<stdlib.h>

//SoftwareSerial esp8266Serial = SoftwareSerial(10, 11);
ESP8266 wifi = ESP8266(Serial2);

//byte received; 
float angle=0;
float angle_test=95;
String angle_string;

int precision=2;
int length_message=3+precision;
void setup() {
  Serial.begin(115200);
  Serial2.begin(115200); // initialize serial2
  //WiFibuf.reserve(50);
  delay(1500);
  Serial2.println("+AT");
  delay(250);
  Serial2.println("AT+CWMODE_CUR=2");
  delay(250);
  Serial2.println("AT+CWSAP_CUR=\"ugvWIFI\",\"protectugv\",7,0");
  delay(250);
  Serial2.println("AT+CIPMUX=1");
  delay(250);
  Serial2.println("AT+CIPSTART=0,\"UDP\",\"192.168.4.2\",444,333,0");
  //InitGcs = true;

  //esp8266Serial.begin(9600);
  wifi.begin();
  wifi.setTimeout(1000);
}

void loop() {
  // read data
    unsigned int id;
    int length;
    int totalRead;
    char buffer[11] = {};
    if ((length = wifi.available()) > 0) {
      id = wifi.getId();
      totalRead = wifi.read(buffer, 10);
      if (length > 0) {
//        Serial.print("Received ");
//        Serial.print(totalRead);
//        Serial.print("/");
//        Serial.print(length);
//        Serial.print(" bytes from client ");
//        Serial.print(id);
//        Serial.print(": ");
        //Serial.println((char*)buffer); //prints the received number
        
          Serial.println(buffer[0]);
          Serial.println("\n");
          Serial.println(buffer[1]);  //contains the first number
          Serial.println("\n");
          Serial.println(buffer[2]);
          Serial.println("\n");
          Serial.println(buffer[3]);
          Serial.println("\n");
          Serial.println(buffer[4]);
          Serial.println("\n");
          Serial.println(buffer[5]);
          Serial.println("\n");
          Serial.println(buffer[6]);
          Serial.println("\n");
          Serial.println(buffer[7]);
          Serial.println("\n");
          Serial.println(buffer[8]);
          Serial.println("\n");
          Serial.println(buffer[9]);
          Serial.println("\n");
          Serial.println(buffer[10]);
          Serial.println("\n");
          
        //angle='buffer';
        
        //std::string angle_string(buffer);
        //angle=angle_string.toFloat()
        //angle=std::stof(angle);

//        String.toCharArray(buffer, 10);
//        float angle = atof(buffer);

//        std::string angle_string(buffer);
//        angle=float(angle_string);

//        angle_string=String('buffer');
//        angle=angle_string.toFloat();
        
        if (int(angle) == int(angle_test)){   
          Serial.println("angleOK");
        }
      }
    }
}




