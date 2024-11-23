#include <Arduino.h>
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
void tighten();
void loosen();
bool buttonPressed();

int TEST_LED_PIN = 13;
int VIBRATE_PIN = 5;
int TIGHTEN_PIN = 2;
int BUTTON_PIN = 3;
int STATIC_OUTPUT = 4;

void setup() {
  pinMode(TEST_LED_PIN, OUTPUT);
  pinMode(VIBRATE_PIN, OUTPUT);
  pinMode(TIGHTEN_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(STATIC_OUTPUT, OUTPUT);
  digitalWrite(STATIC_OUTPUT, HIGH);  
}

void loop() {
  // if (buttonPressed()) {
  //   tighten();
  //   vibrate(5000);
  //   loosen();
  //   delay(1000);           
  // }
  vibrate(5000);
  delay(1000);           
}

bool buttonPressed() {
  return digitalRead(BUTTON_PIN) == HIGH;
}

void vibrate(int time) {
  digitalWrite(VIBRATE_PIN, HIGH);
  digitalWrite(TEST_LED_PIN, HIGH);
  delay(time);           
  digitalWrite(TEST_LED_PIN, LOW);
  digitalWrite(VIBRATE_PIN, LOW);
}

void tighten() {
  digitalWrite(TIGHTEN_PIN, HIGH); 
  delay(1000);          
  digitalWrite(TIGHTEN_PIN, LOW);
}

void loosen() {
  digitalWrite(TIGHTEN_PIN, HIGH); 
  delay(1000);          
  digitalWrite(TIGHTEN_PIN, LOW);
}