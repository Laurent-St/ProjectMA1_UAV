 void setup() {
  Serial2.begin(115200); // initialize serial2
  //WiFibuf.reserve(50);
  delay(1500);
  Serial2.println("+AT");
  delay(250);
  Serial2.println("AT+CWMODE=2");
  delay(250);
  Serial2.println("AT+CWSAP=\"uavWIFI\",\"gaetano\",7,0");
  delay(250);
  Serial2.println("AT+CIPMUX=1");
  delay(250);
  Serial2.println("AT+CIPSTART=0,\"UDP\",\"192.168.4.2\",444,333,0");
  //InitGcs = true;
}

void loop() {
//    t_init = millis();
//    dt_5= (float) (t_init-t_end)/1000;
//    if (Serial2.available()){
//      serialWiFiEvent();
//    }
//    if (newWiFibuf){
//      t_new = millis();
//      dt_wifi = (float) (t_new-t_call)/1000;
//      t_call = millis();
//      dt_no_wifi_event=0;
//      float temp_wifi[6] = {0};
//      int temp_start_ctr = 0;
//      memcpy(&temp_wifi[0],&WiFibuf[0],4);
//      memcpy(&temp_wifi[1],&WiFibuf[4],4);
//      memcpy(&temp_wifi[2],&WiFibuf[8],4);
//      memcpy(&temp_wifi[3],&WiFibuf[12],4);
//      memcpy(&temp_wifi[4],&WiFibuf[16],4);
//      memcpy(&temp_wifi[5],&WiFibuf[20],4);
//      memcpy(&temp_start_ctr,&WiFibuf[24],4);
//      memcpy(&t_wifi_2,&WiFibuf[28],4);
//      memcpy(&readed_ck,&WiFibuf[32],4);
//      float ck = compute_checksum_float(temp_wifi,6);
//      computed_ck=ck;
//      if (computed_ck==readed_ck){
//        thrust=temp_wifi[0];
//        ref_roll=temp_wifi[1];
//        ref_pitch=temp_wifi[2];
//        ref_yaw=temp_wifi[3];
//        start_ctr=temp_start_ctr;
//        err_ck=0;
//      }
//      else{
//        err_ck=err_ck+1;
//      }
//      dt_msg=t_wifi_2-t_wifi_1;
//      t_wifi_1=t_wifi_2;
//      WiFibuf = "";
//      newWiFibuf = false;
//    }
//    else{
//      t_no_wifi=millis();
//      dt_no_wifi_event=(float) (t_no_wifi-t_new)/1000;
//    }
//    
//    create_sendbuf_wifi(motor_pwm,euler,gyro,(float) (millis()-time0)/1000,sendWiFi);
//    Serial2.println("AT+CIPSEND=0,40");
//    vTaskDelay((10L * configTICK_RATE_HZ) / 1000L);
//    Serial2.write(sendWiFi,40);
//    t_end = millis();
//    dt_7= (float) (t_end-t_init)/1000;
//    vTaskDelay((90L * configTICK_RATE_HZ) / 1000L);
}
