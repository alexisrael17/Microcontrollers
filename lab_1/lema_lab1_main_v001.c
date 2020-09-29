/*
 * File:   lema_lab1_main_v001.c
 * Author: Alex
 *
 * Created on September 5, 2019, 11:01 AM
 */

#include "xc.h"
// CW1: FLASH CONFIGURATION WORD 1 (see PIC24 Family Reference Manual 24.1)
#pragma config ICS = PGx1 // Comm Channel Select (Emulator EMUC1/EMUD1 pins are shared with PGC1/PGD1)
#pragma config FWDTEN = OFF // Watchdog Timer Enable (Watchdog Timer is disabled)
#pragma config GWRP = OFF // General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF // General Code Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF // JTAG Port Enable (JTAG port is disabled)
// CW2: FLASH CONFIGURATION WORD 2 (see PIC24 Family Reference Manual 24.1)
#pragma config I2C1SEL = PRI // I2C1 Pin Location Select (Use default SCL1/SDA1 pins)
#pragma config IOL1WAY = OFF // IOLOCK Protection (IOLOCK may be changed via unlocking seq)
#pragma config OSCIOFNC = ON // Primary Oscillator I/O Function (CLKO/RC15 functions as I/O pin)
#pragma config FCKSM = CSECME // Clock Switching and Monitor (Clock switching is enabled,
 // Fail-Safe Clock Monitor is enabled)
#pragma config FNOSC = FRCPLL // Oscillator Select (Fast RC Oscillator with PLL module (FRCPLL))

void setup(void)
{
    CLKDIVbits.RCDIV = 0; //Set RCDIV=1:1 (default 2:1) 32MHz or FCY/2=16M
    AD1PCFG = 0x9fff;
    TRISA = 0b0000000000011111;
    TRISB = 0b0000000000000011;
    LATA = 0xffff;
    LATB = 0xffff;

}

void delay(void) {
    //int curCount = 0;
    unsigned long int curCount = 0;
    
    while(curCount < 400000)
    {
        curCount++;
    }
}

/***FUNTION CREATED***/
void invert(int number)
{
LATB = LATB >> 1; //This shifts the LATB register
LATB = LATB ^ number;
}


int main(void) 
{ 
   setup(); 
   short int count =0;
   LATB = 0x7FFF; //This will turn on the most significant LED
   LATB = LATB | 0x0000;
   delay();
   
   while(1)
   {
    count =0;     
      while(count<3) 
       {
        invert(0x8000); /**CALLING INVERT FUNTION***/
        delay(); //This pauses execution so the shifts are visible
        count++;
        }
    
    count=0;
       
     while(count<3)
        {
           LATB = LATB << 1; //This shifts the LATB register     
           LATB = LATB ^ 0x0001; 
           delay(); //This pauses execution so the shifts are visible
           count++;
        }      
   }
   return 0;
}
