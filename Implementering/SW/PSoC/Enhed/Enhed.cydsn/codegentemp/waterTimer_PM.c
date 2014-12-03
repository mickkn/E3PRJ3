/*******************************************************************************
* File Name: waterTimer_PM.c
* Version 2.60
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "waterTimer.h"

static waterTimer_backupStruct waterTimer_backup;


/*******************************************************************************
* Function Name: waterTimer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  waterTimer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void waterTimer_SaveConfig(void) 
{
    #if (!waterTimer_UsingFixedFunction)
        waterTimer_backup.TimerUdb = waterTimer_ReadCounter();
        waterTimer_backup.InterruptMaskValue = waterTimer_STATUS_MASK;
        #if (waterTimer_UsingHWCaptureCounter)
            waterTimer_backup.TimerCaptureCounter = waterTimer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!waterTimer_UDB_CONTROL_REG_REMOVED)
            waterTimer_backup.TimerControlRegister = waterTimer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: waterTimer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  waterTimer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void waterTimer_RestoreConfig(void) 
{   
    #if (!waterTimer_UsingFixedFunction)

        waterTimer_WriteCounter(waterTimer_backup.TimerUdb);
        waterTimer_STATUS_MASK =waterTimer_backup.InterruptMaskValue;
        #if (waterTimer_UsingHWCaptureCounter)
            waterTimer_SetCaptureCount(waterTimer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!waterTimer_UDB_CONTROL_REG_REMOVED)
            waterTimer_WriteControlRegister(waterTimer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: waterTimer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  waterTimer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void waterTimer_Sleep(void) 
{
    #if(!waterTimer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(waterTimer_CTRL_ENABLE == (waterTimer_CONTROL & waterTimer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            waterTimer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            waterTimer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    waterTimer_Stop();
    waterTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: waterTimer_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  waterTimer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void waterTimer_Wakeup(void) 
{
    waterTimer_RestoreConfig();
    #if(!waterTimer_UDB_CONTROL_REG_REMOVED)
        if(waterTimer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                waterTimer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
