/*******************************************************************************
* File Name: P_FT2.c  
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
#include "P_FT2.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        P_FT2_PC =   (P_FT2_PC & \
                                (uint32)(~(uint32)(P_FT2_DRIVE_MODE_IND_MASK << (P_FT2_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (P_FT2_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: P_FT2_Write
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
void P_FT2_Write(uint8 value) 
{
    uint8 drVal = (uint8)(P_FT2_DR & (uint8)(~P_FT2_MASK));
    drVal = (drVal | ((uint8)(value << P_FT2_SHIFT) & P_FT2_MASK));
    P_FT2_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: P_FT2_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  P_FT2_DM_STRONG     Strong Drive 
*  P_FT2_DM_OD_HI      Open Drain, Drives High 
*  P_FT2_DM_OD_LO      Open Drain, Drives Low 
*  P_FT2_DM_RES_UP     Resistive Pull Up 
*  P_FT2_DM_RES_DWN    Resistive Pull Down 
*  P_FT2_DM_RES_UPDWN  Resistive Pull Up/Down 
*  P_FT2_DM_DIG_HIZ    High Impedance Digital 
*  P_FT2_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void P_FT2_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(P_FT2__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: P_FT2_Read
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
*  Macro P_FT2_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 P_FT2_Read(void) 
{
    return (uint8)((P_FT2_PS & P_FT2_MASK) >> P_FT2_SHIFT);
}


/*******************************************************************************
* Function Name: P_FT2_ReadDataReg
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
uint8 P_FT2_ReadDataReg(void) 
{
    return (uint8)((P_FT2_DR & P_FT2_MASK) >> P_FT2_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(P_FT2_INTSTAT) 

    /*******************************************************************************
    * Function Name: P_FT2_ClearInterrupt
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
    uint8 P_FT2_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(P_FT2_INTSTAT & P_FT2_MASK);
		P_FT2_INTSTAT = maskedStatus;
        return maskedStatus >> P_FT2_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
