#include "fsm.h"

void fsm_mode(){
    switch(traffic_status){
        case INIT:
            traffic_status = MODE_AUTO;
            SetTimer3_ms(return_auto_time*1000);
            break;
        case MODE_AUTO:
            LcdPrintStringS(0,0,"   AUTO MODE    ");
            LcdPrintStringS(1,0,"                ");            
            counter1 = 0;
            counter2 = 0;
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MODE_MAN;               
            }
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
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
            clear_button_flags();
            break;
        case MODE_MAN:
            LcdPrintStringS(0,0,"  MANUAL MODE   ");
            LcdPrintStringS(1,0,"                ");
            counter1 = 0;
            counter2 = 0;            
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MODE_SLOW;
            }
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MODE_AUTO;
            }
            if(is_button_press(MODE_BUTTON)){
                traffic_status = MAN_RED_GREEN;
                SetTimer3_ms(return_auto_time*1000);
            }
            if(timer3_flag){
                SetTimer3_ms(1000);
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                traffic_status = AUTO_RED_GREEN;
                counter1 = max_red1;
                counter2 = max_green2;       
            }
            clear_button_flags();
            break;
        case MODE_SLOW:
            LcdPrintStringS(0,0," SLOWDOWN MODE  ");
            LcdPrintStringS(1,0,"                ");
            counter1 = 0;
            counter2 = 0;            
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MODE_CONFIG;
            }
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MODE_MAN;
            }
            if(is_button_press(MODE_BUTTON)){                
                traffic_status = AUTO_SLOW;
                SetTimer3_ms(1000);
            }
            if(timer3_flag){
                SetTimer3_ms(1000);
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                traffic_status = AUTO_RED_GREEN;
                counter1 = max_red1;
                counter2 = max_green2;       
            }
            clear_button_flags();
            break;
        case MODE_CONFIG:
            LcdPrintStringS(0,0,"  CONFIG MODE   ");
            LcdPrintStringS(1,0,"                ");
            counter1 = 0;
            counter2 = 0;            
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MODE_AUTO;
            }
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MODE_SLOW;
            }
            if(is_button_press(MODE_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);                
                traffic_status = CONFIG_RED1;
                counter1 = max_red1;
            }
            if(timer3_flag){
                SetTimer3_ms(1000);
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                traffic_status = AUTO_RED_GREEN;
                counter1 = max_red1;
                counter2 = max_green2;       
            }
            clear_button_flags();
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
            displayCounter1();
            displayCounter2();
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1--;
                counter2--;                
                if(counter2 == 0){
                    counter2 = max_yellow2;
                    traffic_status = AUTO_RED_YELLOW;
                }
            }
            if(is_button_long_press(MODE_BUTTON)){
                traffic_status = MODE_AUTO;
                SetTimer3_ms(return_auto_time*1000);
            }
            clear_button_flags();
            break;
        case AUTO_RED_YELLOW:
            setRoad1_red();
            setRoad2_yellow();
            displayCounter1();
            displayCounter2();
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
            if(is_button_long_press(MODE_BUTTON)){
                traffic_status = MODE_AUTO;
                SetTimer3_ms(return_auto_time*1000);
            }
            clear_button_flags();
            break;
        case AUTO_GREEN_RED:
            setRoad1_green();
            setRoad2_red();
            displayCounter1();
            displayCounter2();
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1--;
                counter2--;                
                if(counter1 == 0){
                    counter1 = max_yellow1;
                    traffic_status = AUTO_YELLOW_RED;
                }
            }
            if(is_button_long_press(MODE_BUTTON)){
                traffic_status = MODE_AUTO;
                SetTimer3_ms(return_auto_time*1000);
            }
            clear_button_flags();
            break;        
        case AUTO_YELLOW_RED:
            setRoad1_yellow();
            setRoad2_red();
            displayCounter1();
            displayCounter2();
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
            if(is_button_long_press(MODE_BUTTON)){
                traffic_status = MODE_AUTO;
                SetTimer3_ms(return_auto_time*1000);
            }
            clear_button_flags();
            break;
        case AUTO_SLOW:
            if(timer3_flag){
                toggleRoad1_yellow();
                toggleRoad2_yellow();
                SetTimer3_ms(1000);
            }
            if(is_button_long_press(MODE_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MODE_SLOW;
            }
        default:
            break;
    }
}

void fsm_man(){
    switch(traffic_status){
        case MAN_RED_GREEN:
            turnOffCounter1();
            turnOffCounter2();
            setRoad1_red();
            setRoad2_green();
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_yellow2;
                counter2 = max_yellow2;
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                traffic_status = AUTO_RED_YELLOW;
            }
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MAN_RED_YELLOW;
            }            
            if(is_button_long_press(MODE_BUTTON)){
                traffic_status = MODE_MAN;                
                SetTimer3_ms(return_auto_time*1000);
            }
            break;
        case MAN_RED_YELLOW:
            setRoad1_red();
            setRoad2_yellow();
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_green1;
                counter2 = max_red2;
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                traffic_status = AUTO_GREEN_RED;
            }            
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MAN_GREEN_RED;
            }                      
            if(is_button_long_press(MODE_BUTTON)){
                traffic_status = MODE_MAN;
                SetTimer3_ms(return_auto_time*1000);
            }
            break;
        case MAN_GREEN_RED:
            setRoad1_green();
            setRoad2_red();
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_yellow1;
                counter2 = max_yellow2;
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                traffic_status = AUTO_YELLOW_RED;
            }
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MAN_YELLOW_RED;
            }              
            if(is_button_long_press(MODE_BUTTON)){
                traffic_status = MODE_MAN;
                SetTimer3_ms(return_auto_time*1000);
            }
            clear_button_flags();
            break;
        case MAN_YELLOW_RED:
            setRoad1_yellow();
            setRoad2_red();
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                traffic_status = AUTO_RED_GREEN;
            }
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MAN_RED_GREEN;
            }
            if(is_button_long_press(MODE_BUTTON)){
                traffic_status = MODE_MAN;
                SetTimer3_ms(return_auto_time*1000);
            }
            clear_button_flags();
            break;            
    }
}

void fsm_config(){
    switch(traffic_status){
        case CONFIG_RED1:
            setRoad1_red();
            displayCounter1();
            setRoad2_blank();
            turnOffCounter2();
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                traffic_status = AUTO_RED_GREEN;
            }
            if(is_button_long_press(MODE_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MODE_CONFIG;
            }
            if(is_button_press(MODE_BUTTON)){   
                SetTimer3_ms(return_auto_time*1000);
                SetTimer4_ms(500);
                traffic_status = CONFIG_RED1_ENTER;
            }
            if(is_button_press(INC_BUTTON)){   
                SetTimer3_ms(return_auto_time*1000);
                counter1 = 0;
                counter2 = max_red2;
                traffic_status = CONFIG_RED2;
            }
            if(is_button_press(DEC_BUTTON)){   
                SetTimer3_ms(return_auto_time*1000);
                counter1 = 0;
                counter2 = max_green2;
                traffic_status = CONFIG_TURN_AUTO;
            }
            clear_button_flags();
            break;
        case CONFIG_RED2:
            turnOffCounter1();
            displayCounter2();
            setRoad1_blank();
            setRoad2_red();
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                traffic_status = AUTO_RED_GREEN;
            }
            if(is_button_long_press(MODE_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MODE_CONFIG;
            }            
            if(is_button_press(MODE_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                SetTimer4_ms(500);
                traffic_status = CONFIG_RED2_ENTER;
            }
            if(is_button_press(INC_BUTTON)){   
                SetTimer3_ms(return_auto_time*1000);
                counter1 = max_green1;
                counter2 = 0;
                traffic_status = CONFIG_GREEN1;
            }            
            if(is_button_press(DEC_BUTTON)){   
                SetTimer3_ms(return_auto_time*1000);
                counter1 = max_red1;
                counter2 = 0;
                traffic_status = CONFIG_RED1;
            }
            clear_button_flags();
            break;
        case CONFIG_GREEN1:
            turnOffCounter2();
            displayCounter1();
            setRoad1_green();
            setRoad2_blank();            
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                traffic_status = AUTO_RED_GREEN;
            }
            if(is_button_long_press(MODE_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MODE_CONFIG;
            }            
            if(is_button_press(MODE_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                SetTimer4_ms(500);
                traffic_status = CONFIG_GREEN1_ENTER;
            }
            if(is_button_press(INC_BUTTON)){   
                SetTimer3_ms(return_auto_time*1000);
                counter1 = 0;
                counter2 = max_green2;
                traffic_status = CONFIG_GREEN2;
            }
            if(is_button_press(DEC_BUTTON)){   
                SetTimer3_ms(return_auto_time*1000);
                counter1 = 0;
                counter2 = max_red2;
                traffic_status = CONFIG_RED2;
            }
            clear_button_flags();
            break;
        case CONFIG_GREEN2:
            turnOffCounter1();
            displayCounter2();
            setRoad1_blank();
            setRoad2_green();            
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                traffic_status = AUTO_RED_GREEN;
            }
            if(is_button_long_press(MODE_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MODE_CONFIG;
            }            
            if(is_button_press(MODE_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                SetTimer4_ms(500);
                traffic_status = CONFIG_GREEN2_ENTER;
            }            
            if(is_button_press(INC_BUTTON)){   
                SetTimer3_ms(return_auto_time*1000);
                counter1 = max_red1;
                counter2 = 0;
                traffic_status = CONFIG_TURN_AUTO;
            }
            if(is_button_press(DEC_BUTTON)){   
                SetTimer3_ms(return_auto_time*1000);
                counter1 = max_green1;
                counter2 = 0;
                traffic_status = CONFIG_GREEN1;
            }
            clear_button_flags();
            break;
        case CONFIG_RED1_ENTER:
            displayCounter1();
            if(timer4_flag){
                toggleRoad1_red();
                SetTimer4_ms(500);
            }
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                traffic_status = AUTO_RED_GREEN;
            }
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                counter1++;
                if(counter1 > 99) counter1 = 10;
            }
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                counter1--;
                if(counter1 < 10) counter1 = 99;
            }
            if(is_button_long_press(MODE_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                max_red1 = counter1;
                max_green2 = max_red1 - max_yellow2;
                traffic_status = CONFIG_RED1;
            }
            clear_button_flags();
            break;
        case CONFIG_RED2_ENTER:
            displayCounter2();
            if(timer4_flag){
                toggleRoad2_red();
                SetTimer4_ms(500);
            }            
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                traffic_status = AUTO_RED_GREEN;
            }
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                counter2++;
                if(counter2 > 99) counter2 = 10;
            }
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                counter2--;
                if(counter2 < 10) counter2 = 99;
            }
            if(is_button_long_press(MODE_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                max_red2 = counter2;
                max_green1 = max_red2 - max_yellow1;
                traffic_status = CONFIG_RED2;
            }
            clear_button_flags();            
            break;
        case CONFIG_GREEN1_ENTER:
            displayCounter1();
            if(timer4_flag){
                toggleRoad1_green();
                SetTimer4_ms(500);
            }            
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                traffic_status = AUTO_RED_GREEN;
            }
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                counter1++;
                if(counter1 > 96) counter1 = 7;
            }
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                counter1--;
                if(counter1 < 7) counter1 = 96;
            }
            if(is_button_long_press(MODE_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                max_green1 = counter1;
                max_red2 = max_green1 + max_yellow1;
                traffic_status = CONFIG_GREEN1;
            }
            clear_button_flags();
            break;
        case CONFIG_GREEN2_ENTER:
            displayCounter2();
            if(timer4_flag){
                toggleRoad2_green();
                SetTimer4_ms(500);
            }            
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                traffic_status = AUTO_RED_GREEN;
            }
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                counter2++;
                if(counter2 > 96) counter2 = 7;
            }
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                counter2--;
                if(counter2 < 7) counter2 = 96;
            }
            if(is_button_long_press(MODE_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                max_green2 = counter2;
                max_red1 = max_green2 + max_yellow2;
                traffic_status = CONFIG_GREEN2;
            }            
            clear_button_flags();
            break;
        case CONFIG_TURN_AUTO:            
            turnOffCounter1();
            turnOffCounter2();
            setRoad1_blank();
            setRoad2_blank();
            LcdPrintStringS(1,0,"RETURN AUTO:");
            display_time_out();
            counter1 = 0;
            counter2 = 0;
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                LcdPrintStringS(1,0,"                ");
                traffic_status = AUTO_RED_GREEN;
            }
            if(is_button_long_press(MODE_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                traffic_status = MODE_CONFIG;
            }            
            if(is_button_press(MODE_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                SetTimer4_ms(500);
                traffic_status = CONFIG_TURN_AUTO_ENTER;
            }            
            if(is_button_press(INC_BUTTON)){   
                SetTimer3_ms(return_auto_time*1000);
                counter1 = max_red1;
                counter2 = 0;
                LcdPrintStringS(1,0,"                ");
                traffic_status = CONFIG_RED1;
            }
            if(is_button_press(DEC_BUTTON)){   
                SetTimer3_ms(return_auto_time*1000);
                counter1 = 0;
                counter2 = max_green2;
                LcdPrintStringS(1,0,"                ");
                traffic_status = CONFIG_GREEN2;
            }
            clear_button_flags();
            break;
        case CONFIG_TURN_AUTO_ENTER:
            display_time_out();
            if(timer4_flag){
                toggle_time_out();
                SetTimer4_ms(500);
            }            
            if(timer3_flag == 1){
                SetTimer3_ms(1000);
                counter1 = max_red1;
                counter2 = max_green2;
                LcdPrintStringS(0,0,"   AUTO MODE    ");
                LcdPrintStringS(1,0,"                ");
                traffic_status = AUTO_RED_GREEN;
            }
            if(is_button_press(INC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                return_auto_time++;
                if(return_auto_time > 180) return_auto_time = 20;
            }
            if(is_button_press(DEC_BUTTON)){
                SetTimer3_ms(return_auto_time*1000);
                return_auto_time--;
                if(return_auto_time < 20) return_auto_time = 180;
            }
            if(is_button_long_press(MODE_BUTTON)){  
                SetTimer3_ms(return_auto_time*1000);
                SetTimer4_ms(500);
                traffic_status = CONFIG_TURN_AUTO;
            }            
            clear_button_flags();
            break;
        default:
            break;
    }
}