
   // Definition des entrées
#define SWI_1   PORTHbits.RH4
#define SWI_2   PORTHbits.RH5
#define SWI_3   PORTHbits.RH6
#define SWI_4   PORTHbits.RH7

#define BP_1    PORTGbits.RG3
#define BP_2    PORTGbits.RG4


// Définition des sorties
#define LED_0   LATDbits.LATD0
#define LED_1   LATDbits.LATD1
#define LED_2   LATDbits.LATD2
#define LED_3   LATDbits.LATD3
#define LED_4   LATDbits.LATD4
#define LED_5   LATDbits.LATD5
#define LED_6   LATDbits.LATD6
#define LED_7   LATDbits.LATD7

#define LED     LATD  


void INIT(void);


