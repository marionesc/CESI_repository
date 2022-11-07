/* 
 * File:   uart.h
 * Author: marion Escouteloup & Clement CHABANIS
 * GitHub: maesc & 
 * compileur : xc8 V1_1.12
 * 
 * Created on 2022-11-3rd
 *      Last update : 2022-11-07
 */

#ifndef UART_H
#define	UART_H

// UART 1 PORT FUNCTION
void set_UART1(unsigned char set_message);
void set_UART1_hyper(unsigned char set_message); 

// UART 2 PORT FUNCTION
void set_UART2(unsigned char set_message);
void set_UART2_pc(unsigned char set_message); 