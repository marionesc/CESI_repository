/* 
 * File:   eeprom.c
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

// EEPROM FUNCTION
/**Initialisation des ports d acces a la ressources epprom pour de la lecture
 * @param addr
 * @return 
 */
int read_eeprom(unsigned char addr){
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
void write_eeprom(unsigned char addr, unsigned char data){
    // write initialisation sequence
    EEADR = addr;
    EEDATA = data;
    EECON1bits.EEPGD = 0;   // to access data EEPROM memory
    EECON1bits.CFGS = 0;    // to access data EEPROM memory
    EECON1bits.WREN = 1;    // Allows write cycles to Flash program/data EEPROM
    INTCONbits.GIEH = 0;    // Désactive interruption globale
    EECON2 = 0x55;          // Obligatoire
    EECON2 = 0xAA;          // Obligatoire
    EECON1bits.WR = 1;      // Initiate an EEPROM write
    
    // Boucle while car : Read takes one cycle and RD is cleared in hardware.
    while(EECON1bits.WR);
    
    EECON1bits.WREN = 0;    // Inhibits write cycles to Flash program/data EEPROM
    INTCONbits.GIEH = 1;    // active interruption globale
}

