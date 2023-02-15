#include "display.h"

#define RED_LIGHT       "  R"
#define YELLOW_LIGHT    " Y "
#define GREEN_LIGHT     "G  "

#define RED     0
#define GREEN   1
#define YELLOW  2
#define BLANK   3

unsigned char road1_light = BLANK, road2_light = BLANK;

unsigned char arrayMapOfLed[8] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};

void led_init(){
    LED = 0x00;
}

void init_buzzer(){
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
    road1_light = RED;
}

void setRoad1_yellow(){
    LcdPrintStringS(1,0,YELLOW_LIGHT);
    road1_light = YELLOW;
}

void setRoad1_green(){
    LcdPrintStringS(1,0,GREEN_LIGHT);
    road1_light = GREEN;
}

void setRoad1_blank(){
    LcdPrintStringS(1,0,"   ");
    road1_light = BLANK;
}

void toggleRoad1_red(){
    if(road1_light != BLANK){
        setRoad1_blank();
    } else {
        setRoad1_red();
    }
}
void toggleRoad1_yellow(){
    if(road1_light != BLANK){
        setRoad1_blank();
    } else {
        setRoad1_yellow();
    }    
}
void toggleRoad1_green(){
    if(road1_light != BLANK){
        setRoad1_blank();
    } else {
        setRoad1_green();
    }    
}

void setRoad2_red(){
    LcdPrintStringS(1,8,RED_LIGHT);
    road2_light = RED;
}

void setRoad2_yellow(){
    LcdPrintStringS(1,8,YELLOW_LIGHT);
    road2_light = YELLOW;
}

void setRoad2_green(){
    LcdPrintStringS(1,8,GREEN_LIGHT);
    road2_light = GREEN;
}

void setRoad2_blank(){
    LcdPrintStringS(1,8,"   ");
    road2_light = BLANK;
}

void toggleRoad2_red(){
    if(road2_light != BLANK){
        setRoad2_blank();
    } else {
        setRoad2_red();
    }    
}

void toggleRoad2_yellow(){
    if(road2_light != BLANK){
        setRoad2_blank();
    } else {
        setRoad2_yellow();
    }      
}
void toggleRoad2_green(){
    if(road2_light != BLANK){
        setRoad2_blank();
    } else {
        setRoad2_green();
    }      
}

void displayCounter(){
    if(counter1 != 0) {
        LcdPrintNumS(1,4,counter1/10);
        LcdPrintNumS(1,5,counter1%10);
    } else {
        LcdPrintStringS(1,4,"  ");
    }
    
    if(counter2 != 0) {
        LcdPrintNumS(1,12,counter2/10);
        LcdPrintNumS(1,13,counter2%10);
    } else {
        LcdPrintStringS(1,12,"  ");    
    }
}