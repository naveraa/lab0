/* 
 * File:   led.c
 * Author: gvanhoy
 * "TODO" Author: Naomi Vera, netID: navera
 *
 * Created on August 27, 2015, 3:15 PM
 */

#include <xc.h>
#include "led.h"
#define OUTPUT 0
#define OFF 0
#define ON 1

#define LED1 LATDbits.LATD0
#define LED2 LATDbits.LATD1
#define LED3 LATDbits.LATD2

void initLEDs(){
    TRISDbits.TRISD0 = OUTPUT;      //define LED1 as an output 
    TRISDbits.TRISD1 = OUTPUT;      //define LED2 as an output 
    TRISDbits.TRISD2 = OUTPUT;      //define LED3 as an output 
    
    LED1 = ON;            //Turning LED1 ON
    LED2 = OFF;           //Turning LED2 OFF
    LED3 = OFF;           //Turning LED3 OFF
}

void turnOnLED(int led){
    if (led == 0) {
        LED1 = ON;
        LED2 = OFF;
        LED3 = OFF;
    }
    else if (led == 1) {
        LED1 = OFF;
        LED2 = ON;
        LED3 = OFF;
    }
    else {
        LED1 = OFF;
        LED2 = OFF;
        LED3 = ON;
    }  
}