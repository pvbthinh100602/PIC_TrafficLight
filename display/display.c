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

void setRoad1_red(){
    LcdPrintStringS(0,0,"Re");
}

void setRoad1_yellow(){
    LcdPrintStringS(0,0,"Ye");
}

void setRoad1_green(){
    LcdPrintStringS(0,0,"Gr");
}

void toggleRoad1_red();
void toggleRoad1_yellow();
void toggleRoad1_green();

void setRoad2_red(){
    LcdPrintStringS(1,0,"Re");
}

void setRoad2_yellow(){
    LcdPrintStringS(1,0,"Ye");
}

void setRoad2_green(){
    LcdPrintStringS(1,0,"Gr");
}

void displayCounter(){
    if(counter1 != 0) LcdPrintNumS(0,5,counter1);
    if(counter2 != 0) LcdPrintNumS(1,5,counter2);
}

void toggleRoad2_red();
void toggleRoad2_yellow();
void toggleRoad2_green();