/* 
 * File:   initialization.c
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


// GLOBAL VALUE
#define _XTAL_FREQ              11059200
#define ASCII_CONVERSION_CONST  48

// INIT FUNCTION   
/**Initialisation des parametres globaux pour le programme
 * no @param
 * no @return 
 */
void Init(void){
    // Obligatoire :Bus externe
    MEMCON = 0xA0;             //Address de l'EEPROM
    MEMCONbits.EBDIS = 0;      //Activation de l'EEPROM
        
    //Interruptions
    RCONbits.IPEN      = 0;    //Interruptions prioritées a 1nv
    INTCONbits.PEIE    = 0;    //Interruptions peripheriques activées
    INTCONbits.GIE     = 1;    //Interruptions globales activées
    INTCONbits.INT0IE  = 1;    //Interruptions externes sur INTO activées
    INTCONbits.INT0IF  = 0;    //acquittement init
 
    // OBLIGATOIRE : Désactivation des fonctions analogiques
    ANCON0 = 0x00;
    ANCON1 = 0x00;
    ANCON2 = 0x00;
    TRISD  = 0x00;         // 0 => PORTD en sortie
    TRISH  = 0xFF;         // 1 => PORTH en entrée
    
    // OBLIGATOIRE : configuration de la liaison serie
    TRISGbits.TRISG2 = 1;
}


/**Initialisation du bus de com. I2C
 * no @param 
 * no @return 
 */
void I2C_Init(void){
    SSP1STAT = 0x00;
    SSP1CON1 = 0x00;
    SSP1CON1bits.SSPEN = 1; // Enables the serial port and configures the SDAx and SCLx pins as the serial port pins
    SSP1CON1bits.SSPM = 0x08; // 1000 = I2C Master mode
    SSP1CON2 = 0x00;
    SSP1ADD = 0x1A; // Baud rate pour I2C à 100kHz
}

/**
 * Initialisation des parametres pour les interruptions
 * no @param
 * no @return
 */
void Init_interuption(void){
    INTCON = 0x00;
    INTCONbits.PEIE_GIEL = 1;
    INTCONbits.GIE_GIEH = 1;
    INTCONbits.INT0E = 1;
}

/**
 * 
 * 
 * Débordement timer toutes les sec (prescaler =7200): 
 * autoreload = (Ttimer / (Tclock x precaler)) - 1
 * 
 * --> autoreload 7200 --> timer 16bits 
 */
void Init_timer0(void){
    T0CONbits.T08BIT = 0;   // timer configure en 16 bits
    T0CONbits.T0CS = 0;     // Clock interne
    T0CONbits.T0SE = 0;     // Incrementation low to high
    T0CONbits.PSA = 0;      // Assignation du prescaler
    T0CONbits.T0PS = 0b111; // Prescaler 1:256
  
    INTCONbits.TMR0IE = 1;  // enable timer0 interrupt
    INTCONbits.TMR0IF = 0;  // clear timer0 interrupt flag
    INTCONbits.GIE = 1;     // enable global interrupts
    
}

// ADDITIONAL FUNCTION
/**Creation d une fonction delais en ms
 * @param val la valeur de duree a attendre
 * no @return 
 */
void delai_ms(unsigned char val){
/* Utilisation de la fonction temporisation delay_ms définie dans « xc.h »
__delay_ms( val) ;
*/
    for (int j = 0; j < val ; j++) {
        __delay_ms(1);
    }
}

/**
 * Fonction realisant la conversion d'une valeur ASCII en symbole reel
 * @param data
 * @return 
 */
char char_to_ascii(char data){
    return (data + ASCII_CONVERSION_CONST);
}


//fonction de conversion d'echelle :
/**
 *
 * @param min_ech
 * @param max_ech
 * @param min_aff
 * @param max_aff
 * @param value
 * @return 
 */
int conversion_echelle(int min_ech,int max_ech,int min_aff,int max_aff,int value){
    return (((max_aff - min_aff)  / (max_ech - min_ech))*value);
}

/*** TIMER 0 ***/
/**
 * Lancement du timer 0
 * no @param
 * no @return
 */
void start_timer0(void){
    T0CONbits.TMR0ON = 1;
}

/**
 * Arret du timer 0
 * no @param
 * no @return
 */
void stop_timer0(void){
    T0CONbits.TMR0ON = 0;
}

/**
 * Lecture de la valeur du timer en ??
 * @return TMR0L la durée du timer 
 */
int lecture_timer0(void){
    return TMR0L; 
}

/**
 * Reset de la valeur du timer en memoire
 */
void reset_timer0(void){
    TMR0L = 0;
}


/**** FAN ****/
// void set_fan(int rpm) --> vitesse de rotation du fan
// int  get_fan() --> lit la vitesse reelle du fan 

