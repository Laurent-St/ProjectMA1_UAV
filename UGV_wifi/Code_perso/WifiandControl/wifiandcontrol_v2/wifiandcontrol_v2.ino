//byte received; 
float angle=0;
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
}

void loop() {
  if(Serial.available()){
  byte c = Serial.read();
  Serial2.write(c);
  }
  if(Serial2.available()){
    char b = Serial2.read();
    Serial.println(b); //serial or serial2?
    if(b==':'){
      for (int i=0; i<6; i++){
        if(i==0){
        char b = Serial2.read();
        }
        else{
        angle=angle+int(b)*pow(10,(-i-precision+length_message));
        char b = Serial2.read();
        }
      }
    }
    //Serial.println(angle);
    angle=0;
    //int sizeofb=sizeof(b);
    //Serial.write(sizeofb);
    //Serial.write("\n");
  }
}
//void loop(){
//if (Serial2.available()){
//  received = Serial2.read();
//  int length_message=length(received)-header;
//  for (int i=12; i<length_message; i++){
//    angle=angle+received[]*10^(i-precision-header+length_message-1)
//  }
//  Serial.write(b);
//  }
//}


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


