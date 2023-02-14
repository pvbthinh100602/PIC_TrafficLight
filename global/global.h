/* 
 * File:   global.h
 * Author: phamv
 *
 * Created on February 5, 2023, 3:13 PM
 */

#ifndef GLOBAL_H
#define	GLOBAL_H

#include <p18f4620.h>

#include "display/display.h"
#include "timer/timer.h"
#include "interrupt/interrupt.h"
#include "button/button.h"
#include "lcd/lcd.h"

#define INIT 0

#define AUTO_RED_GREEN      1
#define AUTO_RED_YELLOW     2
#define AUTO_GREEN_RED      3
#define AUTO_YELLOW_RED   4

#define MAN_RED_GREEN   11
#define MAN_RED_YELLOW  12
#define MAN_GREEN_RED   13
#define MAN_YELLOW_RED    14

#define SET_RED1    21
#define SET_GREEN1  22
#define SET_RED2    23
#define SET_GREEN2  24

#define SLOWDOWN    30

#define MODE_BUTTON 3
#define INC_BUTTON  7

extern unsigned char traffic_status;

extern unsigned char counter1;
extern unsigned char counter2;

extern unsigned char max_red1;
extern unsigned char max_red2;
extern unsigned char max_yellow1;
extern unsigned char max_yellow2;
extern unsigned char max_green1;
extern unsigned char max_green2;
        
#endif	/* GLOBAL_H */

