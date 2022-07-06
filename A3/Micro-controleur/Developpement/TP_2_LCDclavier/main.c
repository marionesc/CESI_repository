/*
 * File:   MainDemoFipa25.c
 * Author: damie
 *
 * Created on June 13, 2022, 2:37 PM
 */

#include <xc.h>
#include "user.h"
#include "LCD.h"
#include "get_clav.h"
#include "eeprom.h"

// variables globales
unsigned char valeur_clav;
unsigned char valeur_dispo;
unsigned char valeur_to_affich;
unsigned char Tab[6];
unsigned char j;

void main(void) {
//// 
    unsigned char i;
    unsigned char addr ;
    unsigned char data ;
    init();
    init_aff_lcd(); // init lcd
    init_interrupt();
    valeur_dispo = 0;
    j=0;
    for(i=0;i>5;i++)
    {
        Tab[i]=0;
    }
    delai_ms(500);
    LCD_Clear ();
    
//    lcd_print('2');
//    lcd_print('2');
//    lcd_print('3');
//    lcd_print('4');
//    lcd_print('5');
//    lcd_print('6');
//    lcd_print('7');
//    lcd_print('8');
//    lcd_print('9');
//    lcd_print('=');
//    lcd_print('0');
//    while(1);
    
    while(1){
        if(valeur_dispo == 1)
        {
            
            decod_clav();
            if(((valeur_to_affich >= '0') && (valeur_to_affich <= '9')) || (valeur_to_affich == '='))
            {
            LCD_DATA = valeur_to_affich;
            }
            if(valeur_to_affich == 1)
            {
              LCD_FUNC = SHIFT_CURSOR_LEFT;  
            }
            if(valeur_to_affich == 2)
            {
              LCD_FUNC = SHIFT_CURSOR_RIGHT;  
            }
            if(valeur_to_affich == 3)
            {
              LCD_FUNC = DISPLAY_CLEAR;
              while((LCD_FUNC & 0x80)==0x80);
              LCD_FUNC = RETURN_HOME;
              j=0;
            }
            if(valeur_to_affich == 4)
            {
                if(j==6)
                {
                    j=0;
                    addr= Tab[0]*10+Tab[1];
                    data = (Tab[3]<<4) & Tab[4];
                    write_eeprom(addr, data);
                    Tab[3]=decod_tab(Tab[3]);
                    LCD_DATA = Tab[3];
                    while((LCD_FUNC & 0x80)==0x80);
                    Tab[4]=decod_tab(Tab[4]);
                    LCD_DATA = Tab[4];
                
                }
                if(j==3)
                {
                    j=0;
                    addr= Tab[0]*10+Tab[1];
                    data = read_eeprom(addr);
                    LCD_DATA = data /10;
                    while((LCD_FUNC & 0x80)==0x80);
                    LCD_DATA = data %10;
                    
                }
            }
                while((LCD_FUNC & 0x80)==0x80);
            valeur_dispo = 0;
            
        }
    }
    return;
    
}

