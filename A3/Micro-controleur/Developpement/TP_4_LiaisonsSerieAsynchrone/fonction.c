#include "fonction.h"
#include <xc.h>
#include "LCD.h"
#include <stdio.h>
#include <stdlib.h>
#define _XTAL_FREQ 11059200

/**Initialisation des parametres globaux pour le programme
 * no @param
 * no @return 
 */
void Init(void){
    // Obligatoire :Bus externe
    MEMCON = 0xA0;             //Address de l'EEPROM
    MEMCONbits.EBDIS = 0;      //Activation de l'EEPROM
        
    //Interruptions
    RCONbits.IPEN      = 0;    //Interruptions priorit�es a 1nv
    INTCONbits.PEIE    = 0;    //Interruptions peripheriques activ�es
    INTCONbits.GIE     = 1;    //Interruptions globales activ�es
    INTCONbits.INT0IE  = 1;    //Interruptions externes sur INTO activ�es
    INTCONbits.INT0IF  = 0;    //acquittement init
 
    // OBLIGATOIRE : D�sactivation des fonctions analogiques
    ANCON0 = 0x00;
    ANCON1 = 0x00;
    ANCON2 = 0x00;
    TRISD  = 0x00;         // 0 => PORTD en sortie
    TRISH  = 0xFF;         // 1 => PORTH en entr�e
    
    // OBLIGATOIRE : configuration de la liaison serie
    TRISG = 0x04;         // TX-G1 en sortie 0 et RX-G2 en entree 1
}

/**Initialisation des parametres de communications par liaisons serie UART
 * @param addr
 * @return 
 */
void Init_UART2(void){
    TXSTA2 = 0x20;  // Configuration de TX2 en sortie
    RCSTA2 = 0x90;  // Configuration de RX2 en entree
    
    BAUDCON2 = 0x00;
    
    SPBRGH2 = 0;
    SPBRG2 = 17;
}

/**Initialisation des ports d acces a la ressources epprom pour de la lecture
 * @param addr
 * @return 
 */
int Eeprom_read(unsigned char addr){
    // read initialisation sequence
    EEADR = addr;
    EECON1bits.EEPGD = 0;   // to access data EEPROM memory
    EECON1bits.CFGS = 0;    // to access data EEPROM memory
    EECON1bits.RD = 1;      // Initiates an EEPROM read
    
    // Boucle while car : Read takes one cycle and RD is cleared in hardware. 
    while(EECON1bits.RD);
    return EEDATA;
}


/**Initialisation des ports d acces a la ressources epprom pour de l ecriture
 * @param addr
 * @param data
 * @return 
 */
void Eeprom_write(unsigned char addr, unsigned char data){
    // write initialisation sequence
    EEADR = addr;
    EEDATA = data;
    EECON1bits.EEPGD = 0;   // to access data EEPROM memory
    EECON1bits.CFGS = 0;    // to access data EEPROM memory
    EECON1bits.WREN = 1;    // Allows write cycles to Flash program/data EEPROM
    INTCONbits.GIEH = 0;    // D�sactive interruption globale
    EECON2 = 0x55;          // Obligatoire
    EECON2 = 0xAA;          // Obligatoire
    EECON1bits.WR = 1;      // Initiate an EEPROM write
    
    // Boucle while car : Read takes one cycle and RD is cleared in hardware.
    while(EECON1bits.WR);
    
    EECON1bits.WREN = 0;    // Inhibits write cycles to Flash program/data EEPROM
    INTCONbits.GIEH = 1;    // active interruption globale
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
    SSP1ADD = 0x1A; // Baud rate pour I2C � 100kHz
}

/**Creation d une fonction delais en ms
 * @param val la valeur de duree a attendre
 * no @return 
 */
void delai_ms(unsigned char val){
/* Utilisation de la fonction temporisation delay_ms d�finie dans � xc.h �
__delay_ms( val) ;
*/
    for (int j=0;j<val;j++) {
        __delay_ms(1);
    }
}

