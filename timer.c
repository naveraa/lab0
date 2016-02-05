/* 
 * File:   timer.c
 * Author: gvanhoy
 * "TODO" Author: Naomi Vera, netID: navera
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>
#include "timer.h"

void initTimer1(){
    TMR1 = 0;               //the thing that keeps counts. Starts counting at 0
    T1CONbits.TCKPS = 3;    //Pre-scalar. Since we want 256 and the data sheet says TCKPS<1:0>, 11=1:256 and 0b11 means 3 //configure how fast it ticks
    PR1 = 39062;            //period register. the thing to compare against. Register 2 needed. He originally had 1221*2, but I got 39062 assuming that the freq is 10MHz after going thru all the division and multiplication, ignoring the last peripheral clock divisor 
    T1CONbits.ON = 1;       //Turn timer on
    T1CONbits.TCS = 0;      //Selecting which oscillator to use, which is 0 by default, so we don't really neeeeeed it
    IFS0bits.T1IF = 0;      //Put the flag down
    IEC0bits.T1IE = 1;      //Enable interrupt
    IPC1bits.T1IP = 7;      //Configure the Interrupt Priority. Default is 0, so we need to turn that on
}