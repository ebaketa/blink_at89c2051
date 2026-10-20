// ********************************************************
// Program:     Blink LED example
// Author:      Elvis Baketa
// Processor:   AT89C2051
// Oscillator:  12 MHz
// Compiler:    SDCC (Linux)
// Version:     0.2
// ********************************************************

#include <at89x051.h>

// delay one millisecond using timer 0 (12 MHz crystal, 1 us per machine cycle)
void delayms(void)
{
    // 65536 - 966 = 0xFC3A (1000 cycles minus 34 cycles of call and loop overhead)
    TH0 = 0xFC;
    TL0 = 0x3A;
    // start timer and wait for overflow
    TR0 = 1;
    while (!TF0);
    // stop timer and clear overflow flag
    TR0 = 0;
    TF0 = 0;
}

// amount of milliseconds to delay
void delay(unsigned int ms)
{
    while (ms--)
    {
        delayms();
    }
}

void main(void)
{
    // timer 0 in mode 1 (16-bit timer)
    TMOD = 0x01;

    while (1)
    {
        // turn LED on
        P1_0 = 0;
        delay(1000);
        // turn LED off
        P1_0 = 1;
        delay(1000);
    }
}
