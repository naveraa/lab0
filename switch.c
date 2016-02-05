/* 
 * File:   switch.c
 * Author: Naomi Vera
 *
 * Created on February 4, 2016, 2:19 PM
 */
#include <xc.h>
#include "switch.h"

#define INPUT 1
#define ENABLE 1;

void initSwitch(){
    TRISDbits.TRISD6 = INPUT;       //switch is an input thus, 1    
    CNPUDbits.CNPUD6 = ENABLE;      //have to enable the 
    CNCONDbits.ON = 1;              //turns on the change notifications for PORT D
    CNENDbits.CNIED6 = 1;           //turns on the change notifications for RD6
    IFS1bits.CNDIF = 0;             //putting the flag down
    IEC1bits.CNDIE = 1;             //enabling the interrupt
    IPC8bits.CNIP = 7;              //setting the priority 
}
