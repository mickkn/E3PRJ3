/*******************************************************************************
* File Name: logDataTimer_PM.c
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
        logDataTimer_backup.TimerUdb = logDataTimer_ReadCounter();
        logDataTimer_backup.InterruptMaskValue = logDataTimer_STATUS_MASK;
        #if (logDataTimer_UsingHWCaptureCounter)
            logDataTimer_backup.TimerCaptureCounter = logDataTimer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!logDataTimer_UDB_CONTROL_REG_REMOVED)
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

        logDataTimer_WriteCounter(logDataTimer_backup.TimerUdb);
        logDataTimer_STATUS_MASK =logDataTimer_backup.InterruptMaskValue;
        #if (logDataTimer_UsingHWCaptureCounter)
            logDataTimer_SetCaptureCount(logDataTimer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!logDataTimer_UDB_CONTROL_REG_REMOVED)
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
    #if(!logDataTimer_UDB_CONTROL_REG_REMOVED)
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
    #if(!logDataTimer_UDB_CONTROL_REG_REMOVED)
        if(logDataTimer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                logDataTimer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
