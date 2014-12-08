/*******************************************************************************
* File Name: testPin.c  
* Version 2.5
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "testPin.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        testPin_PC =   (testPin_PC & \
                                (uint32)(~(uint32)(testPin_DRIVE_MODE_IND_MASK << (testPin_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (testPin_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: testPin_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void testPin_Write(uint8 value) 
{
    uint8 drVal = (uint8)(testPin_DR & (uint8)(~testPin_MASK));
    drVal = (drVal | ((uint8)(value << testPin_SHIFT) & testPin_MASK));
    testPin_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: testPin_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  testPin_DM_STRONG     Strong Drive 
*  testPin_DM_OD_HI      Open Drain, Drives High 
*  testPin_DM_OD_LO      Open Drain, Drives Low 
*  testPin_DM_RES_UP     Resistive Pull Up 
*  testPin_DM_RES_DWN    Resistive Pull Down 
*  testPin_DM_RES_UPDWN  Resistive Pull Up/Down 
*  testPin_DM_DIG_HIZ    High Impedance Digital 
*  testPin_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void testPin_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(testPin__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: testPin_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro testPin_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 testPin_Read(void) 
{
    return (uint8)((testPin_PS & testPin_MASK) >> testPin_SHIFT);
}


/*******************************************************************************
* Function Name: testPin_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 testPin_ReadDataReg(void) 
{
    return (uint8)((testPin_DR & testPin_MASK) >> testPin_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(testPin_INTSTAT) 

    /*******************************************************************************
    * Function Name: testPin_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 testPin_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(testPin_INTSTAT & testPin_MASK);
		testPin_INTSTAT = maskedStatus;
        return maskedStatus >> testPin_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
