/* 
 * File:   CNA.c
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

/*
 * Programmation des fonction Conversion Analogique/Digital et Digital/Analogique
 */

//fonction de conversion analogique/digital via les bus I2C
unsigned char ADC_read(int channel){
    //configuration de l'entrée analogique
    ADCON0bits.ADON = 0; //désactivation du module ADC
    ADCON0bits.CHS = channel; //choix du canal
    ADCON0bits.ADON = 1; //activation du module ADC
    //lecture de l'entrée analogique
    ADCON0bits.GO = 1; //activation de la conversion
    while(ADCON0bits.GO); //attente de la fin de la conversion
    //desactivation du module ADC
    ADCON0bits.DONE = 0; //désactivation de la conversion
    ADCON0bits.ADON = 0; //désactivation du module ADC
    return ADRESH; //retour de la valeur de l'entrée analogique
}

//fonction de conversion digital/analogique via le bus I2C
/*
void DAC_write(unsigned char value) {
    SSP1CON2bits.SEN = 1;                        // Envoi du bit de start
    while (PIR1bits.SSP1IF == 0) {}
    PIR1bits.SSP1IF = 0;
    SSP1BUF = 0x90;                             // adresse du convertisseur D-A
    
    while (SSP1CON2bits.ACKSTAT == 1) {};       // tant que acquittement du convertisseur non reçu
    while (PIR1bits.SSP1IF == 0) {}
    PIR1bits.SSP1IF = 0;
    SSP1BUF = 0x40;                             // bits de contrôle
    
    while(SSP1CON2bits.ACKSTAT == 1){};       // tant que acquittement du convertisseur non reçu
    while(PIR1bits.SSP1IF == 0){};
    PIR1bits.SSP1IF = 0;
    SSP1BUF = value;                            // bits de données 0 à 255
    
    while (SSP1CON2bits.ACKSTAT == 1){};       // tant que acquittement du convertisseur non reçu
    while (PIR1bits.SSP1IF == 0){};
    PIR1bits.SSP1IF = 0;
    SSP1CON2bits.PEN = 1;                       // Envoi du bit de stop
    while (PIR1bits.SSP1IF == 0) {}
    PIR1bits.SSP1IF = 0;
}
*/