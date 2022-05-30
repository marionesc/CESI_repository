/* 
 * File:   main.c
 * Author: Damien DUBOIS - Marion ESCOUTELOUP
 *
 * Created on May 24, 2022, 9:59 AM
 */

#include <xc.h>
#include<stdio.h>
#include<stdlib.h>
#include "FISA26Biblio.h"
#define _XTAL_FREQ 11059200


void main()
{
    
    
    INIT();
// Définition des variables
    signed char     a;              // variable 8 bits
    unsigned long   i;
    unsigned char   sens = 1;       // sens de rotation
    unsigned char   vitesse = 1;    // vitesse de rotation (4 vitesse)
    unsigned int   V1 = 2000;
    unsigned long   V2 = 40000;
    unsigned long   V3 = 80000;
    unsigned long   V4 = 160000;
    unsigned long   tempo = V1; 
    unsigned char   Leds = 0x01;    // variable Led 8bits


// Recopie des entrées sur les sorties
    while(1)
    {
// Switch

        if(BP_1 ==1 && BP_2 ==1)
        {

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
        else if (BP_1 == 1)
        {
            if (sens == 1)
            {
                sens = 0;
            }
            else
            {
                sens = 1;
            }
                
        }
        
        else if (BP_2 == 1)
        {
            if(vitesse == 4)
            {
                vitesse = 1;
            }
            else 
            {
                vitesse++;
            }
                
        }
        
        if (sens == 1 )
        {
           if (Leds ==0x80)
           {
               Leds = 0x01;
           }
           else 
           {
               Leds = Leds<<1;
           }
           
        }
        else 
        {
           if (Leds ==0x01)
           {
               Leds = 0x80;
           }
           else 
           {
               Leds = Leds>>1;
           } 
        }
        LED = Leds;    
        for(i = 0; i < 100; i++)
        {
            switch(vitesse)
            {
                case 1:
                    __delay_ms(5);

                case 2:
                    __delay_ms(10);

                case 3:
                    __delay_ms(20);

                case 4:
                    __delay_ms(40);

                default: break;
            }
        }     

    }
}
