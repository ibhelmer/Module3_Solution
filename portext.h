/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef _PORTEXT_H    /* Guard against multiple inclusion */
#define _PORTEXT_H


/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include <p32xxxx.h>
#include "GenericTypeDefs.h"
#include "I2C_Drv.h"
/* This section lists the other files that are included in this file.
 */

typedef enum
{
    PORT_A,
    PORT_B
}PORT_NAME;

extern void portextDir(PORT_NAME portName, UINT8 value);
extern UINT8 portextRead(PORT_NAME portName);
extern void portextWrite(PORT_NAME portName, UINT8 value);

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif


    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */
    #define ADDR        0x21   // Change acording to the MCP23017's port 
    #ifdef _BANK0       
        #define IODIRA      0x00
        #define IODIRB      0x01
        #define IPOLA       0x02
        #define IPOLB       0x03
        #define GPINTENA    0x04
        #define GPINTENB    0x05
        #define DEFVALA     0x06
        #define DEFVALB     0x07
        #define INTCONA     0x08
        #define INTCONB     0x09
        #define IOCON       0x0A
        #define GPPUA       0x0C
        #define GPPUB       0x0D
        #define INTFA       0x0E
        #define INTFB       0x0F
        #define INTCAPA     0x10
        #define INTCAPB     0x11
        #define GPIOA       0x12
        #define GPIOB       0x13
        #define OLATA       0x14
        #define OLATB       0x15
    #else      // BANK = 1
        #define IODIRA      0x00
        #define IODIRB      0x10
        #define IPOLA       0x01
        #define IPOLB       0x11
        #define GPINTENA    0x02
        #define GPINTENB    0x12
        #define DEFVALA     0x03
        #define DEFVALB     0x13
        #define INTCONA     0x04
        #define INTCONB     0x14
        #define IOCON       0x15
        #define GPPUA       0x06
        #define GPPUB       0x16
        #define INTFA       0x07
        #define INTFB       0x17
        #define INTCAPA     0x08
        #define INTCAPB     0x18
        #define GPIOA       0x09
        #define GPIOB       0x19
        #define OLATA       0x0a
        #define OLATB       0x1a
    #endif



    // *****************************************************************************
    // *****************************************************************************
    // Section: Data Types
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    // *****************************************************************************

    /** Descriptive Data Type Name

      @Summary
        Brief one-line summary of the data type.
    
      @Description
        Full description, explaining the purpose and usage of the data type.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Remarks
        Any additional remarks
        <p>
        Describe enumeration elements and structure and union members above each 
        element or member.
     */
   


    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    // *****************************************************************************
    /**
      @Function
        int ExampleFunctionName ( int param1, int param2 ) 

      @Summary
        Brief one-line description of the function.

      @Description
        Full description, explaining the purpose and usage of the function.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

      @Precondition
        List and describe any required preconditions. If there are no preconditions,
        enter "None."

      @Parameters
        @param param1 Describe the first parameter to the function.
    
        @param param2 Describe the second parameter to the function.

      @Returns
        List (if feasible) and describe the return values of the function.
        <ul>
          <li>1   Indicates an error occurred
          <li>0   Indicates an error did not occur
        </ul>

      @Remarks
        Describe any special behavior not described above.
        <p>
        Any additional remarks.

      @Example
        @code
        if(ExampleFunctionName(1, 2) == 0)
        {
            return 3;
        }
     */
  
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
