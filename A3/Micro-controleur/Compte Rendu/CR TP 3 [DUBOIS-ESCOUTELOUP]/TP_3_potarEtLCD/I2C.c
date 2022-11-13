/*
 * File:    I2C.c
 * Author:  damien DUBOIS
 *          MArion ESCOUTELOUP (GitHub : maresc)
 *
 */

/** LIBRAIRIES UTILISEES */
#include <xc.h>

/** VARIABLE GLOBALE DE REFERENCE **/

/** INITIALISATION DES FONCTIONS **/
/**
 * Cette fonction permet l'initialisation du bus I2C 
 *  no @param
 *  no @return
 */
void I2C_Init(void){
    SSP1STAT = 0x00;
    SSP1CON1 = 0x00;
    SSP1CON1bits.SSPEN = 1;     // Enables the serial port and configures the SDAx and SCLx pins as the serial port
    SSP1CON1bits.SSPM = 0x08;   // 1000 = I2C Master mode
    SSP1CON2 = 0x00;
    SSP1ADD = 0x1A;             // Baud rate pour I2C à 100kHz
}

/**
 * Cette fonction lance la convertion vers le CNA d'une valeur
 *  @param VAL : valeur à convertir 
 *  no @return
 */
void envoi_CNA(unsigned char VAL){
    SSP1CON2bits.SEN = 1;       //Envoi du bit de start
    while(PIR1bits.SSP1IF == 0){}
    PIR1bits.SSP1IF = 0;
    SSP1BUF = 0x90;             //adresse du convertisseur dig/ana
    
    while(SSP1CON2bits.ACKSTAT == 1){}; 
    // tant que acquittement du convertisseur non reçu
    while(PIR1bits.SSP1IF == 0){}
    PIR1bits.SSP1IF = 0;
    SSP1BUF = 0x40;             //bits de contrôle
    
    while(SSP1CON2bits.ACKSTAT == 1){}; 
    // tant que acquittement du convertisseur non reçu
    while(PIR1bits.SSP1IF == 0){}
    PIR1bits.SSP1IF = 0;
    SSP1BUF = VAL ;             // bits de données 0 à 255
    
    while(SSP1CON2bits.ACKSTAT == 1){}; 
    // tant que acquittement du convertisseur non reçu
    while(PIR1bits.SSP1IF == 0){}
    PIR1bits.SSP1IF = 0;
    SSP1CON2bits.PEN = 1;       // Envoi du bit de stop
    
    while(PIR1bits.SSP1IF == 0){}
    PIR1bits.SSP1IF = 0;
}