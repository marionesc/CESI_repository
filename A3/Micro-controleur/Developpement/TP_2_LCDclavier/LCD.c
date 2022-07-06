#include <xc.h>
#include "user.h"


//far unsigned char CLAVIER @ 0x180000 ;
//far unsigned char LCD_DATA @ 0x1A0002 ;
//far unsigned char LCD_FUNC @ 0x1A0000 ;

// fonction d'initialisation
// en mode use_clav()
void init_aff_lcd(void)
{
delai_ms(100);
LCD_FUNC=0x38; delai_ms(5);
LCD_FUNC=0x38; delai_ms(1);
LCD_FUNC=0x38; delai_ms(1);
LCD_FUNC=SET_FUNC_8BIT_2LINE_5x7; delai_ms(1);
LCD_FUNC=SHIFT_CURSOR_RIGHT; delai_ms(1);
LCD_FUNC=DISPLAY_ON_CUR_ON_BLINKOFF; delai_ms(1);
LCD_FUNC=ENTRY_MODE_SET_CI_DNS; delai_ms(1);
LCD_FUNC=RETURN_HOME; delai_ms(2);
LCD_FUNC=DISPLAY_CLEAR; delai_ms(2);
}


void LCD_busy (void)
{
    delai_ms(10);
    while((LCD_FUNC & 0x80)==0x80);
}


void lcd_print (unsigned char carac)
{
    LCD_DATA = carac ;
    LCD_busy();
}

void LCD_Clear (void)
{
    LCD_FUNC = DISPLAY_CLEAR;
    LCD_busy();
}

