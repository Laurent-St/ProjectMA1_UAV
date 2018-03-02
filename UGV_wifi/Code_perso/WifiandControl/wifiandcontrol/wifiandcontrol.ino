boolean newWiFibuf= false;
char WiFibuf = {0};
float angle=0;
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
}

void loop(){
if (Serial2.available()){
      serialWiFiEvent();
    }
    if (newWiFibuf){
      float temp_wifi = 0;
      memcpy(&temp_wifi,&WiFibuf,4);
        angle=temp_wifi;
        Serial.write("Received angle:");
        Serial.write(angle);
      WiFibuf = '0';
      newWiFibuf = false;
    }
}

void serialWiFiEvent() {
  while (Serial2.available()) {
    char inChar = (char)Serial2.read();
    if (inChar == '$') {
      char inChar = (char)Serial2.read();
      if (inChar == '$') {
        for (int i=0; i<36; i++){
          char inChar = (char)Serial2.read();
          WiFibuf += inChar;
        }
        inChar = (char)Serial2.read();     
        if (inChar == '*') {
          char inChar = (char)Serial2.read();
          if (inChar == '*') {
              newWiFibuf = true;                        
          }
        }
      } 
    }
  }
}

//void loop() {
//  if(Serial.available()){
//  byte c = Serial.read();
//  Serial2.write(c);
//  }
//  if(Serial2.available()){
//    byte b = Serial2.read();
//    Serial.write(b);
//  } 
//}


