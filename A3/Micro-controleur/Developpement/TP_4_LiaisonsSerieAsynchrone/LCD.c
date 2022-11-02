
#include <xc.h>
#include "LCD.h"

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
#define SET_FUNC_8BIT_1LINE_5x10 0x3C
#define SET_FUNC_8BIT_2LINE_5x7 0x38
#define _XTAL_FREQ 11059200

//fonction de set DD ram pour l'affichage du LCD
void set_ddram(unsigned char addr) {
    LCD_FUNC = 0x40 & addr;
}

//fonction de conversion d'un caractere en valeur ASCII
char char_to_ascii(char c){
    return c + 48;
}

void init_aff_lcd(void) {
    __delay_ms(10);
    LCD_FUNC = 0x38;
    __delay_ms(5);
    LCD_FUNC = 0x38;
    __delay_ms(1);
    LCD_FUNC = 0x38;
    __delay_ms(1);
    LCD_FUNC = SET_FUNC_8BIT_2LINE_5x7;
    __delay_ms(1);
    LCD_FUNC = SHIFT_CURSOR_RIGHT;
    __delay_ms(1);
    LCD_FUNC = DISPLAY_ON_CUR_ON_BLINKOFF;
    __delay_ms(1);
    LCD_FUNC = ENTRY_MODE_SET_CI_DNS;
    __delay_ms(1);
    LCD_FUNC = RETURN_HOME;
    __delay_ms(2);
    LCD_FUNC = DISPLAY_CLEAR;
    __delay_ms(2);
}

void acq(void) {
    while ((LCD_FUNC & 0x80) == 0x80);
}

void aff_lcd(char c) {
    LCD_FUNC = DISPLAY_CLEAR;
    acq();
    LCD_DATA = c;
    acq();
}

void aff_lcd_clav(unsigned char c) {
    // c est sur 8 bits mais les 4 premiers bits sont a ignorer
    c = c & 0x0F;
    switch (c) {
        case 10: //valeur +
            break;

        case 11: //valeur -
            break;

        case 12 : // valeur touche <
            LCD_FUNC = SHIFT_CURSOR_LEFT; // décalage de 1 caractère
            __delay_ms(2);
            acq();
            break;

        case 13 : // valeur touche >
            LCD_FUNC = SHIFT_CURSOR_RIGHT; // décalage de 1 caractère
            __delay_ms(2);
            acq();
            break;

        case 14 : // valeur touche AC
            LCD_FUNC = DISPLAY_CLEAR; // remise à zéro
            __delay_ms(2);
            acq();
            LCD_FUNC = RETURN_HOME; //mettre le curseur au début
            __delay_ms(2);
            acq();
            break;

        case 15 : // valeur touche entree
            LCD_FUNC = 0b0011000000;
            __delay_ms(2);
            acq();
            break;

        default :
            LCD_DATA = c + 48; // Decalage de 48 pour arriver dans la table ASCII
            acq();
            break;
    }
}

void writeLCD(char phrase[]) {
    int j = 0;
    LCD_FUNC = DISPLAY_CLEAR;
    acq();
    while (phrase[j] != '\0') {
        LCD_DATA = phrase[j];
        acq();
        j++;
    }
    j = 0;

}
//fonction de conversion d'echelle :
int conversion_echelle(int min_echelle,int max_echelle,int min_aff,int max_aff,int value){
    int conversion = 0;
    conversion = ((max_aff - min_aff)  / (max_echelle - min_echelle))*value;
    return conversion;
}


//fonction pour ecrire un nombre sur lecran
void writeLCD_number(int number) {
    int i = 0;
    char number_string[10];
    LCD_FUNC = DISPLAY_CLEAR;
    acq();
    while (number > 0) {
        number_string[i] = number % 10 + 48;
        number = number / 10;
        i++;
    }
    for (i = i - 1; i >= 0; i--) {
        LCD_DATA = number_string[i];
        acq();
    }
}

/*//fonction pour ecrire un caractere a un emplacement de memoire dans le LCD
void writeLCD_mem(char c, int adresse){
    set_ddram(adresse);
    LCD_FUNC = 0x200 & char_to_ascii(c);
    acq();
}
*/
