#include "display.h"

unsigned char arrayMapOfLed[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

void led_init(){
    LED = 0x00;
}

void turnLedOn(unsigned char index){
    if(index >= 0 && index < 8){
        LED = LED | arrayMapOfLed[index];
    }
}

void turnLedOff(unsigned char index){
    if(index >= 0 && index < 8){
        LED = LED & ~arrayMapOfLed[index];
    }
}

void toggleLed(unsigned char index){
    if(index >= 0 && index < 8){
        LED = LED ^ arrayMapOfLed[index];
    }
}