/* 
 * File:   main.c
 * Author: mario
 *
 * Created on 6 juillet 2022, 16:13
 */

//compileur : xc8
#include "fonction.h"
#include <xc.h>
#include "LCD.h"
#include "clav.h"
#include "CNA.h"
#include "get_keyboard.h"
#include "uart.h"
#include "interruption.h"


#define _XTAL_FREQ 11059200

// GLOBAL VALUE
unsigned char keyboard_value;
int keyboard_flag = 0;

void main(void) {
    Init();
    init_aff_lcd();
    Init_UART2();
    Init_interruption();
    
    acq();
    I2C_Init();
    while (1) {
        if (keyboard_flag == 1){
            TXREG2 = get_keyboard_f();
            aff_lcd(0x05);
            keyboard_flag = 0;
        }
    }
}

