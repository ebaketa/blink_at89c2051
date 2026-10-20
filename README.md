# SDCC (AT89C2051)
## Blink example for AT89C2051 with SDCC

**Hardware:**
- AT89C2051 Experimental Board (12 MHz crystal, LED on pin P1.0)
- TL866A Universal Programmer

**Software:**
- Text Editor
- SDCC (Compiler)
- minipro (Programmer Software)

**Description:**
- Simple program to blink LED on pin P1_0, one second on and one second off.
- The 1 ms delay uses timer 0, so it does not depend on the compiler version.

**Build:**
```
sdcc -mmcs51 --code-size 2048 main.c
packihx main.ihx > main.hex
```

**Program the chip:**
```
minipro -p AT89C2051 -w main.hex
```
