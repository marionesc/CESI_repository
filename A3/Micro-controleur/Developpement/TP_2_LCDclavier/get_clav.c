#include <xc.h>
#include "user.h"

extern unsigned char valeur_clav;
extern unsigned char valeur_dispo;
extern unsigned char valeur_to_affich;
extern unsigned char j;
extern unsigned char Tab[6];

// autorisation interruption
void init_interrupt(void)
{
    INTCONbits.GIE = 1;
    INTCONbits.INT0IE = 1;
    INTCONbits.INT0IF = 0;
}

// routine d'interruption
void high_priority interrupt Get_clav(void)
{
    if(INT0IF)
    {
        // valeur de la matrice du clavier
        valeur_clav = CLAVIER;
        Tab[j] = valeur_clav;
        valeur_dispo = 1;
  
         j++; 
         // remise a zero du flag
        INTCONbits.INT0IF = 0;
    }

}

void decod_clav(void)
{
    // selon la valeur de la matrice clavier
    // valeur à afficher en ascii
    // non prise en compte du retour arriere ou avancer
    valeur_clav = (valeur_clav & 0x0F);
   switch(valeur_clav)
   {
   case 0 : valeur_to_affich = '0'; break;
   case 1 : valeur_to_affich = '1'; break;
   case 2 : valeur_to_affich = '2'; break;
   case 3 : valeur_to_affich = '3'; break;
   case 4 : valeur_to_affich = '4'; break;
   case 5 : valeur_to_affich = '5'; break;
   case 6 : valeur_to_affich = '6'; break;
   case 7 : valeur_to_affich = '7'; break;
   case 8 : valeur_to_affich = '8'; break;
   case 9 : valeur_to_affich = '9'; break;
   case 11: valeur_to_affich = '='; break;
   case 12: valeur_to_affich = 1; break;
   case 13: valeur_to_affich = 2; break;
   case 14: valeur_to_affich = 3; break;
   case 15 : valeur_to_affich = 4; break;
//   case 10 : valeur_to_affich = '11'; break;
//   case 11 : valeur_to_affich = '12'; break;
//   case 12 : valeur_to_affich = '13'; break;
//   case 13 : valeur_to_affich = '14' ; break;
//   case 14 : valeur_to_affich = '15'; break;
   
   default : valeur_to_affich = 'x'  ;
   }
}

unsigned char decod_tab(unsigned char valeur)
{
    unsigned char tab;
    // selon la valeur de la matrice clavier
    // valeur à afficher en ascii
    // non prise en compte du retour arriere ou avancer
    valeur = (valeur & 0x0F);
   switch(valeur)
   {
   case 0 : tab = '0'; break;
   case 1 : tab = '1'; break;
   case 2 : tab = '2'; break;
   case 3 : tab = '3'; break;
   case 4 : tab = '4'; break;
   case 5 : tab = '5'; break;
   case 6 : tab = '6'; break;
   case 7 : tab = '7'; break;
   case 8 : tab = '8'; break;
   case 9 : tab = '9'; break;
//   case 9 : valeur_to_affich = '10'; break;
//   case 10 : valeur_to_affich = '11'; break;
//   case 11 : valeur_to_affich = '12'; break;
//   case 12 : valeur_to_affich = '13'; break;
//   case 13 : valeur_to_affich = '14' ; break;
//   case 14 : valeur_to_affich = '15'; break;
   
   default : valeur_to_affich = 'x'  ;
   }
   return tab;
}