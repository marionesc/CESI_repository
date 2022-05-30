#include <xc.h>

void INIT(void){
    
    

    
    
// Désactivation du bus externe
    MEMCON=0xA0;    //ebdis=1 bus désactivé (sauf en cas d'accès externe)

// Désactivation des fonctions analogiques
    ANCON0=0x00;
    ANCON1=0x00;
    ANCON2=0x00;

// Définition du sens des ports
    TRISD=0x00; // 0 => PORTD en sortie
    TRISH=0xFF; // 1 => PORTH en entrée
    TRISGbits.TRISG3 = 1; 
    TRISGbits.TRISG4 = 1; 
    
    
}
