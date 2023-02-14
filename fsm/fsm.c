#include "fsm.h"

void fsm_auto(){
    switch(traffic_status){
        case INIT:
            SetTimer3_ms(1000);
            counter1 = max_red1;
            counter2 = max_green2;
            traffic_status = AUTO_RED_GREEN;
            break;
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
                SetTimer3_ms(18000);
                traffic_status = MAN_RED_GREEN;
                counter1 = 0;
                counter2 = 0;
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
                SetTimer3_ms(18000);
                traffic_status = MAN_RED_YELLOW;
                counter1 = 0;
                counter2 = 0;
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
                SetTimer3_ms(18000);
                traffic_status = MAN_GREEN_RED;
                counter1 = 0;
                counter2 = 0;
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
                SetTimer3_ms(18000);
                traffic_status = MAN_YELLOW_RED;
                counter1 = 0;
                counter2 = 0;
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
                SetTimer3_ms(18000);
                traffic_status = MAN_RED_YELLOW;
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
                SetTimer3_ms(18000);
                traffic_status = MAN_GREEN_RED;
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
                SetTimer3_ms(18000);
                traffic_status = MAN_YELLOW_RED;
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
                SetTimer3_ms(18000);
                traffic_status = MAN_RED_GREEN;
            }            
            break;            
    }
}