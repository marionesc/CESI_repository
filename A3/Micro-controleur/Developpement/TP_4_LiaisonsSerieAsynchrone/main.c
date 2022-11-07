/* 
 * File:   main.c
 * Author: marion Escouteloup & Clement CHABANIS
 * GitHub: maesc & 
 * compileur : xc8 V1_1.12
 * 
 * Created on 2022-11-3rd
 *      Last update : 2022-11-07
 */

//LIBRARY USED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xc.h>

#include "initialization.h"
#include "eeprom.h"
#include "keyboard.h"
#include "screen_lcd.h"
#include "uart.h"
#include "CNA.h"

//DEFFINITION 
#define _XTAL_FREQ 11059200

//GLOBAL VALUE
unsigned char keyboard_value;
int keyboard_flag = 0;

//MAIN PROGRAM
void main(void) {
    Init();
    Init_interuption(); 
    Init_UART1();
    Init_UART2(); 
    
    while (1) {
        }
    }
