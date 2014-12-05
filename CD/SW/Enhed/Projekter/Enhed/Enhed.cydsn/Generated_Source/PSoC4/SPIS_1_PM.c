/*******************************************************************************
* File Name: SPIS_1_PM.c
* Version 1.20
*
* Description:
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPIS_1.h"
#include "SPIS_1_PVT.h"

#if(SPIS_1_SCB_MODE_I2C_INC)
    #include "SPIS_1_I2C_PVT.h"
#endif /* (SPIS_1_SCB_MODE_I2C_INC) */

#if(SPIS_1_SCB_MODE_EZI2C_INC)
    #include "SPIS_1_EZI2C_PVT.h"
#endif /* (SPIS_1_SCB_MODE_EZI2C_INC) */

#if(SPIS_1_SCB_MODE_SPI_INC || SPIS_1_SCB_MODE_UART_INC)
    #include "SPIS_1_SPI_UART_PVT.h"
#endif /* (SPIS_1_SCB_MODE_SPI_INC || SPIS_1_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG || \
   (SPIS_1_SCB_MODE_I2C_CONST_CFG   && (!SPIS_1_I2C_WAKE_ENABLE_CONST))   || \
   (SPIS_1_SCB_MODE_EZI2C_CONST_CFG && (!SPIS_1_EZI2C_WAKE_ENABLE_CONST)) || \
   (SPIS_1_SCB_MODE_SPI_CONST_CFG   && (!SPIS_1_SPI_WAKE_ENABLE_CONST))   || \
   (SPIS_1_SCB_MODE_UART_CONST_CFG  && (!SPIS_1_UART_WAKE_ENABLE_CONST)))

    SPIS_1_BACKUP_STRUCT SPIS_1_backup =
    {
        0u, /* enableState */
    };
#endif


/*******************************************************************************
* Function Name: SPIS_1_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component to enter Deep Sleep.
*  The “Enable wakeup from Sleep Mode” selection has an influence on
*  this function implementation.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SPIS_1_Sleep(void)
{
#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)

    if(SPIS_1_SCB_WAKE_ENABLE_CHECK)
    {
        if(SPIS_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            SPIS_1_I2CSaveConfig();
        }
        else if(SPIS_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SPIS_1_EzI2CSaveConfig();
        }
    #if(!SPIS_1_CY_SCBIP_V1_I2C_ONLY)
        else if(SPIS_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            SPIS_1_SpiSaveConfig();
        }
        else if(SPIS_1_SCB_MODE_UART_RUNTM_CFG)
        {
            SPIS_1_UartSaveConfig();
        }
    #endif /* (!SPIS_1_CY_SCBIP_V1_I2C_ONLY) */
        else
        {
            /* Unknown mode: do nothing */
        }
    }
    else
    {
        SPIS_1_backup.enableState = (uint8) SPIS_1_GET_CTRL_ENABLED;

        if(0u != SPIS_1_backup.enableState)
        {
            SPIS_1_Stop();
        }
    }

#else

    #if (SPIS_1_SCB_MODE_I2C_CONST_CFG && SPIS_1_I2C_WAKE_ENABLE_CONST)
        SPIS_1_I2CSaveConfig();

    #elif (SPIS_1_SCB_MODE_EZI2C_CONST_CFG && SPIS_1_EZI2C_WAKE_ENABLE_CONST)
        SPIS_1_EzI2CSaveConfig();

    #elif (SPIS_1_SCB_MODE_SPI_CONST_CFG && SPIS_1_SPI_WAKE_ENABLE_CONST)
        SPIS_1_SpiSaveConfig();

    #elif (SPIS_1_SCB_MODE_UART_CONST_CFG && SPIS_1_UART_WAKE_ENABLE_CONST)
        SPIS_1_UartSaveConfig();

    #else

        SPIS_1_backup.enableState = (uint8) SPIS_1_GET_CTRL_ENABLED;

        if(0u != SPIS_1_backup.enableState)
        {
            SPIS_1_Stop();
        }

    #endif /* defined (SPIS_1_SCB_MODE_I2C_CONST_CFG) && (SPIS_1_I2C_WAKE_ENABLE_CONST) */

#endif /* (SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SPIS_1_Wakeup
********************************************************************************
*
* Summary:
*  Prepares the component for the Active mode operation after exiting Deep Sleep.
*  The “Enable wakeup from Sleep Mode” option has an influence on this function
*  implementation.
*  This function should not be called after exiting Sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SPIS_1_Wakeup(void)
{
#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)

    if(SPIS_1_SCB_WAKE_ENABLE_CHECK)
    {
        if(SPIS_1_SCB_MODE_I2C_RUNTM_CFG)
        {
            SPIS_1_I2CRestoreConfig();
        }
        else if(SPIS_1_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            SPIS_1_EzI2CRestoreConfig();
        }
    #if(!SPIS_1_CY_SCBIP_V1_I2C_ONLY)
        else if(SPIS_1_SCB_MODE_SPI_RUNTM_CFG)
        {
            SPIS_1_SpiRestoreConfig();
        }
        else if(SPIS_1_SCB_MODE_UART_RUNTM_CFG)
        {
            SPIS_1_UartRestoreConfig();
        }
    #endif /* (!SPIS_1_CY_SCBIP_V1_I2C_ONLY) */
        else
        {
            /* Unknown mode: do nothing */
        }
    }
    else
    {
        if(0u != SPIS_1_backup.enableState)
        {
            SPIS_1_Enable();
        }
    }

#else

    #if (SPIS_1_SCB_MODE_I2C_CONST_CFG  && SPIS_1_I2C_WAKE_ENABLE_CONST)
        SPIS_1_I2CRestoreConfig();

    #elif (SPIS_1_SCB_MODE_EZI2C_CONST_CFG && SPIS_1_EZI2C_WAKE_ENABLE_CONST)
        SPIS_1_EzI2CRestoreConfig();

    #elif (SPIS_1_SCB_MODE_SPI_CONST_CFG && SPIS_1_SPI_WAKE_ENABLE_CONST)
        SPIS_1_SpiRestoreConfig();

    #elif (SPIS_1_SCB_MODE_UART_CONST_CFG && SPIS_1_UART_WAKE_ENABLE_CONST)
        SPIS_1_UartRestoreConfig();

    #else

        if(0u != SPIS_1_backup.enableState)
        {
            SPIS_1_Enable();
        }

    #endif /* (SPIS_1_I2C_WAKE_ENABLE_CONST) */

#endif /* (SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
