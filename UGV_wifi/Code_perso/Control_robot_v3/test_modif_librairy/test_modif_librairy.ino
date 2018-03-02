odif#include <MotorWheel_modif.h> //modified librairy

#include <PinChangeInt.h>
#include <PinChangeIntConfig.h>
#include <EEPROM.h>
#include <fuzzy_table.h>
#include <PID_Beta6.h>
#include <Omni4WD_modif.h>

#include <fuzzy_table.h>
#include <PID_Beta6.h>

const float Pi = 3.14159;
float angle=Pi/3;

void setup() {
  //comes from sample code
  
  //TCCR0B=TCCR0B&0xf8|0x01;    // warning!! it will change millis()
  TCCR1B = TCCR1B & 0xf8 | 0x01; // Pin9,Pin10 PWM 31250Hz
  TCCR2B = TCCR2B & 0xf8 | 0x01; // Pin3,Pin11 PWM 31250Hz

  Omni.PIDEnable(0.31, 0.01, 0, 10);
}

void loop() {
  //Omni4WD_modif::movement_laurent(200,angle); //200=speed in millimeter per second
  //Omni4WD_modif::movement_laurent2(200,angle);
}
