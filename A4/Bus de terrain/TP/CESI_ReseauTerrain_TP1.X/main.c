/*
 * File:   main.c
 * Author: sduval
 *
 * 6 décembre 2020, 17:28
 */


#include <xc.h>
#include <stdint.h>
#include "main.h"
#include "spi.h"
#include "eep_spi.h"

void initialisation_des_ports()
{
// Désactivation du bus externe
    MEMCON=0xA0;    //ebdis=1 bus désactivé (sauf en cas d'accès externe)

// Désactivation des fonctions analogiques
    ANCON0=0x03; // ecran tactile en analogique X et Y
    ANCON1=0x08; // AN11 = entrée analogique V_pot
    ANCON2=0x00;


// Valeur initiale des ports en sortie
    LED_R=0;
    LED_G=0;
    LED_B=0;

// Défintion du sens des ports
    TRISAbits.TRISA2=0; //LED1
    TRISAbits.TRISA3=0; //LED2
    TRISAbits.TRISA4=0; //LED3
    TRISAbits.TRISA5=0; //LED4
    TRISCbits.TRISC2=0; //LED_R en sortie
    TRISCbits.TRISC1=0; //LED_G en sortie
    TRISGbits.TRISG0=0; //LED_B en sortie

// Mise en place des pull up
    INTCON2bits.RBPU=0; // Pull up PORTB activé
    PADCFG1bits.REPU=1; // Pull up PORTE activé

}

void main(void)
{
    uint8_t tu8Data[16] = {0x54,0x65,0x73,0x74,0x20,0x45,0x45,0x50,0x52,0x4F,0x4D,0x20,0x00,0x00,0x00,0x00};
    uint8_t tu8DataFromEEPROM[20];
    uint8_t u8Index = 0x00;
    uint8_t u8Cpt = 0x00;
    
    for(u8Index=0; u8Index<20; u8Index++)
    {
        tu8DataFromEEPROM[u8Index] = 0x00;
    }

    initialisation_des_ports();
    initialisation_afficheur();
    SPI_Initialize();
    EEP_SPI_Initialize();

    clear_text();
    clear_graphics();

    goto_lico(0,0);
    draw_string((unsigned char *)"Hello");
    
    drawVericalLine(10, 180, 80);

    for(u8Index=0; u8Index<20; u8Index++)
    {
        tu8DataFromEEPROM[u8Index] = EEP_SPI_ReadByte(u8Index);
    }
    
    // Affichage octets lus dans EEPROM SPIx
    goto_lico(1,1);
    draw_string((unsigned char *)&tu8DataFromEEPROM);
    
    // Compteur
    if(     (tu8DataFromEEPROM[12]<0x30)||(tu8DataFromEEPROM[12]>0x39)
        ||  (tu8DataFromEEPROM[13]<0x30)||(tu8DataFromEEPROM[13]>0x39)
        ||  (tu8DataFromEEPROM[14]<0x30)||(tu8DataFromEEPROM[14]>0x39)
       )
    {
        u8Cpt = 0;
    }
    else
    {
        u8Cpt = ((tu8DataFromEEPROM[12]-0x30)*100)+((tu8DataFromEEPROM[13]-0x30)*10)+(tu8DataFromEEPROM[14]-0x30);
        if(u8Cpt>99)
        {
            u8Cpt=0;
        }
        else
        {
            u8Cpt++;
        }
    }
    tu8Data[12] = (u8Cpt/100)+0x30;
    tu8Data[13] = ((u8Cpt-(u8Cpt/100))/10)+0x30;
    tu8Data[14] = (u8Cpt-(u8Cpt/100)-((u8Cpt-(u8Cpt/100))/10))+0x30;

    // Ecriture 16 octets en EEPROM SPI
    EEP_SPI_WriteBytes(0x00, (uint8_t *)&tu8Data, 16);
    
    while(1)
    {
        
    }
}
