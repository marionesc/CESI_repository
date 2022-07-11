/* 
 * File:   user.h
 * Author: damien DUBOIS
 *         Marion ESCOUTELOUP (GitHub : maresc)
 *
 * Created on June 13, 2022, 2:36 PM
 */

#define _XTAL_FREQ 11059200


far unsigned char CLAVIER @ 0x180000 ;
far unsigned char LCD_DATA @ 0x1A0002 ;
far unsigned char LCD_FUNC @ 0x1A0000 ;

unsigned int ConvBinVolt(unsigned int binConv) ;
void init(void);
void delai_ms(unsigned int temps);

//Définitions des fonctions LCD
#define DISPLAY_CLEAR 0x01
#define RETURN_HOME 0x02
#define ENTRY_MODE_SET_CI_DNS 0x06 //Cursor increase, is not shifted
#define ENTRY_MODE_SET_CI_DS 0x07 //Cursor increase, shifted
#define DISPLAY_ON_CUR_ON_BLINK_ON 0x0F
#define DISPLAY_ON_CUR_ON_BLINKOFF 0x0E
#define SHIFT_DISPLAY_RIGHT 0x1C
#define SHIFT_DISPLAY_LEFT 0x18
#define SHIFT_CURSOR_RIGHT 0x14
#define SHIFT_CURSOR_LEFT 0x10
#define SET_FUNC_8BIT_2LINE_5x10 0x3C
#define SET_FUNC_8BIT_2LINE_5x7 0x38
