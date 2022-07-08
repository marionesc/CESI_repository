/*
 * File:   clav.c
 * Author: etien
 *
 * Created on 2 juin 2022, 16:09
 */


#include <xc.h>
#include "clav.h"
#include "LCD.h"

unsigned char mem_touche = 0;

unsigned char high_priority interrupt get_val_clav (){ // interrupt sur appui d'une touche clavier
   aff_lcd_clav(Clavier);
    INTCONbits.INT0IF = 0;
    return 0;
}
