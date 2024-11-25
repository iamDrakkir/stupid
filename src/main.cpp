#include <Arduino.h>
#include <Wire.h>
#include <LOLIN_I2C_MOTOR.h>
// 4   	      GND 	    Ground
// 5   	      D2 	      Digital IO Pin 2
// 6   	      D3 	      Digital IO Pin 3
// 7   	      D4 	      Digital IO Pin 4
// 8   	      D5 	      Digital IO Pin 5
// 9   	      D6 	      Digital IO Pin 6
// 10 	      D7 	      Digital IO Pin 7
// 11 	      D8 	      Digital IO Pin 8
// 12 	      D9 	      Digital IO Pin 9
// 13 	      D10 	    Digital IO Pin 10
// 14 	      D11 	    Digital IO Pin 11
// 15 	      D12 	    Digital IO Pin 12
// 16 	      D13 	    Digital IO Pin 13
// 18 	      AREF 	    Analog Reference
// 19 	      A0 	      Analog Input 0
// 20 	      A1 	      Analog Input 1
// 21 	      A2 	      Analog Input 2
// 22 	      A3 	      Analog Input 3
// 23 	      A4 	      Analog Input 4
// 24 	      A5 	      Analog Input 5
// 25 	      A6 	      Analog Input 6
// 26 	      A7 	      Analog Input 7
// 27 	      5V 	      +5V Output/Input
// 28 	      RST 	    Reset (Active LOW)
// 29 	      GND 	    Ground
// 30 	      VIN 	    Unregulated Supply

void vibrate(int time);
void tighten(int time);
void loosen(int time);
bool buttonPressed();

int TEST_LED_PIN = 13;
int BUTTON_PIN = 3;


void setup() {
  pinMode(TEST_LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  if (buttonPressed()) {
    tighten(9000);
    vibrate(5000);
    delay(200);
    loosen(8000);
    delay(2000);           
  }
  delay(100);
}

bool buttonPressed() {
  return (digitalRead(BUTTON_PIN) == LOW);
}

void vibrate(int time) {
  LOLIN_I2C_MOTOR motor; 
  motor.changeFreq(MOTOR_CH_A, 1000); 

  motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_CW);
  motor.changeDuty(MOTOR_CH_A, 100);
  delay(time);
  
  motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_STOP);
}

void tighten(int time) {
  LOLIN_I2C_MOTOR motor; 
  motor.changeFreq(MOTOR_CH_B, 1000); 

  motor.changeStatus(MOTOR_CH_B, MOTOR_STATUS_CCW);
  motor.changeDuty(MOTOR_CH_B, 100);
  delay(time);
  
  motor.changeStatus(MOTOR_CH_B, MOTOR_STATUS_STOP);
}

void loosen(int time) {
  LOLIN_I2C_MOTOR motor; 
  motor.changeFreq(MOTOR_CH_B, 1000);

  motor.changeStatus(MOTOR_CH_B, MOTOR_STATUS_CW);
  motor.changeDuty(MOTOR_CH_B, 100);
  delay(time);
  
  motor.changeStatus(MOTOR_CH_B, MOTOR_STATUS_STOP);
}