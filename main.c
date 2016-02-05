/* 
 * File:   main.c
 * Author: gvanhoy
 * "TODO" Author: Naomi Vera, netID: navera
 * Description: lab 0.
 * Created on August 27, 2015, 10:14 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "timer.h"
#include "led.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1
#define OFF 0
#define ON 1

typedef enum stateTypeEnum{
    led1, led2, led3
} stateType;

volatile stateType ledThatsOn = led1;     //so that ledThatsOn can be used in the interrupt 


int main() {
    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.
    initLEDs();                           //initiates LEDs
    initTimer1();                         //initiates Timer
    
    while(1){
        
        switch(ledThatsOn) {              //state machine!
            case led1:
                turnOnLED(led1);
                break;
            case led2:
                turnOnLED(led2);
                break;
            case led3:
                turnOnLED(led3);
                break;
        }
    }
    return 0;
}

void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interupt() {
	IFS0bits.T1IF = 0;                      //put flag down!!!!! Or else it'll keep calling this
    if (ledThatsOn == led1) {
        ledThatsOn = led2;
    }
    else if (ledThatsOn == led2) {
        ledThatsOn = led3;
    }
    else {
        ledThatsOn = led1;
    }
}