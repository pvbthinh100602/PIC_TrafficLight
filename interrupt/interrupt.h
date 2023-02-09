/* 
 * File:   interrupt.h
 * Author: phamv
 *
 * Created on February 5, 2023, 3:24 PM
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include "global/global.h"

void init_interrupt(void);
void init_ext_int0(void);
void low_isr(void);
void high_isr(void);

#endif	/* INTERRUPT_H */

