/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses
  the result to set the pulse width modulation (PWM) of an output pin.
  Also prints the results to the Serial Monitor.

  The circuit:
  - potentiometer connected to analog pin 0.
    Center pin of the potentiometer goes to the analog pin.
    side pins of the potentiometer go to +5V and ground
  - LED connected from digital pin 9 to ground

  created 24 JAN. 2020
  modified 24 JAN. 2020
  by Rafsun Jany Arman

  This example code is in the public domain.

  https://github.com/rjarman/Home-Automation
*/

#include<Home_Automation.h>

//Home_Automation(uint8_t HC_SR04_triggerPin, uint8_t HC_SR04_echoPin)
Home_Automation home_Automation(8,7);

void setup(){
  Serial.begin(9600);
  home_Automation.init();
}

void loop(){
  Serial.println(home_Automation.getDistance_HC_SR04());
}
