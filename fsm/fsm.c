#include "fsm.h"

void fsm_mode(){
    switch(traffic_status){
        case INIT:
            traffic_status = MODE_AUTO;
            SetTimer3_ms(20000);
            break;
        case MODE_AUTO:
            LcdPrintStringS(0,0,"   AUTO MODE    ");
            LcdPrintStringS(1,0,"                ");            
            counter1 = 0;
            counter2 = 0;
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = MODE_MAN;               
            }
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = MODE_CONFIG;
            }
            if(is_button_press(MODE_BUTTON)){
                SetTimer3_ms(1000);
                traffic_status = AUTO_RED_GREEN;
                counter1 = max_red1;
                counter2 = max_green2;                
            }
            if(timer3_flag){
                SetTimer3_ms(1000);
                traffic_status = AUTO_RED_GREEN;
                counter1 = max_red1;
                counter2 = max_green2;       
            }
            break;
        case MODE_MAN:
            LcdPrintStringS(0,0,"  MANUAL MODE   ");
            LcdPrintStringS(1,0,"                ");
            counter1 = 0;
            counter2 = 0;            
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = MODE_SLOW;
            }
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = MODE_AUTO;
            }
            if(is_button_press(MODE_BUTTON)){
                traffic_status = MAN_RED_GREEN;
                SetTimer3_ms(20000);
            }
            if(timer3_flag){
                SetTimer3_ms(1000);
                traffic_status = AUTO_RED_GREEN;
                counter1 = max_red1;
                counter2 = max_green2;       
            }
            break;
        case MODE_SLOW:
            LcdPrintStringS(0,0," SLOWDOWN MODE  ");
            LcdPrintStringS(1,0,"                ");
            counter1 = 0;
            counter2 = 0;            
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = MODE_CONFIG;
            }
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = MODE_MAN;
            }
            if(is_button_press(MODE_BUTTON)){                
                traffic_status = SLOW;
                SetTimer3_ms(1000);
            }
            if(timer3_flag){
                SetTimer3_ms(1000);
                traffic_status = AUTO_RED_GREEN;
                counter1 = max_red1;
                counter2 = max_green2;       
            }
            break;
        case MODE_CONFIG:
            LcdPrintStringS(0,0,"  CONFIG MODE   ");
            LcdPrintStringS(1,0,"                ");
            counter1 = 0;
            counter2 = 0;            
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = MODE_AUTO;
            }
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = MODE_SLOW;
            }
            if(is_button_press(MODE_BUTTON)){                
                traffic_status = CONFIG_RED1;
                counter1 = max_red1;
            }
            if(timer3_flag){
                SetTimer3_ms(1000);
                traffic_status = AUTO_RED_GREEN;
                counter1 = max_red1;
                counter2 = max_green2;       
            }
            break;
        default:
            break;
    }
}

void fsm_auto(){
    switch(traffic_status){
        case AUTO_RED_GREEN:
            setRoad1_red();
            setRoad2_green();
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1--;
                counter2--;                
                if(counter2 == 0){
                    counter2 = max_yellow2;
                    traffic_status = AUTO_RED_YELLOW;
                }
            }
            if(is_button_press(MODE_BUTTON)){
                traffic_status = MODE_AUTO;
                SetTimer3_ms(20000);
            }
            break;
        case AUTO_RED_YELLOW:
            setRoad1_red();
            setRoad2_yellow();
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1--;
                counter2--;                
                if(counter2 == 0){
                    counter1 = max_green1;
                    counter2 = max_red2;
                    traffic_status = AUTO_GREEN_RED;
                }
            }
            if(is_button_press(MODE_BUTTON)){
                traffic_status = MODE_AUTO;
                SetTimer3_ms(20000);
            }            
            break;
        case AUTO_GREEN_RED:
            setRoad1_green();
            setRoad2_red();
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1--;
                counter2--;                
                if(counter1 == 0){
                    counter1 = max_yellow1;
                    traffic_status = AUTO_YELLOW_RED;
                }
            }
            if(is_button_press(MODE_BUTTON)){
                traffic_status = MODE_AUTO;
                SetTimer3_ms(20000);
            }            
            break;        
        case AUTO_YELLOW_RED:
            setRoad1_yellow();
            setRoad2_red();
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1--;
                counter2--;                
                if(counter1 == 0){
                    counter1 = max_red1;
                    counter2 = max_green2;
                    traffic_status = AUTO_RED_GREEN;
                }
            } 
            if(is_button_press(MODE_BUTTON)){
                traffic_status = MODE_AUTO;
                SetTimer3_ms(20000);
            }
            break;
        default:
            break;
    }
}

void fsm_man(){
    switch(traffic_status){
        case MAN_RED_GREEN:
            setRoad1_red();
            setRoad2_green();
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_yellow2;
                counter2 = max_yellow2;
                traffic_status = AUTO_RED_YELLOW;
            }
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = MAN_RED_YELLOW;
            }
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = MAN_YELLOW_RED;
            }            
            if(is_button_press(MODE_BUTTON)){
                traffic_status = MODE_MAN;
                SetTimer3_ms(20000);
            }
            break;
        case MAN_RED_YELLOW:
            setRoad1_red();
            setRoad2_yellow();
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_green1;
                counter2 = max_red2;
                traffic_status = AUTO_GREEN_RED;
            }            
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = MAN_GREEN_RED;
            }           
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = MAN_RED_GREEN;
            }            
            if(is_button_press(MODE_BUTTON)){
                traffic_status = MODE_MAN;
                SetTimer3_ms(20000);
            }
            break;
        case MAN_GREEN_RED:
            setRoad1_green();
            setRoad2_red();
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_yellow1;
                counter2 = max_yellow2;
                traffic_status = AUTO_YELLOW_RED;
            }
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = MAN_YELLOW_RED;
            }            
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = MAN_RED_YELLOW;
            }            
            if(is_button_press(MODE_BUTTON)){
                traffic_status = MODE_MAN;
                SetTimer3_ms(20000);
            }
            break;
        case MAN_YELLOW_RED:
            setRoad1_yellow();
            setRoad2_red();
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                traffic_status = AUTO_RED_GREEN;
            }
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = MAN_RED_GREEN;
            }
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = MAN_GREEN_RED;
            }
            if(is_button_press(MODE_BUTTON)){
                traffic_status = MODE_MAN;
                SetTimer3_ms(20000);
            }
            break;            
    }
}

void fsm_config(){
    switch(traffic_status){
        case CONFIG_RED1:
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                traffic_status = AUTO_RED_GREEN;
            }
            if(is_button_press(MODE_BUTTON)){   
                SetTimer3_ms(20000);
                traffic_status = CONFIG_RED1_ENTER;
                counter1 = max_red1;
            }
            if(is_button_press(INC_BUTTON)){   
                SetTimer3_ms(20000);
                traffic_status = CONFIG_RED2;
            }
            if(is_button_press(DEC_BUTTON)){   
                SetTimer3_ms(20000);
                traffic_status = CONFIG_GREEN2;
            }
            break;
        case CONFIG_RED2:
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                traffic_status = AUTO_RED_GREEN;
            }            
            if(is_button_press(MODE_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = CONFIG_RED2_ENTER;
                counter2 = max_red2;
            }
            if(is_button_press(INC_BUTTON)){   
                SetTimer3_ms(20000);
                traffic_status = CONFIG_GREEN1;
            }            
            if(is_button_press(DEC_BUTTON)){   
                SetTimer3_ms(20000);
                traffic_status = CONFIG_RED1;
            }
            break;
        case CONFIG_GREEN1:
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                traffic_status = AUTO_RED_GREEN;
            }
            if(is_button_press(MODE_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = CONFIG_GREEN1_ENTER;
                counter1 = max_green1;
            }
            if(is_button_press(INC_BUTTON)){   
                SetTimer3_ms(20000);
                traffic_status = CONFIG_GREEN2;
            }
            if(is_button_press(DEC_BUTTON)){   
                SetTimer3_ms(20000);
                traffic_status = CONFIG_RED2;
            }
            break;
        case CONFIG_GREEN2:
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                traffic_status = AUTO_RED_GREEN;
            }
            if(is_button_press(MODE_BUTTON)){
                SetTimer3_ms(20000);
                traffic_status = CONFIG_GREEN2_ENTER;
                counter2 = max_green2;
            }            
            if(is_button_press(INC_BUTTON)){   
                SetTimer3_ms(20000);
                traffic_status = CONFIG_RED1;
            }
            if(is_button_press(DEC_BUTTON)){   
                SetTimer3_ms(20000);
                traffic_status = CONFIG_GREEN1;
            }
            break;
        case CONFIG_RED1_ENTER:
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                traffic_status = AUTO_RED_GREEN;
            }
            break;
        case CONFIG_RED2_ENTER:
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                traffic_status = AUTO_RED_GREEN;
            }
            break;
        case CONFIG_GREEN1_ENTER:
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                traffic_status = AUTO_RED_GREEN;
            }
            break;
        case CONFIG_GREEN2_ENTER:
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                traffic_status = AUTO_RED_GREEN;
            }
            break;           
        default:
            break;
    }
}