#include "clav.h"
#include <pic18f87k22.h>
#include <xc.h>
#include "LCD.h"
#include "interruption.h"

/*
void high_priority interrupt INT_clav(){
    if(INTCONbits.INT0F){
        unsigned char result;
        
            result = get_val_clav();
            aff_lcd(result);
            INTCONbits.INT0F = 0;
    }
}
*/

void Init_interruption(void){
    INTCON = 0x00;
    INTCONbits.PEIE_GIEL = 1;
    INTCONbits.GIE_GIEH = 1;
    INTCONbits.INT0E = 1;
}