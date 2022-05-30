#include <xc.h>

void INIT(void){
    
    

    
    
// D�sactivation du bus externe
    MEMCON=0xA0;    //ebdis=1 bus d�sactiv� (sauf en cas d'acc�s externe)

// D�sactivation des fonctions analogiques
    ANCON0=0x00;
    ANCON1=0x00;
    ANCON2=0x00;

// D�finition du sens des ports
    TRISD=0x00; // 0 => PORTD en sortie
    TRISH=0xFF; // 1 => PORTH en entr�e
    TRISGbits.TRISG3 = 1; 
    TRISGbits.TRISG4 = 1; 
    
    
}
