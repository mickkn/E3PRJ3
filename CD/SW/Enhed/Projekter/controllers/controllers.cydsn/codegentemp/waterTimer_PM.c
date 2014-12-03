/*******************************************************************************
* File Name: waterTimer_PM.c
* Version 2.50
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
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
        /* Backup the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            waterTimer_backup.TimerUdb = waterTimer_ReadCounter();
            waterTimer_backup.TimerPeriod = waterTimer_ReadPeriod();
            waterTimer_backup.InterruptMaskValue = waterTimer_STATUS_MASK;
            #if (waterTimer_UsingHWCaptureCounter)
                waterTimer_backup.TimerCaptureCounter = waterTimer_ReadCaptureCount();
            #endif /* Backup the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Backup the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            waterTimer_backup.TimerUdb = waterTimer_ReadCounter();
            waterTimer_backup.InterruptMaskValue = waterTimer_STATUS_MASK;
            #if (waterTimer_UsingHWCaptureCounter)
                waterTimer_backup.TimerCaptureCounter = waterTimer_ReadCaptureCount();
            #endif /* Back Up capture counter register  */
        #endif /* Backup non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!waterTimer_ControlRegRemoved)
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
        /* Restore the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            /* Interrupt State Backup for Critical Region*/
            uint8 waterTimer_interruptState;

            waterTimer_WriteCounter(waterTimer_backup.TimerUdb);
            waterTimer_WritePeriod(waterTimer_backup.TimerPeriod);
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            waterTimer_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            waterTimer_STATUS_AUX_CTRL |= waterTimer_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(waterTimer_interruptState);
            waterTimer_STATUS_MASK =waterTimer_backup.InterruptMaskValue;
            #if (waterTimer_UsingHWCaptureCounter)
                waterTimer_SetCaptureCount(waterTimer_backup.TimerCaptureCounter);
            #endif /* Restore the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Restore the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            waterTimer_WriteCounter(waterTimer_backup.TimerUdb);
            waterTimer_STATUS_MASK =waterTimer_backup.InterruptMaskValue;
            #if (waterTimer_UsingHWCaptureCounter)
                waterTimer_SetCaptureCount(waterTimer_backup.TimerCaptureCounter);
            #endif /* Restore Capture counter register*/
        #endif /* Restore up non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!waterTimer_ControlRegRemoved)
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
    #if(!waterTimer_ControlRegRemoved)
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
    #if(!waterTimer_ControlRegRemoved)
        if(waterTimer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                waterTimer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
