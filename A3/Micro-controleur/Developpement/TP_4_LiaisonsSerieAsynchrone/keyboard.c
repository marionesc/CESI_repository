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
/**
 * Recuparation de la valeur entree sur le clavier numerique
 * no @param
 * @return keyboard_value la valeur ASCII convertie en valeur reelle
 */
unsigned char  high_priority interrupt get_keyboard(void){
    unsigned char keyboard_value = (CLAV & 0x0F) + 0x30;
    screen_word_write(keyboard_value);
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