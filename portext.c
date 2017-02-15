/* ************************************************************************** */
/** Descriptive File Name

  @Company
    University College Nordjylland

  @File Name
    portext.c

  @Summary
    Driver for MCP23017/MCP23S17 port extender from Microchip

  @Description
    Upper layer device driver
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
#include "I2C_Drv.h"
//#define _BANK1    // Default BANK0 uncomment this line for BANK1 
#include "portext.h"


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
void portextDir(PORT_NAME portName, UINT8 value)
{
    switch(portName)
    {
        case PORT_A: drvI2CWriteByte(0x00,value,ADDR); break;
        case PORT_B: drvI2CWriteByte(0x01,value,ADDR); break;
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
    UINT8 value;
    switch (portName) {
        case PORT_A: drvI2CReadRegisters(GPIOA, &value, 1, ADDR ); break;
        case PORT_B: drvI2CReadRegisters(GPIOB, &value, 1, ADDR); break;
        default: value = 0; break;
    }
    return value;
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
