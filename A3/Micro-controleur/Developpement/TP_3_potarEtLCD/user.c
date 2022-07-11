/*
 * File:    user.c
 * Author:  damien DUBOIS
 *          MArion ESCOUTELOUP (GitHub : maresc)
 *
 * Created on June 13, 2022, 2:37 PM
 */

/** LIBRAIRIES UTILISEES */
#include <xc.h>
#include "user.h"

/** VARIABLE GLOBALE DE REFERENCE **/
#define VOLTAGE_REF 5000    // Tension de reference à 5V
#define BITS_REF    4096    // Précision du µc : 12bits = 4096o

/** INITIALISATION DES FONCTIONS **/
/**
 * Cette fonction a pour but de configurer les ports du microntroleur qui sont 
 * neccessaire pour ce projet. Ici, la pin A0 du port A est initialisé à 1. 
 *  no @param
 *  no @return
 */
void init(void){
    TRISAbits.TRISA0 = 1 ;
//    TRISCbits.TRISC4 = 0 ;
//    TRISCbits.TRISC5 = 0 ;
    
    
}

/**
 * Cette fonction nous permet d'activer un delais en ms sans limitation de la
 * fonction d'origine '__delay_ms()'. 
 *  @param temps la durée à executer en ms
 *  no @return
 */
void delai_ms(unsigned int temps){
    for(int i=0; i<temps; i++){
        __delay_ms(1);
    }
}

/**
 * Cette fonction nous permet de réaliser une conversion entre une valeur sur 
 * 12bits en une tension 
 *  @param adc_value valeur lu sur la pin analogique
 *  @return voltage_conv valeur convertie en tension 
 */
unsigned int ConvBinVolt(unsigned int adc_value){
    //on force le resultat en type : unsigned long 
    voltage_conv = ((unsigned long)(adc_value * VOLTAGE_REF)) / (BITS_REF);  
    
    return voltage_conv; 
}

