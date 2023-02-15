/* 
 * File:   button.h
 * Author: phamv
 *
 * Created on February 5, 2023, 3:19 PM
 */

#ifndef BUTTON_H
#define	BUTTON_H

#include "global/global.h"

#define PORT_BUTTON		PORTC
#define TRIS_BUTTON		TRISC
#define	MAX_COL			4
#define MAX_ROW			4

extern unsigned int key_code[];
extern unsigned int long_key_flag[];
unsigned char is_button_press(unsigned char index);
unsigned char is_button_long_press(unsigned char index);
void init_key_matrix();
void scan_key_matrix();
//void button_process();

#endif	/* BUTTON_H */

