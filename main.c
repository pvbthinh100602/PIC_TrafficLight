#include "main.h"

void init_system();

void main(){
    init_system();
    LED = 0x01;
    while(1){
        LED = ~LED;
        delay_ms(500);
    }
}

void init_system(){
    TRISB = 0x00;
    delay_ms(1000);
}

void delay_ms(int value){
    int i,j;
	for(i=0;i<value;i++){
		for(j=0;j<238;j++);
    }
}