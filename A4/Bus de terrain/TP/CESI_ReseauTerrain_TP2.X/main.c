/*
 * File:   main.c
 * Author: sduval
 *
 * 6 d�cembre 2020, 17:28
 */

#include "main.h"
#include "afficheur.h"
#include "spi.h"
#include "eep_spi.h"
#include "i2c.h"

uint8_t u8DataFromI2C = 0;
uint8_t u8EventCounter[3]={0,0,0};

void initialisation_des_ports()
{
// D�sactivation du bus externe
    MEMCON=0xA0;    //ebdis=1 bus d�sactiv� (sauf en cas d'acc�s externe)

// D�sactivation des fonctions analogiques
    ANCON0=0x03; // ecran tactile en analogique X et Y
    ANCON1=0x08; // AN11 = entr�e analogique V_pot
    ANCON2=0x00;


// Valeur initiale des ports en sortie
    LED_R=0;
    LED_G=0;
    LED_B=0;

// D�fintion du sens des ports
    TRISAbits.TRISA2=0; //LED1
    TRISAbits.TRISA3=0; //LED2
    TRISAbits.TRISA4=0; //LED3
    TRISAbits.TRISA5=0; //LED4
    TRISCbits.TRISC2=0; //LED_R en sortie
    TRISCbits.TRISC1=0; //LED_G en sortie
    TRISGbits.TRISG0=0; //LED_B en sortie
    TRISCbits.TRISC3=1;
    TRISCbits.TRISC4=1;

// Mise en place des pull up
    INTCON2bits.RBPU=0; // Pull up PORTB activ�
    PADCFG1bits.REPU=1; // Pull up PORTE activ�

}

void main(void)
{
    initialisation_des_ports();
    initialisation_afficheur();

    SPI_Initialize();
    EEP_SPI_Initialize();

    I2C_Initialize();

    clear_text();
    clear_graphics();

    goto_lico(0,0);
    draw_string((unsigned char *)"Hello");
    
    I2C_Write_Register(0xA0,0x00,0x20); // Configure i2c chip to event counter
 
    while(1)
    {
        I2C_Read_Registers(0xA0, 0x01, 3, u8EventCounter);
        
        goto_lico(2,0);
        draw_hex8(u8EventCounter[2]);
        goto_lico(2,2);
        draw_hex8(u8EventCounter[1]);
        goto_lico(2,4);
        draw_hex8(u8EventCounter[0]);
        
        // Sur appui du bouton 4, remise � z�ro du cpt (sur 3 octets)
        if(!BP4)
        {
            I2C_Write_Register(0xA0,0x01,0x00);
            I2C_Write_Register(0xA0,0x02,0x00);
            I2C_Write_Register(0xA0,0x03,0x00);
            while(!BP4);
        }
    }
}
