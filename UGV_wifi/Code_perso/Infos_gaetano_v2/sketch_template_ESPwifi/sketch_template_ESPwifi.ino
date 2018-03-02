while (1) {
    if (Serial2.available()){
      serialWiFiEvent();
    }
    if (newWiFibuf){
      dt_no_wifi_event=0;
      float temp_wifi[6] = {0};
      int temp_start_ctr = 0;
      memcpy(&temp_wifi[0],&WiFibuf[0],4);
      memcpy(&temp_wifi[1],&WiFibuf[4],4);
      memcpy(&temp_wifi[2],&WiFibuf[8],4);
      memcpy(&temp_wifi[3],&WiFibuf[12],4);
      memcpy(&temp_wifi[4],&WiFibuf[16],4);
      memcpy(&temp_wifi[5],&WiFibuf[20],4);
      memcpy(&temp_start_ctr,&WiFibuf[24],4);
      memcpy(&t_wifi_2,&WiFibuf[28],4);
      memcpy(&readed_ck,&WiFibuf[32],4);
        thrust=temp_wifi[0];
        ref_roll=temp_wifi[1];
        ref_pitch=temp_wifi[2];
        ref_yaw=temp_wifi[3];
        start_ctr=temp_start_ctr;
        err_ck=0;
      WiFibuf = "";
      newWiFibuf = false;
    }
    else{
      dt_no_wifi_event=(float) (t_no_wifi-t_new)/1000;
    }
    
    create_sendbuf_wifi(motor_pwm,euler,gyro,(float) (millis()-time0)/1000,sendWiFi);
    Serial2.println("AT+CIPSEND=0,40");
    vTaskDelay((10L * configTICK_RATE_HZ) / 1000L);
    Serial2.write(sendWiFi,40);
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

void float2Bytes(float val,byte* bytes_array){
  // Create union of shared memory space
  union {
    float float_variable;
    byte temp_array[4];
  } u;
  // Overite bytes of union with float variable
  u.float_variable = val;
  // Assign bytes to input array
  memcpy(bytes_array, u.temp_array, 4);
}

void int2Bytes(int val,byte* bytes_array){
  // Create union of shared memory space
  union {
    int int_variable;
    byte temp_array[4];
  } u;
  // Overite bytes of union with float variable
  u.int_variable = val;
  // Assign bytes to input array
  memcpy(bytes_array, u.temp_array, 4);
}

void create_sendbuf_wifi(int* pwm, float* attitude,float* gyro, float t, byte* buf){
  int i=0;
  byte v_byte[4];
  int2Bytes(pwm[0],v_byte); memcpy(&buf[0],&v_byte,4);
  int2Bytes(pwm[3],v_byte); memcpy(&buf[4],&v_byte,4);
  int2Bytes(pwm[5],v_byte); memcpy(&buf[8],&v_byte,4);
  
  float2Bytes(gyro[0],v_byte); memcpy(&buf[12],&v_byte,4);
  float2Bytes(gyro[1],v_byte); memcpy(&buf[16],&v_byte,4);
  float2Bytes(gyro[2],v_byte); memcpy(&buf[20],&v_byte,4);
    
  float2Bytes(attitude[0],v_byte); memcpy(&buf[24],&v_byte,4);
  float2Bytes(attitude[1],v_byte); memcpy(&buf[28],&v_byte,4);
  float2Bytes(attitude[2],v_byte); memcpy(&buf[32],&v_byte,4);
  
  float2Bytes(t,v_byte); memcpy(&buf[36],&v_byte,4);
}
