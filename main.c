// ********************************************************
// Program:     Blink LED example
// Author:      Elvis Baketa
// Processor:   AT89C2051
// Oscillator:  12 MHz
// Compiler:    SDCC (Linux)
// Version:     0.1
// Comment:     
// ********************************************************

#include "at89x051.h"

// declare function
void delayms(void);
void delay(int data);

// main function
void main(void)
{
    // declare variable
    int i = 0;
    
    // run once
    P1_0 = 1;
    
    // loop forever
    while(1)
    {
        // turn LED on
        P1_0 = 0;
        // wait 1 second
        delay(1000);
        // turn LED off
        P1_0 = 1;
        // wait 1 second
        delay(1000);
    }
}

// delay one milisecond
void delayms(void)
{
    int i;
    // count to 33 for 1 ms delay
    for (i = 0; i < 34; i++);
}

// amount of milisecond to delay
void delay(int data)
{
    int i;
    for (i = 0; i < data; i++)
    {
        delayms();
    }
}

