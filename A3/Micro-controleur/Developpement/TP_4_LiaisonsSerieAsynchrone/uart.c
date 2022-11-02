#include <xc.h>
#include "get_keyboard.h"
#include "LCD.h"
#include "fonction.h"
#include "uart.h"

extern unsigned char keyboard_value;
extern int keyboard_flag;

/********************************/
/************ UART 1 ************/
/********************************/
/**Envoie d un message via le port serie UART1
 * @param set_message le message a envoye
 * no @return
 */
void set_UART1(unsigned char set_message){
    while(TX1IF == 0);
    TXREG1 = set_message;
}

/**Envoie d un message via le port serie UART1 hyper
 * @param set_message le message a envoye
 * no @return
 */
void set_UART1_hyper(unsigned char set_message){
    if (set_message != 0x00){
        set_UART1(set_message);
    }
}

/********************************/
/************ UART 2 ************/
/********************************/
/**Envoie d un message via le port serie UART
 * @param set_message le message a envoye
 * no @return
 */
void set_UART2(unsigned char set_message){
    while(TX1IF == 0);
    TXREG2 = set_message;
}

/**Envoie d un message via le port serie UART au PC
 * @param set_message le message a envoye
 * no @return
 */
void set_UART2_pc(unsigned char set_message){
    if (set_message != 0x00){
        set_UART2(set_message);
    }
}

void keyboard_treatment(void){
    unsigned char data;
    if (keyboard_flag == 1){
        data = get_keyboard_f();
        
        if (data == 0x3F){
            set_UART2(0x0D);
            set_UART2(0x0A);
            acq();
        }
        else{
            set_UART2(data);
            set_UART2_pc(data);
            acq();   
        }
    }
}