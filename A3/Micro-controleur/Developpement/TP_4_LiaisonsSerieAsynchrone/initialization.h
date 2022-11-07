/* 
 * File:   initialization.h
 * Author: marion Escouteloup & Clement CHABANIS
 * GitHub: maesc & 
 * compileur : xc8 V1_1.12
 * 
 * Created on 2022-11-3rd
 *      Last update : 2022-11-07
 */


// INIT FUNCTION
void Init(void); 
void I2C_Init(void);
void Init_interuption(void);

// ADDITIONAL FUNCTION
void delai_ms(unsigned char val);
char char_to_ascii(char data); 
int conversion_echelle(int min_ech,int max_ech,int min_aff,int max_aff,int value);
