void setup() {
  Serial3.begin(115200); // initialize serial3  ATTENTION logic levels have to be 3.3V, on Arduino Due Serial 3 it is OK 
  //Serial.begin(115200);
  
  //WiFibuf.reserve(50);
  
  delay(1500);
  Serial3.write("+AT");  //check communication
  delay(250);
  Serial3.write("AT+CWMODE_CUR=2");  //put the ESP in softAP mode
                                    //ATTENTION to change it permanently, put AT+CWMODE instead of AT+CWMODE_CUR, but apparently it is deprecated
  delay(250);
  Serial3.write("AT+CWSAP_CUR=\"ugv_wifi\",\"protect\",10,0");  //configures the softAP mode, 
  //last arguments: 10=10 maximum connections (NON PAS SUR), 0=SSID is broadcasted (not hidden) (NON PAS SUR, c'est juste pour dire qu'il n'y a pas de mot de passe)
   //ATTENTION to change it permanently, put AT+CWSAP instead of AT+CWSAP_CUR,but apparently it is deprecated
  delay(250);
  Serial3.write("AT+CIPMUX=1"); //enables multiple connections
  delay(250);
  Serial3.write("AT+CIPSTART=0,\"UDP\",\"192.168.4.2\",444,333,0"); //establishes connection (UDP here)
  //arguments: linkID (between 0 and 4, gives the ID of network connection), 
  //           type=UDP here,
  //           remoteIP,
  //           remotePorts: 444,333 and 0 here
  
  //InitGcs = true;

}

void loop() {
  //delay(1000);
  //Serial3.write("AT");
  //Serial.write(Serial3.read());
  
}
