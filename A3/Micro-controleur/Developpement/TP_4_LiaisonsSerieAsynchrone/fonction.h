/* 
 * File:   fonction.h
 * Author: mario
 *
 * Created on 6 juillet 2022, 16:11
 */

#ifndef FONCTION_H
#define	FONCTION_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* FONCTION_H */

void Init (void);
void Eeprom_write(unsigned char addr, unsigned char data);
int Eeprom_read(unsigned char addr);
void I2C_Init();
void delai_ms(unsigned char val);

