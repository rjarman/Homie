#ifndef Home_Automation_h
#define Home_Automation_h
#include "Arduino.h"


class Home_Automation {
    private:
        uint8_t _HC_SR04_triggerPin, _HC_SR04_echoPin, _pir_pin;
        int duration_HC_SR04;
        float distance_HC_SR04;
    
    public:
        Home_Automation(uint8_t pir_pin);
        Home_Automation(uint8_t HC_SR04_triggerPin, uint8_t HC_SR04_echoPin);
        void init();
        float getDistance_HC_SR04();
        bool get_PIR();
};

#endif