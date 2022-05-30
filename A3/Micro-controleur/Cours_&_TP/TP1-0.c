#include <xc.h>

/* Configuration du PIC:
    Oscillateur: HS (11.0592MHz)
    Watchdog Timer: désactivé
    Protection du code: désactivé */
#pragma config CONFIG1L = 0x1D
#pragma config CONFIG1H = 0x03 //HS_OSC
#pragma config CONFIG2L = 0x61 //BOR et PWRT Disable
#pragma config CONFIG2H = 0x00 //WDT off
#pragma config CONFIG3L = 0x01 //0x01:Bus D:8bit A:20bit
#pragma config CONFIG3H = 0x8B //MCLR
#pragma config CONFIG4L = 0x81 //0x81=debug_off 0x01=DEBUG_ON
#pragma config CONFIG5L = 0xFF //No CODE PROTECT
#pragma config CONFIG5H = 0xC0 //No CP EEPROM + code
#pragma config CONFIG6L = 0xFF //No write protect...
#pragma config CONFIG6H = 0xE0 //No write protect config...
#pragma config CONFIG7L = 0xFF //No table read protection
#pragma config CONFIG7H = 0x40 //No table read protection

// Definition des entrées
#define SWI_1   PORTHbits.RH4
#define SWI_2   PORTHbits.RH5
#define SWI_3   PORTHbits.RH6
#define SWI_4   PORTHbits.RH7

// Définition des sorties
#define LED_0   LATDbits.LATD0
#define LED_1   LATDbits.LATD1
#define LED_2   LATDbits.LATD2
#define LED_3   LATDbits.LATD3
#define LED_4   LATDbits.LATD4
#define LED_5   LATDbits.LATD5
#define LED_6   LATDbits.LATD6
#define LED_7   LATDbits.LATD7

void main(void)
{
// Définition des variables
    signed char a; // variable 8 bits

// Désactivation du bus externe
    MEMCON=0xA0;    //ebdis=1 bus désactivé (sauf en cas d'accès externe)

// Désactivation des fonctions analogiques
    ANCON0=0x00;
    ANCON1=0x00;
    ANCON2=0x00;

// Définition du sens des ports
    TRISD=0x00; // 0 => PORTD en sortie
    TRISH=0xFF; // 1 => PORTH en entrée

// Recopie des entrées sur les sorties
    while(1)
    {

// Switch
        if (SWI_1==1)
		LED_7=1;
	else
		LED_7=0;

        if (SWI_2==1)
		LED_6=1;
	else
		LED_6=0;

        if (SWI_3==1)
		LED_5=1;
	else
		LED_5=0;

        if (SWI_4==1)
		LED_4=1;
	else
		LED_4=0;
    }
}
