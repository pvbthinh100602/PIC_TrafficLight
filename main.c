#include "main.h"
#include "lcd/lcd.h"
#include "fsm/fsm.h"
#include "pwm/pwm.h"

void delay_ms(int value);
void init_system();

void main(){
    init_system();
    while(1){
//        LcdClearS();
        fsm_mode();
        fsm_auto();
        fsm_man();
        fsm_config();
        buzz();
        DisplayLcdScreen();
    }
}

void init_system(){
    TRISB = 0x00;
    init_lcd();
    init_interrupt();
    init_key_matrix();
    init_pwm();
    init_timer0(4695);  //dinh thoi 1ms 
    init_timer1(9390);  //dinh thoi 2ms
	init_timer3(46950); //dinh thoi 10ms
    delay_ms(1000);
}

void delay_ms(int value){
    int i,j;
	for(i=0;i<value;i++){
		for(j=0;j<238;j++);
    }
}