/* 
 * File:   keyboard.c
 * Author: marion Escouteloup & Clement CHABANIS
 * GitHub: maesc & 
 * compileur : xc8 V1_1.12
 * 
 * Created on 2022-11-3rd
 *      Last update : 2022-11-07
 */

// LIBRARY USED 
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

// GLOBAL VALUE
far unsigned char CLAV @0x180000;


// FUNCTION 
/** Lecture de la valeur du clavier
 * no @param
 * @return la valeur du clavier 
 */
unsigned char get_keyboard(){
    return ((CLAV && 0x0F) + 0x30); 
}
/**
 * Recuparation de la valeur entree sur le clavier numerique
 * no @param
 * no @return
 */
unsigned char  high_priority interrupt keyboard_int(void){
    unsigned char keyboard_value; 
    if((INTCONbits.INT0IF && INTCONbits.INT0IE) == 1){
        keyboard_value = get_keyboard();
        screen_word_write(keyboard_value);
        
        set_UART1(keyboard_value); 
        set_UART2(keyboard_value);
        
        INTCONbits.INT0IF = 0; 
    }
    return keyboard_value; 
}
/**
 * Configuration d une interruption des l appui sur une touche du clavier
 * no @param
 * no @return 
 */
/*
void high_priority interrupt get_val_clav (){ 
   screen_word_write(Clavier);
   INTCONbits.INT0IF = 0;
} */