#include "fonction.h"
#include <xc.h>
#include "LCD.h"
#include <stdio.h>
#include <stdlib.h>
#define _XTAL_FREQ 11059200
void Init(void){
 // Obligatoire :Bus externe
 MEMCON=0xA0; //Address de l'EEPROM
 MEMCONbits.EBDIS = 0; //Activation de l'EEPROM
 //Iterruptions
 RCONbits.IPEN = 0; //Interruptions prioritées a 1nv
 INTCONbits.PEIE = 0; //Interruptions peripheriques activées
 INTCONbits.GIE = 1; //Interruptions globales activées
 INTCONbits.INT0IE = 1; //Interruptions externes sur INTO activées
 INTCONbits.INT0IF = 0; //acquittement init
// Obligatoire : Désactivation des fonctions analogiques
 ANCON0=0x00;
 ANCON1=0x00;
 ANCON2=0x00;
 TRISD=0x00; // 0 => PORTD en sortie
 TRISH=0xFF; // 1 => PORTH en entrée
 TRISG=0x00;

}
int Eeprom_read(unsigned char addr){
    // read initialisation sequence
    EEADR = addr;
    EECON1bits.EEPGD = 0; // to access data EEPROM memory
    EECON1bits.CFGS = 0; // to access data EEPROM memory
    EECON1bits.RD = 1; // Initiates an EEPROM read
    
    // Boucle while car : Read takes one cycle and RD is cleared in hardware. 
    while(EECON1bits.RD);
    
    return EEDATA;
}
void Eeprom_write(unsigned char addr, unsigned char data){
    // write initialisation sequence
    EEADR = addr;
    EEDATA = data;
    EECON1bits.EEPGD = 0; // to access data EEPROM memory
    EECON1bits.CFGS = 0; // to access data EEPROM memory
    EECON1bits.WREN = 1; // Allows write cycles to Flash program/data EEPROM
    INTCONbits.GIEH = 0; // Désactive interruption globale
    EECON2 = 0x55; // Obligatoire
    EECON2 = 0xAA; // Obligatoire
    EECON1bits.WR = 1; // Initiate an EEPROM write
    
    // Boucle while car : Read takes one cycle and RD is cleared in hardware.
    while(EECON1bits.WR);
    
    EECON1bits.WREN = 0; // Inhibits write cycles to Flash program/data EEPROM
    INTCONbits.GIEH = 1; // active interruption globale
}
void I2C_Init(void)
{
    SSP1STAT = 0x00;
    SSP1CON1 = 0x00;
    SSP1CON1bits.SSPEN = 1; // Enables the serial port and configures the SDAx and SCLx pins as the serial port pins
    SSP1CON1bits.SSPM = 0x08; // 1000 = I2C Master mode
    SSP1CON2 = 0x00;
    SSP1ADD = 0x1A; // Baud rate pour I2C à 100kHz
}
void delai_ms(unsigned char val){
/* Utilisation de la fonction temporisation delay_ms définie dans « xc.h »
__delay_ms( val) ;
*/
    for (int j=0;j<val;j++) {
        __delay_ms(1);
    }
}
