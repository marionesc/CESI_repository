
#include <xc.h>
#include "CNA.h"

/*
 * Programmation des fonction Conversion Analogique/Digital et Digital/Analogique
 */

//fonction de conversion analogique/digital via les bus I2C
unsigned char ADC_read(int channel){
    //configuration de l'entr�e analogique
    ADCON0bits.ADON = 0; //d�sactivation du module ADC
    ADCON0bits.CHS = channel; //choix du canal
    ADCON0bits.ADON = 1; //activation du module ADC
    //lecture de l'entr�e analogique
    ADCON0bits.GO = 1; //activation de la conversion
    while(ADCON0bits.GO); //attente de la fin de la conversion
    //desactivation du module ADC
    ADCON0bits.DONE = 0; //d�sactivation de la conversion
    ADCON0bits.ADON = 0; //d�sactivation du module ADC
    return ADRESH; //retour de la valeur de l'entr�e analogique
}

//fonction de conversion digital/analogique via le bus I2C
void DAC_write(unsigned char value) {
    SSP1CON2bits.SEN = 1; // Envoi du bit de start
    while (PIR1bits.SSP1IF == 0) {}
    PIR1bits.SSP1IF = 0;
    SSP1BUF = 0x90; // adresse du convertisseur dig/ana
    while (SSP1CON2bits.ACKSTAT == 1) {}; // tant que acquittement du convertisseur non re�u
    while (PIR1bits.SSP1IF == 0) {}
    PIR1bits.SSP1IF = 0;
    SSP1BUF = 0x40; // bits de contr�le
    while (SSP1CON2bits.ACKSTAT == 1) {}; // tant que acquittement du convertisseur non re�u
    while (PIR1bits.SSP1IF == 0) {}
    PIR1bits.SSP1IF = 0;
    SSP1BUF = value; // bits de do
    nn�es 0 � 255
    while (SSP1CON2bits.ACKSTAT == 1) {}; // tant que acquittement du convertisseur non re�u
    while (PIR1bits.SSP1IF == 0) {}
    PIR1bits.SSP1IF = 0;
    SSP1CON2bits.PEN = 1; // Envoi du bit de stop
    while (PIR1bits.SSP1IF == 0) {}
    PIR1bits.SSP1IF = 0;
}
