/* 
 * File:   timer.h
 * Author: phamv
 *
 * Created on February 5, 2023, 3:26 PM
 */

#ifndef TIMER_H
#define	TIMER_H

#include <p18f4620.h>

void init_interrupt(void);
void init_ext_int0(void);
void low_isr(void);
void high_isr(void);

#endif	/* TIMER_H */

