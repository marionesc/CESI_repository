/* 
 * File:   main.c
 * Author: mario
 *
 * Created on 6 juillet 2022, 16:13
 */

//compileur : xc8
#include "fonction.h"
#include <xc.h>
#include "LCD.h"
#include "clav.h"
#include "CNA.h"


#define _XTAL_FREQ 11059200


void main(void) {
    Init();
    init_aff_lcd();
    acq();
    I2C_Init();
    while (1) {
        double value = ADC_read(0); // TP3
        DAC_write(value);
        value = (value*1000*(5/255));
        writeLCD_number(value);
        if (value > 255 * 0.7) {
            PORTGbits.RG0 = 1;
        } else {
            PORTGbits.RG0 = 0;
        }
        delai_ms(100);
        PIR1bits.ADIF = 0; // clear ADC interrupt flag
        return;
    }
}

