#include "main.h"

void delay_ms(int value);
void init_system();

void main(){
    init_system();
    SetTimer1_ms(1000);
    while(1){
        if(timer1_flag == 1){
            toggleLed(0);
            SetTimer1_ms(1000);
        }
    }
}

void init_system(){
    TRISB = 0x00;
    led_init();
    init_interrupt();
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