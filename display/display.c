#include "display.h"

#define RED_LIGHT       "  R"
#define YELLOW_LIGHT    " Y "
#define GREEN_LIGHT     "G  "

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
    LcdPrintStringS(1,0,RED_LIGHT);
}

void setRoad1_yellow(){
    LcdPrintStringS(1,0,YELLOW_LIGHT);
}

void setRoad1_green(){
    LcdPrintStringS(1,0,GREEN_LIGHT);
}

void toggleRoad1_red();
void toggleRoad1_yellow();
void toggleRoad1_green();

void setRoad2_red(){
    LcdPrintStringS(1,8,RED_LIGHT);
}

void setRoad2_yellow(){
    LcdPrintStringS(1,8,YELLOW_LIGHT);
}

void setRoad2_green(){
    LcdPrintStringS(1,8,GREEN_LIGHT);
}

void displayCounter1(){
    if(counter1 != 0) {
        LcdPrintNumS(1,4,counter1/10);
        LcdPrintNumS(1,5,counter1%10);
    } else {
        LcdPrintStringS(1,4,"  ");
    }
}

void displayCounter2(){
    if(counter1 != 0) {
        LcdPrintNumS(1,12,counter2/10);
        LcdPrintNumS(1,13,counter2%10);
    } else {
        LcdPrintStringS(1,4,"  ");
    }
}

void toggleRoad2_red();
void toggleRoad2_yellow();
void toggleRoad2_green();