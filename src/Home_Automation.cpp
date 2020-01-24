#include "Arduino.h"
#include "Home_Automation.h"

Home_Automation::Home_Automation(uint8_t pir_pin){
    _pir_pin = pir_pin;
}

Home_Automation::Home_Automation(uint8_t HC_SR04_triggerPin, uint8_t HC_SR04_echoPin){
    _HC_SR04_triggerPin = HC_SR04_triggerPin;
    _HC_SR04_echoPin = HC_SR04_echoPin;
}

void Home_Automation::init(){
    if(_HC_SR04_triggerPin && _HC_SR04_echoPin){
        pinMode(_HC_SR04_triggerPin, OUTPUT);
        pinMode(_HC_SR04_echoPin, INPUT);
    }

    if(_pir_pin){
        pinMode(_pir_pin, INPUT);
    }
}

float Home_Automation::getDistance_HC_SR04(){

    digitalWrite(_HC_SR04_triggerPin, LOW);
    delayMicroseconds(10);
    digitalWrite(_HC_SR04_triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_HC_SR04_triggerPin, LOW);

    duration_HC_SR04 = pulseIn(_HC_SR04_echoPin, HIGH);
    distance_HC_SR04 = (duration_HC_SR04*0.034) / 2;

    return distance_HC_SR04;

}

bool Home_Automation::get_PIR(){
    if(digitalRead(_pir_pin)){
        return true;
    }

    return false;
}
