#include <xc.h>
#include "user.h"


void init(void){
    
MEMCON=0xA0;
MEMCONbits.EBDIS = 0;

ANCON0 = 0x00;
ANCON1 = 0x00;
ANCON2 = 0x00;

}

void delai_ms(unsigned int temps)
{
    for(int i=0; i<temps; i++)
    {
        __delay_ms(1);
    }
}




























//// mise en sortie des bit du multiplexeur 
//void Init(void)
//{
//    TRISHbits.TRISH0 = 0;
//    TRISHbits.TRISH1 = 0;
//    TRISHbits.TRISH2 = 0;
//    TRISHbits.TRISH3 = 0;
//    
//}
//
///*
//     Le port D est partagé entre le clavier et l'afficheur, il faut alterner 
// *   pour utiliser les deux en même temps
// */
//
//
//// multiplexeur pour CS_Clav
//void Use_clav(void)
//{
//    // entrée multiplex
//    LATHbits.LATH0 = 0;
//    LATHbits.LATH1 = 0;
//    LATHbits.LATH2 = 1;
//    LATHbits.LATH3 = 1;
//    
//    // port D en entrée
//    TRISD = 0xFF;
//    
//    
//}
//
//// multiplexeur pour CS_Aff
//void Use_aff(void)
//{
//    // entrée multiplex
//    LATHbits.LATH0 = 1;
//    LATHbits.LATH1 = 0;
//    LATHbits.LATH2 = 1;
//    LATHbits.LATH3 = 1; 
//    
//    // mise en sortie du port D
//    TRISD = 0x00;
//}