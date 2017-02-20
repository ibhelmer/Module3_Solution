/*
** LCD.c
** Interfacing to an LCD display of EPSON type
** 
*/

#include <p32xxxx.h>
#include "delay.h"
#include "portext.h"
#include "lcd.h"

void initLCD( void)
{
//    portchipsetup();
    portextDir(PORTB,0x00);
    portextDir(PORTA,0x00);
    
    DelayMs(40);                // wait 40mSec
    cmdLCD(0x38);               // Sendt 0x38
    DelayMs(5);                 // wait 5mSec
    cmdLCD(0x38);               // send 0x38
    DelayMs(1);               // wait 100uSec
    cmdLCD(0x38);               // send 0x38
    DelayMs(1);                // wait 48us
    cmdLCD(0x38);
    offLCD();
    cmdLCD(CLRDISP);           // clear display
    DelayMs(2);                 // wait 2mSec
    cmdLCD(6);                 // increment cursor, no shift
    DelayMs(2);                 // wait 2mSec
    onLCD();
    DelayMs(2);
} // initLCD


void writeLCD( char addr, unsigned char c)    
{   portextWrite(PORTB,c);
    if (addr==LCDDATA)          // select DDRam or command reg
    {
        portextWrite(PORTA,RS);
        portextWrite(PORTA,RS+E);
        DelayMs(1);
        portextWrite(PORTA,RS);
    }
    else
    {
        portextWrite(PORTA,0x00);
        portextWrite(PORTA,E); 
        DelayMs(1);
    }
    portextWrite(PORTA,0x00);
    DelayMs(20);                // Wait 48us so LCD is ready
} // writeLCD

void clrLCD()
{
    cmdLCD(CLRDISP);
    DelayMs(2);
}
void offLCD()
{
    cmdLCD(ONOFF);
}

void onLCD()
{
    cmdLCD(ONOFF | D_ONOFF);
}
void gotoLCD(char row, char col)
{
    switch(row)
    {
        case 1 : cmdLCD(DDRAM + LINE1 + col); break;
        case 2 : cmdLCD(DDRAM + LINE2+ col); break;
        case 3 : cmdLCD(DDRAM + LINE3+ col); break;
        case 4 : cmdLCD(DDRAM + LINE4+ col); break;
        default : cmdLCD(DDRAM + LINE1+ col); break;
    }
    
}
void putsLCD( char *s)
{
    while( *s) putLCD( *s++);   // Send out string char by char
} //putsLCD                        end when \0


