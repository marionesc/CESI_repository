/*
 * File:    CAN.c
 * Author:  damien DUBOIS
 *          MArion ESCOUTELOUP (GitHub : maresc)
 *
 */

/** LIBRAIRIES UTILISEES */
#include <xc.h>
#include "user.h"

/** VARIABLE GLOBALE DE REFERENCE **/

/** INITIALISATION DES FONCTIONS **/
/**
 * Cette fonction permet l'initialisation le CAN 
 *  no @param
 *  no @return
 */
void init_can(void){
    ANCON0bits.ANSEL0 = 1;
    ADCON1bits.VCFG0 = 0;
    ADCON2bits.ADFM = 1;        // Resulst format 1= Right justified
    ADCON2bits.ACQT = 0b011;    // Acquition time 7 = 20TAD 2 = 4TAD 1=2TAD
    ADCON2bits.ADCS = 0b101;    //Clock conversion bits 6= FOSC/64 2=FOSC/32
    ADCON0bits.ADON=1;          // Turn on ADC
}

/**
 * Cette fonction permet de lire la valeur de l'ADC 
 *  no @param
 *  @return VAL_ADC : valeur lu sur l'ADC
 */
 unsigned int read_adc(void){
     unsigned char CAN_H;
     unsigned char CAN_L;
     unsigned int VAL_ADC;
     
     ADCON0bits.GO_nDONE =1;
     
     while(ADCON0bits.GO_nDONE);
     CAN_H = ADRESH;
     CAN_L =  ADRESL;       
     
     VAL_ADC = (CAN_H<<8) + CAN_L;
     
	return VAL_ADC;
} 

