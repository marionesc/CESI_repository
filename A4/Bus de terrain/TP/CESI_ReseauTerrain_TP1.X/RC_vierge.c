#include "main.h"


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
    initialisation_des_ports();
    initialisation_afficheur();
    clear_text();
    clear_graphics();

    goto_lico(0,0);
    draw_string("Hello");
    
    while(1)
    {
        
    }
}