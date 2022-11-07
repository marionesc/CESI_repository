/* 
 * File:   eeprom.h
 * Author: marion Escouteloup & Clement CHABANIS
 * GitHub: maesc & 
 * compileur : xc8 V1_1.12
 * 
 * Created on 2022-11-3rd
 *      Last update : 2022-11-07
 */

#ifndef EEPROM_H
#define	EEPROM_H

int read_eeprom(unsigned char addr);
void write_eeprom(unsigned char addr, unsigned char data); 

