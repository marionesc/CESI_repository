#include <xc.h>
#include "get_keyboard.h"

far unsigned char CLAV @0x180000;

unsigned char get_keyboard_f(void){
    unsigned char keyboard_value;
    keyboard_value = CLAV&0x0F + 0x30;
    
    return keyboard_value;
}
