/* 
 * File:   display.h
 * Author: phamv
 *
 * Created on February 5, 2023, 3:20 PM
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#include "global/global.h"

#define LED PORTB

void led_init();
void turnLedOn(unsigned char index);
void turnLedOff(unsigned char index);
void toggleLed(unsigned char index);

#endif	/* DISPLAY_H */

