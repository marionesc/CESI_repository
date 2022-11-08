/* 
 * File:   fan.c
 * Author: marion Escouteloup & Clement CHABANIS
 * GitHub: maesc & 
 * compileur : xc8 V1_1.12
 * 
 * Created on 2022-11-3rd
 *      Last update : 2022-11-08
 */

//LIBRARY USED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <xc.h>

#include <pic18f87k22.h>

#include "initialization.h"
#include "eeprom.h"
//#include "keyboard.h"
#include "screen_lcd.h"
#include "uart.h"
#include "CNA.h"
#include "fan.h"



// Init
/**
 * Initialisation du ventilateur
 */
void Init_fan(void){
    TRISCbits.TRISC2 = 0;   // Commande du fan
    
    TRISBbits.TRISB1 = 1;   // Lecture tachymetre fan
}
/**** FAN ****/
// void set_fan(int rpm) --> vitesse de rotation du fan
// int  get_fan() --> lit la vitesse reelle du fan 

void set_fan(int value){
    LATCbits.LATC2 = value;
}

/**
 * 
 * @return 
 */
int get_fan(void){
    reset_timer0(); 
    int fan_signal = PORTBbits.RB1;
    
    // Attente etat haut puis lancement du timer
    while(fan_signal == 0){
        fan_signal = PORTBbits.RB1; 
    };
    start_timer0(); 
    
    //Attente fin d etat haut 
    while(fan_signal == 1){
        fan_signal = PORTBbits.RB1;
    };
    /*
    //Attente nouveau etat haut
    while(fan_signal == 0){
        fan_signal = PORTBbits.RB1;
    };
    */
    
    stop_timer0();
    return lecture_timer0(); 
    
   /*
    int active = 0;
    int compteur = 0; 
    reset_timer0(); 
    
    while(compteur <= 2){
        if(PORTBbits.RB1 == 1){
            if(active == 0){
                start_timer0();
                active = 1; 
            }
            else {
                stop_timer0(); 
                active = 0;
            }
        }
    }
    
    return lecture_timer0(); 
    */
}