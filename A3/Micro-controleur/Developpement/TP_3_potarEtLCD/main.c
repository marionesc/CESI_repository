/*
 * File:    MainDemoFipa25.c
 * Author:  damien DUBOIS
 *          MArion ESCOUTELOUP (GitHub : maresc)
 *
 * Created on June 13, 2022, 2:37 PM
 */

/** LIBRAIRIES GLOBALES DU PROJET **/
#include <xc.h>
#include "user.h"
#include "LCD.h"
#include "CAN.h"
#include "I2C.h"

/** MAIN PROJET **/
void main(void) {
    unsigned int VAL;
    unsigned char tampon;
    
    init();                 // Init. config gloable du µcontroleur
    init_aff_lcd();         // Init. des @param LCD
    I2C_Init();             // Init. des @param bus I2C
    init_can();             // Init. des @param confertisseur A/N
    
    while(1){
       VAL = read_adc();
       tampon = VAL >>4;
       //VAL = ConvBinVolt(VAL);
       AffichNombre(VAL);
       envoi_CNA(tampon);
       delai_ms(100);        
    }    
    return;
}

