/* 
 * File:   LCD.h
 * Author: mario
 *
 * Created on 6 juillet 2022, 16:12
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

far unsigned char LCD_FUNC@0x1A0000;
far unsigned char LCD_DATA@0x1A0002;
int mmode = 0; //sauvegarde du mode de fonctionnement
void acq(void);
void init_aff_lcd(void);
void aff_lcd_clav(unsigned char c);
void writeLCD(char phrase[]);
void aff_lcd(char c);
void writeLCD_number(int number);
int conversion_echelle(int min_echelle,int max_echelle,int min_aff,int max_aff,int value);

