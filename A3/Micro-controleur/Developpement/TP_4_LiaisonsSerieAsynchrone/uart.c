/* 
 * File:   uart.c
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


// GLOBAL VALUE
extern unsigned char keyboard_value;
extern int keyboard_flag;

// UART 1 PORT FUNCTION
/**Initialisation des parametres de communications par liaisons serie UART
 * @param addr
 * @return 
 */
void Init_UART1(void){
    TXSTA1 = 0x20;  // Configuration de TX2 en sortie
    RCSTA1 = 0x90;  // Configuration de RX2 en entree
    
    BAUDCON1 = 0x00;
    
    SPBRGH1 = 0;
    SPBRG1 = 17;
}

/**Envoie d un message via le port serie UART1
 * @param set_message le message a envoye
 * no @return
 */
void set_UART1(unsigned char set_message){
    while(TX1IF == 0);
    TXREG1 = set_message;
}

/**Envoie d un message via le port serie UART1 hyper
 * @param set_message le message a envoye
 * no @return
 */
void set_UART1_hyper(unsigned char set_message){
    if (set_message != 0x00){
        set_UART1(set_message);
    }
}



// UART 2 PORT FUNCTION
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


/**Envoie d un message via le port serie UART
 * @param set_message le message a envoye
 * no @return
 */
void set_UART2(unsigned char set_message){
    while(TX1IF == 0);
    TXREG2 = set_message;
}

/**Envoie d un message via le port serie UART au PC
 * @param set_message le message a envoye
 * no @return
 */
void set_UART2_pc(unsigned char set_message){
    if (set_message != 0x00){
        set_UART2(set_message);
    }
}

void keyboard_treatment(void){
    unsigned char data;
    if (keyboard_flag == 1){
        data = get_keyboard_f();
        
        if (data == 0x3F){
            set_UART2(0x0D);
            set_UART2(0x0A);
            acq();
        }
        else{
            set_UART2(data);
            set_UART2_pc(data);
            acq();   
        }
    }
}