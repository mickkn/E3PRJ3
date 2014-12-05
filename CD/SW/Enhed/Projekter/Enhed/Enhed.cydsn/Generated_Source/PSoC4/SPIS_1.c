/*******************************************************************************
* File Name: SPIS_1.c
* Version 1.20
*
* Description:
*  This file provides the source code to the API for the SCB Component.
*
* Note:
*
*******************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

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
*    Run Time Configuration Vars
***************************************/

/* Stores internal component configuration for unconfigured mode */
#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common config vars */
    uint8 SPIS_1_scbMode = SPIS_1_SCB_MODE_UNCONFIG;
    uint8 SPIS_1_scbEnableWake;
    uint8 SPIS_1_scbEnableIntr;

    /* I2C config vars */
    uint8 SPIS_1_mode;
    uint8 SPIS_1_acceptAddr;

    /* SPI/UART config vars */
    volatile uint8 * SPIS_1_rxBuffer;
    uint8  SPIS_1_rxDataBits;
    uint32 SPIS_1_rxBufferSize;

    volatile uint8 * SPIS_1_txBuffer;
    uint8  SPIS_1_txDataBits;
    uint32 SPIS_1_txBufferSize;

    /* EZI2C config vars */
    uint8 SPIS_1_numberOfAddr;
    uint8 SPIS_1_subAddrSize;
#endif /* (SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Common SCB Vars
***************************************/

uint8 SPIS_1_initVar = 0u;

#if !defined (CY_REMOVE_SPIS_1_CUSTOM_INTR_HANDLER)
    cyisraddress SPIS_1_customIntrHandler = NULL;
#endif /* !defined (CY_REMOVE_SPIS_1_CUSTOM_INTR_HANDLER) */


/***************************************
*    Private Function Prototypes
***************************************/

static void SPIS_1_ScbEnableIntr(void);
static void SPIS_1_ScbModeStop(void);


/*******************************************************************************
* Function Name: SPIS_1_Init
********************************************************************************
*
* Summary:
*  Initializes the SCB component to operate in one of the selected configurations:
*  I2C, SPI, UART or EZ I2C.
*  When the configuration is set to “Unconfigured SCB”, this function does
*  not do any initialization. Use mode-specific initialization APIs instead:
*  SCB_I2CInit, SCB_SpiInit, SCB_UartInit or SCB_EzI2CInit.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SPIS_1_Init(void)
{
#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)
    if(SPIS_1_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        SPIS_1_initVar = 0u; /* Clear init var */
    }
    else
    {
        /* Initialization was done before call */
    }

#elif(SPIS_1_SCB_MODE_I2C_CONST_CFG)
    SPIS_1_I2CInit();

#elif(SPIS_1_SCB_MODE_SPI_CONST_CFG)
    SPIS_1_SpiInit();

#elif(SPIS_1_SCB_MODE_UART_CONST_CFG)
    SPIS_1_UartInit();

#elif(SPIS_1_SCB_MODE_EZI2C_CONST_CFG)
    SPIS_1_EzI2CInit();

#endif /* (SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SPIS_1_Enable
********************************************************************************
*
* Summary:
*  Enables the SCB component operation.
*  The SCB configuration should be not changed when the component is enabled.
*  Any configuration changes should be made after disabling the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SPIS_1_Enable(void)
{
#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Enable SCB block, only if it is already configured */
    if(!SPIS_1_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        SPIS_1_CTRL_REG |= SPIS_1_CTRL_ENABLED;

        SPIS_1_ScbEnableIntr();
    }
#else
    SPIS_1_CTRL_REG |= SPIS_1_CTRL_ENABLED;

    SPIS_1_ScbEnableIntr();
#endif /* (SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: SPIS_1_Start
********************************************************************************
*
* Summary:
*  Invokes SCB_Init() and SCB_Enable().
*  After this function call, the component is enabled and ready for operation.
*  When configuration is set to “Unconfigured SCB”, the component must first be
*  initialized to operate in one of the following configurations: I2C, SPI, UART
*  or EZ I2C. Otherwise this function does not enable the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SPIS_1_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void SPIS_1_Start(void)
{
    if(0u == SPIS_1_initVar)
    {
        SPIS_1_Init();
        SPIS_1_initVar = 1u; /* Component was initialized */
    }

    SPIS_1_Enable();
}


/*******************************************************************************
* Function Name: SPIS_1_Stop
********************************************************************************
*
* Summary:
*  Disables the SCB component and its interrupt.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SPIS_1_Stop(void)
{
#if(SPIS_1_SCB_IRQ_INTERNAL)
    SPIS_1_DisableInt();
#endif /* (SPIS_1_SCB_IRQ_INTERNAL) */

    SPIS_1_CTRL_REG &= (uint32) ~SPIS_1_CTRL_ENABLED;  /* Disable SCB block */

#if(SPIS_1_SCB_IRQ_INTERNAL)
    SPIS_1_ClearPendingInt();
#endif /* (SPIS_1_SCB_IRQ_INTERNAL) */

    SPIS_1_ScbModeStop(); /* Calls scbMode specific Stop function */
}


/*******************************************************************************
* Function Name: SPIS_1_SetCustomInterruptHandler
********************************************************************************
*
* Summary:
*  Registers a function to be called by the internal interrupt handler.
*  First the function that is registered is called, then the internal interrupt
*  handler performs any operations such as software buffer management functions
*  before the interrupt returns.  It is the user's responsibility not to break the
*  software buffer operations. Only one custom handler is supported, which is
*  the function provided by the most recent call.
*  At initialization time no custom handler is registered.
*
* Parameters:
*  func: Pointer to the function to register.
*        The value NULL indicates to remove the current custom interrupt
*        handler.
*
* Return:
*  None
*
*******************************************************************************/
void SPIS_1_SetCustomInterruptHandler(cyisraddress func)
{
#if !defined (CY_REMOVE_SPIS_1_CUSTOM_INTR_HANDLER)
    SPIS_1_customIntrHandler = func; /* Register interrupt handler */
#else
    if(NULL != func)
    {
        /* Suppress compiler warning */
    }
#endif /* !defined (CY_REMOVE_SPIS_1_CUSTOM_INTR_HANDLER) */
}


/*******************************************************************************
* Function Name: SPIS_1_ScbModeEnableIntr
********************************************************************************
*
* Summary:
*  Enables an interrupt for a specific mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void SPIS_1_ScbEnableIntr(void)
{
#if(SPIS_1_SCB_IRQ_INTERNAL)
    #if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Enable interrupt in the NVIC */
        if(0u != SPIS_1_scbEnableIntr)
        {
            SPIS_1_EnableInt();
        }
    #else
        SPIS_1_EnableInt();

    #endif /* (SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG) */
#endif /* (SPIS_1_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: SPIS_1_ScbModeStop
********************************************************************************
*
* Summary:
*  Calls the Stop function for a specific operation mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void SPIS_1_ScbModeStop(void)
{
#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)
    if(SPIS_1_SCB_MODE_I2C_RUNTM_CFG)
    {
        SPIS_1_I2CStop();
    }
    else if(SPIS_1_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        SPIS_1_EzI2CStop();
    }
    else
    {
        /* Do nohing for other modes */
    }
#elif(SPIS_1_SCB_MODE_I2C_CONST_CFG)
    SPIS_1_I2CStop();

#elif(SPIS_1_SCB_MODE_EZI2C_CONST_CFG)
    SPIS_1_EzI2CStop();

#endif /* (SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if(SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: SPIS_1_SetPins
    ********************************************************************************
    *
    * Summary:
    *  Sets the pins settings accordingly to the selected operation mode.
    *  Only available in the Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when a specific mode of operation
    *  is selected in design time.
    *
    * Parameters:
    *  mode:      Mode of SCB operation.
    *  subMode:   Sub-mode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  uartTxRx:  Direction for UART.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SPIS_1_SetPins(uint32 mode, uint32 subMode, uint32 uartTxRx)
    {
        uint32 hsiomSel [SPIS_1_SCB_PINS_NUMBER];
        uint32 pinsDm   [SPIS_1_SCB_PINS_NUMBER];
        uint32 pinsInBuf = 0u;

        uint32 i;

        /* Set default HSIOM to GPIO and Drive Mode to Analog Hi-Z */
        for(i = 0u; i < SPIS_1_SCB_PINS_NUMBER; i++)
        {
            hsiomSel[i]  = SPIS_1_HSIOM_DEF_SEL;
            pinsDm[i]    = SPIS_1_PIN_DM_ALG_HIZ;
        }

        if((SPIS_1_SCB_MODE_I2C   == mode) ||
           (SPIS_1_SCB_MODE_EZI2C == mode))
        {
            hsiomSel[SPIS_1_MOSI_SCL_RX_PIN_INDEX] = SPIS_1_HSIOM_I2C_SEL;
            hsiomSel[SPIS_1_MISO_SDA_TX_PIN_INDEX] = SPIS_1_HSIOM_I2C_SEL;

            pinsDm[SPIS_1_MOSI_SCL_RX_PIN_INDEX] = SPIS_1_PIN_DM_OD_LO;
            pinsDm[SPIS_1_MISO_SDA_TX_PIN_INDEX] = SPIS_1_PIN_DM_OD_LO;
        }
    #if(!SPIS_1_CY_SCBIP_V1_I2C_ONLY)
        else if(SPIS_1_SCB_MODE_SPI == mode)
        {
            hsiomSel[SPIS_1_MOSI_SCL_RX_PIN_INDEX] = SPIS_1_HSIOM_SPI_SEL;
            hsiomSel[SPIS_1_MISO_SDA_TX_PIN_INDEX] = SPIS_1_HSIOM_SPI_SEL;
            hsiomSel[SPIS_1_SCLK_PIN_INDEX]        = SPIS_1_HSIOM_SPI_SEL;

            if(SPIS_1_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[SPIS_1_MOSI_SCL_RX_PIN_INDEX] = SPIS_1_PIN_DM_DIG_HIZ;
                pinsDm[SPIS_1_MISO_SDA_TX_PIN_INDEX] = SPIS_1_PIN_DM_STRONG;
                pinsDm[SPIS_1_SCLK_PIN_INDEX]        = SPIS_1_PIN_DM_DIG_HIZ;

            #if(SPIS_1_SS0_PIN)
                /* Only SS0 is valid choice for Slave */
                hsiomSel[SPIS_1_SS0_PIN_INDEX] = SPIS_1_HSIOM_SPI_SEL;
                pinsDm  [SPIS_1_SS0_PIN_INDEX] = SPIS_1_PIN_DM_DIG_HIZ;
            #endif /* (SPIS_1_SS1_PIN) */

            #if(SPIS_1_MISO_SDA_TX_PIN)
                /* Disable input buffer */
                 pinsInBuf |= SPIS_1_MISO_SDA_TX_PIN_MASK;
            #endif /* (SPIS_1_MISO_SDA_TX_PIN_PIN) */
            }
            else /* (Master) */
            {
                pinsDm[SPIS_1_MOSI_SCL_RX_PIN_INDEX] = SPIS_1_PIN_DM_STRONG;
                pinsDm[SPIS_1_MISO_SDA_TX_PIN_INDEX] = SPIS_1_PIN_DM_DIG_HIZ;
                pinsDm[SPIS_1_SCLK_PIN_INDEX]        = SPIS_1_PIN_DM_STRONG;

            #if(SPIS_1_SS0_PIN)
                hsiomSel [SPIS_1_SS0_PIN_INDEX] = SPIS_1_HSIOM_SPI_SEL;
                pinsDm   [SPIS_1_SS0_PIN_INDEX] = SPIS_1_PIN_DM_STRONG;
                pinsInBuf                                |= SPIS_1_SS0_PIN_MASK;
            #endif /* (SPIS_1_SS0_PIN) */

            #if(SPIS_1_SS1_PIN)
                hsiomSel [SPIS_1_SS1_PIN_INDEX] = SPIS_1_HSIOM_SPI_SEL;
                pinsDm   [SPIS_1_SS1_PIN_INDEX] = SPIS_1_PIN_DM_STRONG;
                pinsInBuf                                |= SPIS_1_SS1_PIN_MASK;
            #endif /* (SPIS_1_SS1_PIN) */

            #if(SPIS_1_SS2_PIN)
                hsiomSel [SPIS_1_SS2_PIN_INDEX] = SPIS_1_HSIOM_SPI_SEL;
                pinsDm   [SPIS_1_SS2_PIN_INDEX] = SPIS_1_PIN_DM_STRONG;
                pinsInBuf                                |= SPIS_1_SS2_PIN_MASK;
            #endif /* (SPIS_1_SS2_PIN) */

            #if(SPIS_1_SS3_PIN)
                hsiomSel [SPIS_1_SS3_PIN_INDEX] = SPIS_1_HSIOM_SPI_SEL;
                pinsDm   [SPIS_1_SS3_PIN_INDEX] = SPIS_1_PIN_DM_STRONG;
                pinsInBuf                                |= SPIS_1_SS3_PIN_MASK;
            #endif /* (SPIS_1_SS2_PIN) */

                /* Disable input buffers */
            #if(SPIS_1_MOSI_SCL_RX_PIN)
                pinsInBuf |= SPIS_1_MOSI_SCL_RX_PIN_MASK;
            #endif /* (SPIS_1_MOSI_SCL_RX_PIN) */

             #if(SPIS_1_MOSI_SCL_RX_WAKE_PIN)
                pinsInBuf |= SPIS_1_MOSI_SCL_RX_WAKE_PIN_MASK;
            #endif /* (SPIS_1_MOSI_SCL_RX_WAKE_PIN) */

            #if(SPIS_1_SCLK_PIN)
                pinsInBuf |= SPIS_1_SCLK_PIN_MASK;
            #endif /* (SPIS_1_SCLK_PIN) */
            }
        }
        else /* UART */
        {
            if(SPIS_1_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
                hsiomSel[SPIS_1_MISO_SDA_TX_PIN_INDEX] = SPIS_1_HSIOM_UART_SEL;
                pinsDm  [SPIS_1_MISO_SDA_TX_PIN_INDEX] = SPIS_1_PIN_DM_OD_LO;
            }
            else /* Standard or IrDA */
            {
                if(0u != (SPIS_1_UART_RX & uartTxRx))
                {
                    hsiomSel[SPIS_1_MOSI_SCL_RX_PIN_INDEX] = SPIS_1_HSIOM_UART_SEL;
                    pinsDm  [SPIS_1_MOSI_SCL_RX_PIN_INDEX] = SPIS_1_PIN_DM_DIG_HIZ;
                }

                if(0u != (SPIS_1_UART_TX & uartTxRx))
                {
                    hsiomSel[SPIS_1_MISO_SDA_TX_PIN_INDEX] = SPIS_1_HSIOM_UART_SEL;
                    pinsDm  [SPIS_1_MISO_SDA_TX_PIN_INDEX] = SPIS_1_PIN_DM_STRONG;

                #if(SPIS_1_MISO_SDA_TX_PIN)
                     pinsInBuf |= SPIS_1_MISO_SDA_TX_PIN_MASK;
                #endif /* (SPIS_1_MISO_SDA_TX_PIN_PIN) */
                }
            }
        }
    #endif /* (!SPIS_1_CY_SCBIP_V1_I2C_ONLY) */

    /* Configure pins: set HSIOM, DM and InputBufEnable */
    /* Note: the DR register settigns do not effect the pin output if HSIOM is other than GPIO */

    #if(SPIS_1_MOSI_SCL_RX_PIN)
        SPIS_1_SET_HSIOM_SEL(SPIS_1_MOSI_SCL_RX_HSIOM_REG,
                                       SPIS_1_MOSI_SCL_RX_HSIOM_MASK,
                                       SPIS_1_MOSI_SCL_RX_HSIOM_POS,
                                       hsiomSel[SPIS_1_MOSI_SCL_RX_PIN_INDEX]);

        SPIS_1_spi_mosi_i2c_scl_uart_rx_SetDriveMode((uint8) pinsDm[SPIS_1_MOSI_SCL_RX_PIN_INDEX]);

        SPIS_1_SET_INP_DIS(SPIS_1_spi_mosi_i2c_scl_uart_rx_INP_DIS,
                                     SPIS_1_spi_mosi_i2c_scl_uart_rx_MASK,
                                     (0u != (pinsInBuf & SPIS_1_MOSI_SCL_RX_PIN_MASK)));
    #endif /* (SPIS_1_MOSI_SCL_RX_PIN) */

    #if(SPIS_1_MOSI_SCL_RX_WAKE_PIN)
        SPIS_1_SET_HSIOM_SEL(SPIS_1_MOSI_SCL_RX_WAKE_HSIOM_REG,
                                       SPIS_1_MOSI_SCL_RX_WAKE_HSIOM_MASK,
                                       SPIS_1_MOSI_SCL_RX_WAKE_HSIOM_POS,
                                       hsiomSel[SPIS_1_MOSI_SCL_RX_WAKE_PIN_INDEX]);

        SPIS_1_spi_mosi_i2c_scl_uart_rx_wake_SetDriveMode((uint8)
                                                               pinsDm[SPIS_1_MOSI_SCL_RX_WAKE_PIN_INDEX]);

        SPIS_1_SET_INP_DIS(SPIS_1_spi_mosi_i2c_scl_uart_rx_wake_INP_DIS,
                                     SPIS_1_spi_mosi_i2c_scl_uart_rx_wake_MASK,
                                     (0u != (pinsInBuf & SPIS_1_MOSI_SCL_RX_WAKE_PIN_MASK)));

         /* Set interrupt on falling edge */
        SPIS_1_SET_INCFG_TYPE(SPIS_1_MOSI_SCL_RX_WAKE_INTCFG_REG,
                                        SPIS_1_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK,
                                        SPIS_1_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS,
                                        SPIS_1_INTCFG_TYPE_FALLING_EDGE);
    #endif /* (SPIS_1_MOSI_SCL_RX_WAKE_PIN) */

    #if(SPIS_1_MISO_SDA_TX_PIN)
        SPIS_1_SET_HSIOM_SEL(SPIS_1_MISO_SDA_TX_HSIOM_REG,
                                       SPIS_1_MISO_SDA_TX_HSIOM_MASK,
                                       SPIS_1_MISO_SDA_TX_HSIOM_POS,
                                       hsiomSel[SPIS_1_MISO_SDA_TX_PIN_INDEX]);

        SPIS_1_spi_miso_i2c_sda_uart_tx_SetDriveMode((uint8) pinsDm[SPIS_1_MISO_SDA_TX_PIN_INDEX]);

        SPIS_1_SET_INP_DIS(SPIS_1_spi_miso_i2c_sda_uart_tx_INP_DIS,
                                     SPIS_1_spi_miso_i2c_sda_uart_tx_MASK,
                                    (0u != (pinsInBuf & SPIS_1_MISO_SDA_TX_PIN_MASK)));
    #endif /* (SPIS_1_MOSI_SCL_RX_PIN) */

    #if(SPIS_1_SCLK_PIN)
        SPIS_1_SET_HSIOM_SEL(SPIS_1_SCLK_HSIOM_REG, SPIS_1_SCLK_HSIOM_MASK,
                                       SPIS_1_SCLK_HSIOM_POS, hsiomSel[SPIS_1_SCLK_PIN_INDEX]);

        SPIS_1_spi_sclk_SetDriveMode((uint8) pinsDm[SPIS_1_SCLK_PIN_INDEX]);

        SPIS_1_SET_INP_DIS(SPIS_1_spi_sclk_INP_DIS,
                             SPIS_1_spi_sclk_MASK,
                            (0u != (pinsInBuf & SPIS_1_SCLK_PIN_MASK)));
    #endif /* (SPIS_1_SCLK_PIN) */

    #if(SPIS_1_SS0_PIN)
        SPIS_1_SET_HSIOM_SEL(SPIS_1_SS0_HSIOM_REG, SPIS_1_SS0_HSIOM_MASK,
                                       SPIS_1_SS0_HSIOM_POS, hsiomSel[SPIS_1_SS0_PIN_INDEX]);

        SPIS_1_spi_ss0_SetDriveMode((uint8) pinsDm[SPIS_1_SS0_PIN_INDEX]);

        SPIS_1_SET_INP_DIS(SPIS_1_spi_ss0_INP_DIS,
                                     SPIS_1_spi_ss0_MASK,
                                     (0u != (pinsInBuf & SPIS_1_SS0_PIN_MASK)));
    #endif /* (SPIS_1_SS1_PIN) */

    #if(SPIS_1_SS1_PIN)
        SPIS_1_SET_HSIOM_SEL(SPIS_1_SS1_HSIOM_REG, SPIS_1_SS1_HSIOM_MASK,
                                       SPIS_1_SS1_HSIOM_POS, hsiomSel[SPIS_1_SS1_PIN_INDEX]);

        SPIS_1_spi_ss1_SetDriveMode((uint8) pinsDm[SPIS_1_SS1_PIN_INDEX]);

        SPIS_1_SET_INP_DIS(SPIS_1_spi_ss1_INP_DIS,
                                     SPIS_1_spi_ss1_MASK,
                                     (0u != (pinsInBuf & SPIS_1_SS1_PIN_MASK)));
    #endif /* (SPIS_1_SS1_PIN) */

    #if(SPIS_1_SS2_PIN)
        SPIS_1_SET_HSIOM_SEL(SPIS_1_SS2_HSIOM_REG, SPIS_1_SS2_HSIOM_MASK,
                                       SPIS_1_SS2_HSIOM_POS, hsiomSel[SPIS_1_SS2_PIN_INDEX]);

        SPIS_1_spi_ss2_SetDriveMode((uint8) pinsDm[SPIS_1_SS2_PIN_INDEX]);

        SPIS_1_SET_INP_DIS(SPIS_1_spi_ss2_INP_DIS,
                                     SPIS_1_spi_ss2_MASK,
                                     (0u != (pinsInBuf & SPIS_1_SS2_PIN_MASK)));
    #endif /* (SPIS_1_SS2_PIN) */

    #if(SPIS_1_SS3_PIN)
        SPIS_1_SET_HSIOM_SEL(SPIS_1_SS3_HSIOM_REG,  SPIS_1_SS3_HSIOM_MASK,
                                       SPIS_1_SS3_HSIOM_POS, hsiomSel[SPIS_1_SS3_PIN_INDEX]);

        SPIS_1_spi_ss3_SetDriveMode((uint8) pinsDm[SPIS_1_SS3_PIN_INDEX]);

        SPIS_1_SET_INP_DIS(SPIS_1_spi_ss3_INP_DIS,
                                     SPIS_1_spi_ss3_MASK,
                                     (0u != (pinsInBuf & SPIS_1_SS3_PIN_MASK)));
    #endif /* (SPIS_1_SS3_PIN) */
    }

#endif /* (SPIS_1_SCB_MODE_UNCONFIG_CONST_CFG) */


/* [] END OF FILE */
