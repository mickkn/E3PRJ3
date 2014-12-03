/*******************************************************************************
* File Name: water_pin.c  
* Version 2.0
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
#include "water_pin.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        water_pin_PC =   (water_pin_PC & \
                                (uint32)(~(uint32)(water_pin_DRIVE_MODE_IND_MASK << (water_pin_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (water_pin_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: water_pin_Write
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
void water_pin_Write(uint8 value) 
{
    uint8 drVal = (uint8)(water_pin_DR & (uint8)(~water_pin_MASK));
    drVal = (drVal | ((uint8)(value << water_pin_SHIFT) & water_pin_MASK));
    water_pin_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: water_pin_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  water_pin_DM_STRONG     Strong Drive 
*  water_pin_DM_OD_HI      Open Drain, Drives High 
*  water_pin_DM_OD_LO      Open Drain, Drives Low 
*  water_pin_DM_RES_UP     Resistive Pull Up 
*  water_pin_DM_RES_DWN    Resistive Pull Down 
*  water_pin_DM_RES_UPDWN  Resistive Pull Up/Down 
*  water_pin_DM_DIG_HIZ    High Impedance Digital 
*  water_pin_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void water_pin_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(water_pin__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: water_pin_Read
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
*  Macro water_pin_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 water_pin_Read(void) 
{
    return (uint8)((water_pin_PS & water_pin_MASK) >> water_pin_SHIFT);
}


/*******************************************************************************
* Function Name: water_pin_ReadDataReg
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
uint8 water_pin_ReadDataReg(void) 
{
    return (uint8)((water_pin_DR & water_pin_MASK) >> water_pin_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(water_pin_INTSTAT) 

    /*******************************************************************************
    * Function Name: water_pin_ClearInterrupt
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
    uint8 water_pin_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(water_pin_INTSTAT & water_pin_MASK);
		water_pin_INTSTAT = maskedStatus;
        return maskedStatus >> water_pin_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
