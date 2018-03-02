void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);
  delay(1000);
}

void loop() {
  if(Serial.available()){
  byte c = Serial.read();
  Serial3.write(c);
  }
  if(Serial3.available()){
    byte b = Serial3.read();
    Serial.write(b);
  }
}
/*  Manual Setup to act as access point: Commands to copy: 
AT
AT+CWMODE_CUR=2   ou    3 ?
AT+CWSAP_CUR="ugv_wifi","protectugv",10,0
AT+CIPMUX=1
AT+CIPSTART=0,"UDP","192.168.4.2",444,333,0
//AT+CWDHCP=0,0
//AT+CIPAP_CUR="192.168.4.2","192.168.4.2","255.255.255.0"
//AT+CIPAP?

Manual Setup to connect to a wifi network: Commands to copy: 
/AT+CWMODE=1
AT+CWLAP   to list available networks
AT+CWJAP="NUMERICABLE-D921","BEDEESNNGK"   to connect to the network
AT+CIPSTA?     to check the IP address
AT+CIFSR       to check the local IP address
AT+CIPMUX=1
AT+CIPSTART=0,"UDP","192.168.0.13",444,333,0  to communicate with my computer  (192.168.0.13=address of my computer,444=port of my computer)
AT+CIPCLOSE=0    ou   5    to close connection

Send data to the target specified with AT+CIPSTART:
AT+CIPSEND=0,7  //send 7 bytes on connection 0 from CIPSTART
ensuite taper UDPtest sans carriage return
*/


