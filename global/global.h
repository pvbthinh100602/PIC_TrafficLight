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

#define MODE_AUTO   1
#define MODE_MAN    2
#define MODE_SLOW   3
#define MODE_CONFIG    4

#define AUTO_RED_GREEN      11
#define AUTO_RED_YELLOW     12
#define AUTO_GREEN_RED      13
#define AUTO_YELLOW_RED     14

#define AUTO_RED_GREEN_SETUP      111
#define AUTO_RED_YELLOW_SETUP     121
#define AUTO_GREEN_RED_SETUP      131
#define AUTO_YELLOW_RED_SETUP     141

#define MAN_SETUP       20
#define MAN_RED_GREEN   21
#define MAN_RED_YELLOW  22
#define MAN_GREEN_RED   23
#define MAN_YELLOW_RED  24

#define AUTO_SLOW    31

#define CONFIG_RED1    41
#define CONFIG_GREEN1  42
#define CONFIG_RED2    43
#define CONFIG_GREEN2  44
#define CONFIG_TURN_AUTO  51


#define CONFIG_RED1_ENTER    45
#define CONFIG_GREEN1_ENTER  46
#define CONFIG_RED2_ENTER    47
#define CONFIG_GREEN2_ENTER  48
#define CONFIG_TURN_AUTO_ENTER  52

#define MODE_BUTTON 11
#define INC_BUTTON  3
#define DEC_BUTTON  7

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

