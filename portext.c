/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
#include "I2C_Drv.h"
#define _BANK0
#include "portext.h"

/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
void portextDir(PORT_NAME portName, UINT8 value)
{
    switch(portName)
    {
        case PORT_A: drvI2CWriteByte(0x00,value,0x21); break;
        case PORT_B: drvI2CWriteByte(0x01,value,0x21); break;
        default: 
        break;
    }
}
void portextWrite(PORT_NAME portName, UINT8 value)
{
    switch(portName)
    {
        case PORT_A: drvI2CWriteByte(OLATA, value, ADDR); break;
        case PORT_B: drvI2CWriteByte(OLATB, value, ADDR); break;
        default:
        break;
    }   
}
UINT8 portextRead(PORT_NAME portName) {
    UINT8 *value;
    switch (portName) {
        case PORT_A:
            drvI2CReadRegisters(0x12, value, 1, 0x21);
            break;
        case PORT_B:
            drvI2CReadRegisters(0x13, value, 1, 0x21);
            break;
        default: value = 0;
            break;
    }
    return *value;
}







/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/* ************************************************************************** */

/* *****************************************************************************
 End of File
 */
