/*******************************************************************************
* File Name: ADC_SAR_Seq_0_PM.c
* Version 1.10
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CyLib.h"
#include "ADC_SAR_Seq_0.h"


/***************************************
* Local data allocation
***************************************/

static ADC_SAR_Seq_0_BACKUP_STRUCT  ADC_SAR_Seq_0_backup =
{
    ADC_SAR_Seq_0_DISABLED
};


/*******************************************************************************
* Function Name: ADC_SAR_Seq_0_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_SAR_Seq_0_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_SAR_Seq_0_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADC_SAR_Seq_0_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADC_SAR_Seq_0_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_SAR_Seq_0_backup - modified.
*
*******************************************************************************/
void ADC_SAR_Seq_0_Sleep(void)
{
    /* During deepsleep/ hibernate mode keep SARMUX active, i.e. do not open
    *   all switches (disconnect), to be used for ADFT
    */
    ADC_SAR_Seq_0_SAR_DFT_CTRL_REG |= ADC_SAR_Seq_0_ADFT_OVERRIDE;
    if((ADC_SAR_Seq_0_SAR_CTRL_REG  & ADC_SAR_Seq_0_ENABLE) != 0u)
    {
        if((ADC_SAR_Seq_0_SAR_SAMPLE_CTRL_REG & ADC_SAR_Seq_0_CONTINUOUS_EN) != 0u)
        {
            ADC_SAR_Seq_0_backup.enableState = ADC_SAR_Seq_0_ENABLED | ADC_SAR_Seq_0_STARTED;
        }
        else
        {
            ADC_SAR_Seq_0_backup.enableState = ADC_SAR_Seq_0_ENABLED;
        }
        ADC_SAR_Seq_0_StopConvert();
        ADC_SAR_Seq_0_Stop();
    }
    else
    {
        ADC_SAR_Seq_0_backup.enableState = ADC_SAR_Seq_0_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADC_SAR_Seq_0_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers.
*  This should be called just after awaking from sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADC_SAR_Seq_0_backup - used.
*
*******************************************************************************/
void ADC_SAR_Seq_0_Wakeup(void)
{
    ADC_SAR_Seq_0_SAR_DFT_CTRL_REG &= (uint32)~ADC_SAR_Seq_0_ADFT_OVERRIDE;
    if(ADC_SAR_Seq_0_backup.enableState != ADC_SAR_Seq_0_DISABLED)
    {
        ADC_SAR_Seq_0_Start();
        if((ADC_SAR_Seq_0_backup.enableState & ADC_SAR_Seq_0_STARTED) != 0u)
        {
            ADC_SAR_Seq_0_StartConvert();
        }
    }
}
/* [] END OF FILE */
