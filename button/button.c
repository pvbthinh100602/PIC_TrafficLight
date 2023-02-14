#include "button.h"

#define PRESS_SIGNAL 0
#define RELEASE_SIGNAL 1

#define PRESS_STATE  1
#define RELEASE_STATE  0
#define LONG_PRESS_STATE  2

unsigned int key_flag[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//unsigned char arrayMaskOutputOfKey [8] = {0x80,0x40,0x20,0x10,0x01,0x02,0x04,0x08};
//unsigned char arrayMaskInputOfKey [8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
unsigned char arrayMaskOutputOfKey [4] = {0x10,0x20,0x40,0x80};
unsigned char arrayMaskInputOfKey [4] = {0x01,0x02,0x04,0x08};
static unsigned char d1[16];
static unsigned char d2[16];
static unsigned char button_buffer[16];
unsigned char button_state[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char button_counter[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

unsigned char is_button_press(unsigned char index){
    if(key_flag[index] == 1){
        key_flag[index] = 0;
        return 1;
    }
    return 0;
}


void button_process(unsigned int index){
    switch(button_state[index]){
        case PRESS_STATE:
            button_counter[index]++;
            if(button_buffer[index] == RELEASE_SIGNAL){
                button_state[index] = RELEASE_STATE;
                button_counter[index] = 0;
            }
            if(button_counter[index] == 100){
                button_state[index] = LONG_PRESS_STATE;
                key_flag[index] = 1;
                button_counter[index] = 0;
            }
            break;
        case RELEASE_STATE:
            if(button_buffer[index] == PRESS_SIGNAL){
                button_state[index] = PRESS_STATE;
                key_flag[index] = 1;
            }
            break;
        case LONG_PRESS_STATE:
            button_counter[index]++;
            if(button_buffer[index] == RELEASE_SIGNAL){
                button_state[index] = RELEASE_STATE;
                button_counter[index] = 0;
            }
            if(button_counter[index] >= 200){
                key_flag[index] = 1;
                button_counter[index] = 0;
            }
            break;
        default:
            break;
    }
}

void init_key_matrix()
{
	TRIS_BUTTON = 0x0f; 
	PORT_BUTTON = 0xff;
}

void scan_key_matrix()
{
	int i,j;
	for(i=0;i<MAX_ROW;i++)     
	{
		PORT_BUTTON = ~arrayMaskOutputOfKey[i];
		for(j=0;j<MAX_COL;j++)
		{ 
            d1[i*MAX_COL+j] = d2[i*MAX_COL+j];
            d2[i*MAX_COL+j] = (PORT_BUTTON & arrayMaskInputOfKey[j]) >> j;
            if(d1[i*MAX_COL+j] == d2[i*MAX_COL+j]){
                button_buffer[i*MAX_COL+j] = d1[i*MAX_COL+j];
                button_process(i*MAX_COL+j);
            }
		}
	}
}