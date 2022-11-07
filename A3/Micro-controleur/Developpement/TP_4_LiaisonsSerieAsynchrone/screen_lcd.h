/* 
 * File:   screen_lcd.h
 * Author: marion Escouteloup & Clement CHABANIS
 * GitHub: maesc & 
 * compileur : xc8 V1_1.12
 * 
 * Created on 2022-11-3rd
 *      Last update : 2022-11-07
 */

#ifndef SCREEN_LCD_H
#define	SCREEN_LCD_H


// INIT FUNCTION 
void init_screen_lcd(void);

// FUNCTION 
void acq(void);
void set_ddram(unsigned char addr); 
void screen_action(unsigned char keyboard);
void screen_word_write(char word); 
void screen_number_write(int number);
//void writeLCD_mem(char c, int adresse);