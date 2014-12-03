/*******************************************************************************
* File Name: logDataTimer_PM.c
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

#include "logDataTimer.h"
static logDataTimer_backupStruct logDataTimer_backup;


/*******************************************************************************
* Function Name: logDataTimer_SaveConfig
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
*  logDataTimer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void logDataTimer_SaveConfig(void) 
{
    #if (!logDataTimer_UsingFixedFunction)
        /* Backup the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            logDataTimer_backup.TimerUdb = logDataTimer_ReadCounter();
            logDataTimer_backup.TimerPeriod = logDataTimer_ReadPeriod();
            logDataTimer_backup.InterruptMaskValue = logDataTimer_STATUS_MASK;
            #if (logDataTimer_UsingHWCaptureCounter)
                logDataTimer_backup.TimerCaptureCounter = logDataTimer_ReadCaptureCount();
            #endif /* Backup the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Backup the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            logDataTimer_backup.TimerUdb = logDataTimer_ReadCounter();
            logDataTimer_backup.InterruptMaskValue = logDataTimer_STATUS_MASK;
            #if (logDataTimer_UsingHWCaptureCounter)
                logDataTimer_backup.TimerCaptureCounter = logDataTimer_ReadCaptureCount();
            #endif /* Back Up capture counter register  */
        #endif /* Backup non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!logDataTimer_ControlRegRemoved)
            logDataTimer_backup.TimerControlRegister = logDataTimer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: logDataTimer_RestoreConfig
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
*  logDataTimer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void logDataTimer_RestoreConfig(void) 
{   
    #if (!logDataTimer_UsingFixedFunction)
        /* Restore the UDB non-rentention registers for CY_UDB_V0 */
        #if (CY_UDB_V0)
            /* Interrupt State Backup for Critical Region*/
            uint8 logDataTimer_interruptState;

            logDataTimer_WriteCounter(logDataTimer_backup.TimerUdb);
            logDataTimer_WritePeriod(logDataTimer_backup.TimerPeriod);
            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            logDataTimer_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            logDataTimer_STATUS_AUX_CTRL |= logDataTimer_STATUS_ACTL_INT_EN_MASK;
            /* Exit Critical Region*/
            CyExitCriticalSection(logDataTimer_interruptState);
            logDataTimer_STATUS_MASK =logDataTimer_backup.InterruptMaskValue;
            #if (logDataTimer_UsingHWCaptureCounter)
                logDataTimer_SetCaptureCount(logDataTimer_backup.TimerCaptureCounter);
            #endif /* Restore the UDB non-rentention register capture counter for CY_UDB_V0 */
        #endif /* Restore the UDB non-rentention registers for CY_UDB_V0 */

        #if (CY_UDB_V1)
            logDataTimer_WriteCounter(logDataTimer_backup.TimerUdb);
            logDataTimer_STATUS_MASK =logDataTimer_backup.InterruptMaskValue;
            #if (logDataTimer_UsingHWCaptureCounter)
                logDataTimer_SetCaptureCount(logDataTimer_backup.TimerCaptureCounter);
            #endif /* Restore Capture counter register*/
        #endif /* Restore up non retention registers, interrupt mask and capture counter for CY_UDB_V1 */

        #if(!logDataTimer_ControlRegRemoved)
            logDataTimer_WriteControlRegister(logDataTimer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: logDataTimer_Sleep
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
*  logDataTimer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void logDataTimer_Sleep(void) 
{
    #if(!logDataTimer_ControlRegRemoved)
        /* Save Counter's enable state */
        if(logDataTimer_CTRL_ENABLE == (logDataTimer_CONTROL & logDataTimer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            logDataTimer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            logDataTimer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    logDataTimer_Stop();
    logDataTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: logDataTimer_Wakeup
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
*  logDataTimer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void logDataTimer_Wakeup(void) 
{
    logDataTimer_RestoreConfig();
    #if(!logDataTimer_ControlRegRemoved)
        if(logDataTimer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                logDataTimer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
