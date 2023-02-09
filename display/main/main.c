/* 
 * File:   main.c
 * Author: phamv
 *
 * Created on February 9, 2023, 10:46 PM
 */

#include "main.h"

#include "global/global.h"

void delay_ms(int value);
void init_system();

void main(){
    init_system();
//    SetTimer3_ms(2000);
    while(1){
        toggleLed(0);
        delay_ms(50);
//        if(timer3_flag == 1){
//            toggleLed(0);
//            SetTimer3_ms(2000);
//        }
    }
}

void init_system(){
    TRISB = 0x00;
    led_init();
//    init_interrupt();
    delay_ms(1000);
//    init_timer0(4695);  //dinh thoi 1ms
//    init_timer1(9390);  //dinh thoi 2ms
//    init_timer3(46950); //dinh thoi 10ms
}

void delay_ms(int value){
    int i,j;
	for(i=0;i<value;i++){
		for(j=0;j<238;j++);
    }
}

