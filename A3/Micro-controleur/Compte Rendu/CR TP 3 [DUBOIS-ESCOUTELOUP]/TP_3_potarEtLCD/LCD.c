/*
 * File:    LCD.c
 * Author:  damien DUBOIS
 *          MArion ESCOUTELOUP (GitHub : maresc)
 *
 */

/** LIBRAIRIES UTILISEES */
#include <xc.h>
#include "user.h"

/** VARIABLE GLOBALE DE REFERENCE **/
//far unsigned char CLAVIER @ 0x180000 ;
//far unsigned char LCD_DATA @ 0x1A0002 ;
//far unsigned char LCD_FUNC @ 0x1A0000 ;

/** INITIALISATION DES FONCTIONS **/
/**
 * Cette fonction permet l'initialisation del'afficheur LCD 
 *  no @param
 *  no @return
 * 
 * en mode use_clav()
 */
void init_aff_lcd(void){
    delai_ms(100);
    LCD_FUNC = 0x38; delai_ms(5);
    LCD_FUNC = 0x38; delai_ms(1);
    LCD_FUNC = 0x38; delai_ms(1);
    LCD_FUNC = SET_FUNC_8BIT_2LINE_5x7; delai_ms(1);
    LCD_FUNC = SHIFT_CURSOR_RIGHT; delai_ms(1);
    LCD_FUNC = DISPLAY_ON_CUR_ON_BLINKOFF; delai_ms(1);
    LCD_FUNC = ENTRY_MODE_SET_CI_DNS; delai_ms(1);
    LCD_FUNC = RETURN_HOME; delai_ms(2);
    LCD_FUNC = DISPLAY_CLEAR; delai_ms(2);
}

/**
 * Cette fonction permet  
 *  no @param
 *  no @return
 */
void LCD_busy (void){
    delai_ms(10);
    while((LCD_FUNC & 0x80) == 0x80);
}

/**
 * Cette fonction permet d'afficher un caractere ou une chaine de caractere
 * sur l'afficheur LCD
 *  @param carac le(s) caractere(s) à afficher
 *  no @return
 */
void lcd_print (unsigned char carac){
    LCD_DATA = carac ;
    LCD_busy();
}

/**
 * Cette fonction permet de nettoyer et d'effacer l'afficheur LCD
 *  no @param
 *  no @return
 */
void LCD_Clear (void){
    LCD_FUNC = DISPLAY_CLEAR;
    LCD_busy();
}

/**
 * Cette fonction permet d'afficher un nombre sur l'afficheur LCD 
 *  @param nombre le chiffre à afficher
 *  no @return
 */
void AffichNombre( unsigned int nombre){
    unsigned char millier = 0;
    unsigned char unites = 0;
    unsigned char dizaines = 0;
    unsigned char centaines = 0;
    unsigned short tampon = 0;
    LCD_Clear();
    
    /* CONVERSION */
    millier = nombre /1000;
    tampon = nombre%1000;
    centaines = tampon /100;
    tampon = nombre %100;
    dizaines = tampon/10;
    unites = tampon%10; 
    
    lcd_print (millier+0x30);
    
    lcd_print (0x2E);
    
    lcd_print (centaines+0x30);

    lcd_print (dizaines+0x30);
    
    lcd_print (unites+0x30);
    
    
    LCD_FUNC = RETURN_HOME;
    /* AFFICHAGE */
    return;
}