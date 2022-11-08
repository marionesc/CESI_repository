/* 
 * File:   screen_lcd.c
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
//#include "keyboard.h"
#include "screen_lcd.h"
#include "uart.h"
#include "CNA.h"

// DEFFINITION 
#define DISPLAY_CLEAR               0x01
#define RETURN_HOME                 0x02
#define ENTRY_MODE_SET_CI_DNS       0x06 //Cursor increase, is not shifted
#define ENTRY_MODE_SET_CI_DS        0x07 //Cursor increase, shifted
#define DISPLAY_ON_CUR_ON_BLINK_ON  0x0F
#define DISPLAY_ON_CUR_ON_BLINKOFF  0x0E
#define SHIFT_DISPLAY_RIGHT         0x1C
#define SHIFT_DISPLAY_LEFT          0x18
#define SHIFT_CURSOR_RIGHT          0x14
#define SHIFT_CURSOR_LEFT           0x10
#define SET_FUNC_8BIT_1LINE_5x10    0x3C
#define SET_FUNC_8BIT_2LINE_5x7     0x38

#define _XTAL_FREQ                  11059200

// GLOBAL VALUE
#define ASCII_CONVERSION_CONST      48

far unsigned char LCD_FUNC   @0x1A0000;
far unsigned char LCD_DATA   @0x1A0002;

//int calcul_value = 0;     // Pour pouvoir activer +/- sur le clavier


// INIT FUNCTION
/**
 * Initialisation du l ecran lcd avant utilisation
 * no @param
 * no @return
 */
void init_screen_lcd(void) {
    __delay_ms(10); LCD_FUNC = 0x38;
    __delay_ms(5);  LCD_FUNC = 0x38;
    __delay_ms(1);  LCD_FUNC = 0x38;
    __delay_ms(1);  LCD_FUNC = SET_FUNC_8BIT_2LINE_5x7;
    __delay_ms(1);  LCD_FUNC = SHIFT_CURSOR_RIGHT;
    __delay_ms(1);  LCD_FUNC = DISPLAY_ON_CUR_ON_BLINKOFF;
    __delay_ms(1);  LCD_FUNC = ENTRY_MODE_SET_CI_DNS;
    __delay_ms(1);  LCD_FUNC = RETURN_HOME;
    __delay_ms(2);  LCD_FUNC = DISPLAY_CLEAR;
    __delay_ms(2);
}


// FUNCTION
/** Acquisition --> AUCUNE IDEE PQ ??
 * no @param
 * no @return
 */
void acq(void) {
    while ((LCD_FUNC & 0x80) == 0x80);
}


/**
 * Set du DDram pour l'affichage LCD ????
 * @param addr
 * no @return
 */
void set_ddram(unsigned char addr) {
    LCD_FUNC = 0x40 & addr;
}

/**
 * Fonction permettant de réaliser une action de decalage ou de validation
 * @param keyboard
 * no @return
 */
void screen_action(unsigned char keyboard) {
    keyboard = keyboard & 0x0F; // & 0x0F : on ignore les 4 1er bits
    
    switch (keyboard) {
        // value 11 = -
        case 10 : break;    // value 10 = +
        case 11 : break;    // value 11 = -
        
        case 12 : // valeur touche < : décalage de 1 carac vers la gauche
            LCD_FUNC = SHIFT_CURSOR_LEFT;
            __delay_ms(2); acq();
            break;

        case 13 : // valeur touche > : décalage de 1 carac vers la droite
            LCD_FUNC = SHIFT_CURSOR_RIGHT;
            __delay_ms(2); acq();
            break;

        case 14 : // valeur touche AC : remise à O
            LCD_FUNC = DISPLAY_CLEAR;
            __delay_ms(2); acq();
            
            LCD_FUNC = RETURN_HOME;
            __delay_ms(2); acq();
            break;

        case 15 : // valeur touche entree
            LCD_FUNC = 0b0011000000;
            __delay_ms(2);
            acq();
            break;

        default :
            LCD_DATA = keyboard + 48; 
            acq();
            break;
    }
}

/**
 * Fonction permettant d'afficher un mot sur l ecran
 * @param word
 * no @return
 */
void screen_word_write(char *word) {
    int word_length = strlen(word);
    
    LCD_FUNC = DISPLAY_CLEAR;
    acq();
    if(word_length == 1){
        LCD_DATA = word;
        acq();
    }
    else{
        for(int j = 1; j < word_length; j++){
            LCD_DATA = word[j];
            acq();
        }
    }
}

/**
 * Fonction permettant l'affichage d un nombre sur l ecran
 * @param number
 * no @return
 */
void screen_number_write(int number){
    int i = 0;
    char number_string[10];
    LCD_FUNC = DISPLAY_CLEAR;
    acq();
    while (number > 0) {
        number_string[i] = number % 10 + 48;
        number = number / 10;
        i++;
    }
    for (i = i - 1; i >= 0; i--) {
        LCD_DATA = number_string[i];
        acq();
    }
}


/*//fonction pour ecrire un caractere a un emplacement de memoire dans le LCD
void writeLCD_mem(char c, int adresse){
    set_ddram(adresse);
    LCD_FUNC = 0x200 & char_to_ascii(c);
    acq();
}
*/