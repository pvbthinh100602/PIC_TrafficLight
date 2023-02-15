/* 
 * File:   timer.h
 * Author: phamv
 *
 * Created on February 5, 2023, 3:26 PM
 */

#ifndef TIMER_H
#define	TIMER_H

#include "global/global.h"

void init_timer0(unsigned int count);
void start_timer0(void);
void stop_timer0(void);
void init_timer1(unsigned int count);
void start_timer1(void);
void stop_timer1(void);
void init_timer2(unsigned char count);
void start_timer2(void);
void stop_timer2(void);
void init_timer3(unsigned int count);
void start_timer3(void);
void stop_timer3(void);

void timer0_isr(void);
void timer1_isr(void);
void timer2_isr(void);
void timer3_isr(void);
// xay dung ham cap cao cho timer, nhung ham se duoc lop user goi
void SetTimer0_ms(int time);
void SetTimer1_ms(int time);
void SetTimer3_ms(int time);
void SetTimer4_ms(int time);


extern unsigned char timer0_flag, timer1_flag, timer2_flag, timer3_flag, timer4_flag;
#endif	/* TIMER_H */

