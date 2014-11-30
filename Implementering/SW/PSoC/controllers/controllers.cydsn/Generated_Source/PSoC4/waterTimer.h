/*******************************************************************************
* File Name: waterTimer.h
* Version 2.50
*
*  Description:
*     Contains the function prototypes and constants available to the timer
*     user module.
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_Timer_v2_30_waterTimer_H)
#define CY_Timer_v2_30_waterTimer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 waterTimer_initVar;

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component Timer_v2_50 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/**************************************
*           Parameter Defaults
**************************************/

#define waterTimer_Resolution                 16u
#define waterTimer_UsingFixedFunction         0u
#define waterTimer_UsingHWCaptureCounter      0u
#define waterTimer_SoftwareCaptureMode        0u
#define waterTimer_SoftwareTriggerMode        0u
#define waterTimer_UsingHWEnable              0u
#define waterTimer_EnableTriggerMode          0u
#define waterTimer_InterruptOnCaptureCount    0u
#define waterTimer_RunModeUsed                0u
#define waterTimer_ControlRegRemoved          0u


/***************************************
*       Type defines
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for Timer Component
 *************************************************************************/
typedef struct
{
    uint8 TimerEnableState;
    #if(!waterTimer_UsingFixedFunction)
        #if (CY_UDB_V0)
            uint16 TimerUdb;                 /* Timer internal counter value */
            uint16 TimerPeriod;              /* Timer Period value       */
            uint8 InterruptMaskValue;       /* Timer Compare Value */
            #if (waterTimer_UsingHWCaptureCounter)
                uint8 TimerCaptureCounter;  /* Timer Capture Counter Value */
            #endif /* variable declaration for backing up Capture Counter value*/
        #endif /* variables for non retention registers in CY_UDB_V0 */

        #if (CY_UDB_V1)
            uint16 TimerUdb;
            uint8 InterruptMaskValue;
            #if (waterTimer_UsingHWCaptureCounter)
                uint8 TimerCaptureCounter;
            #endif /* variable declarations for backing up non retention registers in CY_UDB_V1 */
        #endif /* (CY_UDB_V1) */

        #if (!waterTimer_ControlRegRemoved)
            uint8 TimerControlRegister;
        #endif /* variable declaration for backing up enable state of the Timer */
    #endif /* define backup variables only for UDB implementation. Fixed function registers are all retention */
}waterTimer_backupStruct;


/***************************************
*       Function Prototypes
***************************************/

void    waterTimer_Start(void) ;
void    waterTimer_Stop(void) ;

void    waterTimer_SetInterruptMode(uint8 interruptMode) ;
uint8   waterTimer_ReadStatusRegister(void) ;
/* Deprecated function. Do not use this in future. Retained for backward compatibility */
#define waterTimer_GetInterruptSource() waterTimer_ReadStatusRegister()

#if(!waterTimer_ControlRegRemoved)
    uint8   waterTimer_ReadControlRegister(void) ;
    void    waterTimer_WriteControlRegister(uint8 control) \
        ;
#endif /* (!waterTimer_ControlRegRemoved) */

uint16  waterTimer_ReadPeriod(void) ;
void    waterTimer_WritePeriod(uint16 period) \
    ;
uint16  waterTimer_ReadCounter(void) ;
void    waterTimer_WriteCounter(uint16 counter) \
    ;
uint16  waterTimer_ReadCapture(void) ;
void    waterTimer_SoftwareCapture(void) ;


#if(!waterTimer_UsingFixedFunction) /* UDB Prototypes */
    #if (waterTimer_SoftwareCaptureMode)
        void    waterTimer_SetCaptureMode(uint8 captureMode) ;
    #endif /* (!waterTimer_UsingFixedFunction) */

    #if (waterTimer_SoftwareTriggerMode)
        void    waterTimer_SetTriggerMode(uint8 triggerMode) ;
    #endif /* (waterTimer_SoftwareTriggerMode) */
    #if (waterTimer_EnableTriggerMode)
        void    waterTimer_EnableTrigger(void) ;
        void    waterTimer_DisableTrigger(void) ;
    #endif /* (waterTimer_EnableTriggerMode) */

    #if(waterTimer_InterruptOnCaptureCount)
        #if(!waterTimer_ControlRegRemoved)
            void    waterTimer_SetInterruptCount(uint8 interruptCount) \
                ;
        #endif /* (!waterTimer_ControlRegRemoved) */
    #endif /* (waterTimer_InterruptOnCaptureCount) */

    #if (waterTimer_UsingHWCaptureCounter)
        void    waterTimer_SetCaptureCount(uint8 captureCount) \
            ;
        uint8   waterTimer_ReadCaptureCount(void) ;
    #endif /* (waterTimer_UsingHWCaptureCounter) */

    void waterTimer_ClearFIFO(void) ;
#endif /* UDB Prototypes */

/* Sleep Retention APIs */
void waterTimer_Init(void)          ;
void waterTimer_Enable(void)        ;
void waterTimer_SaveConfig(void)    ;
void waterTimer_RestoreConfig(void) ;
void waterTimer_Sleep(void)         ;
void waterTimer_Wakeup(void)        ;


/***************************************
*   Enumerated Types and Parameters
***************************************/

/* Enumerated Type B_Timer__CaptureModes, Used in Capture Mode */
#define waterTimer__B_TIMER__CM_NONE 0
#define waterTimer__B_TIMER__CM_RISINGEDGE 1
#define waterTimer__B_TIMER__CM_FALLINGEDGE 2
#define waterTimer__B_TIMER__CM_EITHEREDGE 3
#define waterTimer__B_TIMER__CM_SOFTWARE 4



/* Enumerated Type B_Timer__TriggerModes, Used in Trigger Mode */
#define waterTimer__B_TIMER__TM_NONE 0x00u
#define waterTimer__B_TIMER__TM_RISINGEDGE 0x04u
#define waterTimer__B_TIMER__TM_FALLINGEDGE 0x08u
#define waterTimer__B_TIMER__TM_EITHEREDGE 0x0Cu
#define waterTimer__B_TIMER__TM_SOFTWARE 0x10u


/***************************************
*    Initialial Parameter Constants
***************************************/

#define waterTimer_INIT_PERIOD             65535u
#define waterTimer_INIT_CAPTURE_MODE       ((uint8)((uint8)0u << waterTimer_CTRL_CAP_MODE_SHIFT))
#define waterTimer_INIT_TRIGGER_MODE       ((uint8)((uint8)0u << waterTimer_CTRL_TRIG_MODE_SHIFT))
#if (waterTimer_UsingFixedFunction)
    #define waterTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << waterTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                  ((uint8)((uint8)0 << waterTimer_STATUS_CAPTURE_INT_MASK_SHIFT)))
#else
    #define waterTimer_INIT_INTERRUPT_MODE (((uint8)((uint8)0u << waterTimer_STATUS_TC_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << waterTimer_STATUS_CAPTURE_INT_MASK_SHIFT)) | \
                                                 ((uint8)((uint8)0 << waterTimer_STATUS_FIFOFULL_INT_MASK_SHIFT)))
#endif /* (waterTimer_UsingFixedFunction) */
#define waterTimer_INIT_CAPTURE_COUNT      (2u)
#define waterTimer_INIT_INT_CAPTURE_COUNT  ((uint8)((uint8)(1u - 1u) << waterTimer_CTRL_INTCNT_SHIFT))


/***************************************
*           Registers
***************************************/

#if (waterTimer_UsingFixedFunction) /* Implementation Specific Registers and Register Constants */


    /***************************************
    *    Fixed Function Registers
    ***************************************/

    #define waterTimer_STATUS         (*(reg8 *) waterTimer_TimerHW__SR0 )
    /* In Fixed Function Block Status and Mask are the same register */
    #define waterTimer_STATUS_MASK    (*(reg8 *) waterTimer_TimerHW__SR0 )
    #define waterTimer_CONTROL        (*(reg8 *) waterTimer_TimerHW__CFG0)
    #define waterTimer_CONTROL2       (*(reg8 *) waterTimer_TimerHW__CFG1)
    #define waterTimer_CONTROL2_PTR   ( (reg8 *) waterTimer_TimerHW__CFG1)
    #define waterTimer_RT1            (*(reg8 *) waterTimer_TimerHW__RT1)
    #define waterTimer_RT1_PTR        ( (reg8 *) waterTimer_TimerHW__RT1)

    #if (CY_PSOC3 || CY_PSOC5LP)
        #define waterTimer_CONTROL3       (*(reg8 *) waterTimer_TimerHW__CFG2)
        #define waterTimer_CONTROL3_PTR   ( (reg8 *) waterTimer_TimerHW__CFG2)
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */
    #define waterTimer_GLOBAL_ENABLE  (*(reg8 *) waterTimer_TimerHW__PM_ACT_CFG)
    #define waterTimer_GLOBAL_STBY_ENABLE  (*(reg8 *) waterTimer_TimerHW__PM_STBY_CFG)

    #define waterTimer_CAPTURE_LSB         (* (reg16 *) waterTimer_TimerHW__CAP0 )
    #define waterTimer_CAPTURE_LSB_PTR       ((reg16 *) waterTimer_TimerHW__CAP0 )
    #define waterTimer_PERIOD_LSB          (* (reg16 *) waterTimer_TimerHW__PER0 )
    #define waterTimer_PERIOD_LSB_PTR        ((reg16 *) waterTimer_TimerHW__PER0 )
    #define waterTimer_COUNTER_LSB         (* (reg16 *) waterTimer_TimerHW__CNT_CMP0 )
    #define waterTimer_COUNTER_LSB_PTR       ((reg16 *) waterTimer_TimerHW__CNT_CMP0 )


    /***************************************
    *    Register Constants
    ***************************************/

    /* Fixed Function Block Chosen */
    #define waterTimer_BLOCK_EN_MASK                     waterTimer_TimerHW__PM_ACT_MSK
    #define waterTimer_BLOCK_STBY_EN_MASK                waterTimer_TimerHW__PM_STBY_MSK

    /* Control Register Bit Locations */
    /* Interrupt Count - Not valid for Fixed Function Block */
    #define waterTimer_CTRL_INTCNT_SHIFT                  0x00u
    /* Trigger Polarity - Not valid for Fixed Function Block */
    #define waterTimer_CTRL_TRIG_MODE_SHIFT               0x00u
    /* Trigger Enable - Not valid for Fixed Function Block */
    #define waterTimer_CTRL_TRIG_EN_SHIFT                 0x00u
    /* Capture Polarity - Not valid for Fixed Function Block */
    #define waterTimer_CTRL_CAP_MODE_SHIFT                0x00u
    /* Timer Enable - As defined in Register Map, part of TMRX_CFG0 register */
    #define waterTimer_CTRL_ENABLE_SHIFT                  0x00u

    /* Control Register Bit Masks */
    #define waterTimer_CTRL_ENABLE                        ((uint8)((uint8)0x01u << waterTimer_CTRL_ENABLE_SHIFT))

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define waterTimer_CTRL2_IRQ_SEL_SHIFT                 0x00u
    #define waterTimer_CTRL2_IRQ_SEL                      ((uint8)((uint8)0x01u << waterTimer_CTRL2_IRQ_SEL_SHIFT))

    #if (CY_PSOC5A)
        /* Use CFG1 Mode bits to set run mode */
        /* As defined by Verilog Implementation */
        #define waterTimer_CTRL_MODE_SHIFT                     0x01u
        #define waterTimer_CTRL_MODE_MASK                     ((uint8)((uint8)0x07u << waterTimer_CTRL_MODE_SHIFT))
    #endif /* (CY_PSOC5A) */
    #if (CY_PSOC3 || CY_PSOC5LP)
        /* Control3 Register Bit Locations */
        #define waterTimer_CTRL_RCOD_SHIFT        0x02u
        #define waterTimer_CTRL_ENBL_SHIFT        0x00u
        #define waterTimer_CTRL_MODE_SHIFT        0x00u

        /* Control3 Register Bit Masks */
        #define waterTimer_CTRL_RCOD_MASK  ((uint8)((uint8)0x03u << waterTimer_CTRL_RCOD_SHIFT)) /* ROD and COD bit masks */
        #define waterTimer_CTRL_ENBL_MASK  ((uint8)((uint8)0x80u << waterTimer_CTRL_ENBL_SHIFT)) /* HW_EN bit mask */
        #define waterTimer_CTRL_MODE_MASK  ((uint8)((uint8)0x03u << waterTimer_CTRL_MODE_SHIFT)) /* Run mode bit mask */

        #define waterTimer_CTRL_RCOD       ((uint8)((uint8)0x03u << waterTimer_CTRL_RCOD_SHIFT))
        #define waterTimer_CTRL_ENBL       ((uint8)((uint8)0x80u << waterTimer_CTRL_ENBL_SHIFT))
    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

    /*RT1 Synch Constants: Applicable for PSoC3 and PSoC5LP */
    #define waterTimer_RT1_SHIFT                       0x04u
    /* Sync TC and CMP bit masks */
    #define waterTimer_RT1_MASK                        ((uint8)((uint8)0x03u << waterTimer_RT1_SHIFT))
    #define waterTimer_SYNC                            ((uint8)((uint8)0x03u << waterTimer_RT1_SHIFT))
    #define waterTimer_SYNCDSI_SHIFT                   0x00u
    /* Sync all DSI inputs with Mask  */
    #define waterTimer_SYNCDSI_MASK                    ((uint8)((uint8)0x0Fu << waterTimer_SYNCDSI_SHIFT))
    /* Sync all DSI inputs */
    #define waterTimer_SYNCDSI_EN                      ((uint8)((uint8)0x0Fu << waterTimer_SYNCDSI_SHIFT))

    #define waterTimer_CTRL_MODE_PULSEWIDTH            ((uint8)((uint8)0x01u << waterTimer_CTRL_MODE_SHIFT))
    #define waterTimer_CTRL_MODE_PERIOD                ((uint8)((uint8)0x02u << waterTimer_CTRL_MODE_SHIFT))
    #define waterTimer_CTRL_MODE_CONTINUOUS            ((uint8)((uint8)0x00u << waterTimer_CTRL_MODE_SHIFT))

    /* Status Register Bit Locations */
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define waterTimer_STATUS_TC_SHIFT                 0x07u
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define waterTimer_STATUS_CAPTURE_SHIFT            0x06u
    /* As defined in Register Map, part of TMRX_SR0 register */
    #define waterTimer_STATUS_TC_INT_MASK_SHIFT        (waterTimer_STATUS_TC_SHIFT - 0x04u)
    /* As defined in Register Map, part of TMRX_SR0 register, Shared with Compare Status */
    #define waterTimer_STATUS_CAPTURE_INT_MASK_SHIFT   (waterTimer_STATUS_CAPTURE_SHIFT - 0x04u)

    /* Status Register Bit Masks */
    #define waterTimer_STATUS_TC                       ((uint8)((uint8)0x01u << waterTimer_STATUS_TC_SHIFT))
    #define waterTimer_STATUS_CAPTURE                  ((uint8)((uint8)0x01u << waterTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on TC */
    #define waterTimer_STATUS_TC_INT_MASK              ((uint8)((uint8)0x01u << waterTimer_STATUS_TC_INT_MASK_SHIFT))
    /* Interrupt Enable Bit-Mask for interrupt on Capture */
    #define waterTimer_STATUS_CAPTURE_INT_MASK         ((uint8)((uint8)0x01u << waterTimer_STATUS_CAPTURE_INT_MASK_SHIFT))

#else   /* UDB Registers and Register Constants */


    /***************************************
    *           UDB Registers
    ***************************************/

    #define waterTimer_STATUS              (* (reg8 *) waterTimer_TimerUDB_rstSts_stsreg__STATUS_REG )
    #define waterTimer_STATUS_MASK         (* (reg8 *) waterTimer_TimerUDB_rstSts_stsreg__MASK_REG)
    #define waterTimer_STATUS_AUX_CTRL     (* (reg8 *) waterTimer_TimerUDB_rstSts_stsreg__STATUS_AUX_CTL_REG)
    #define waterTimer_CONTROL             (* (reg8 *) waterTimer_TimerUDB_sCTRLReg_SyncCtl_ctrlreg__CONTROL_REG )
    
    #if(waterTimer_Resolution <= 8u) /* 8-bit Timer */
        #define waterTimer_CAPTURE_LSB         (* (reg8 *) waterTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define waterTimer_CAPTURE_LSB_PTR       ((reg8 *) waterTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define waterTimer_PERIOD_LSB          (* (reg8 *) waterTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define waterTimer_PERIOD_LSB_PTR        ((reg8 *) waterTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define waterTimer_COUNTER_LSB         (* (reg8 *) waterTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define waterTimer_COUNTER_LSB_PTR       ((reg8 *) waterTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
    #elif(waterTimer_Resolution <= 16u) /* 8-bit Timer */
        #if(CY_PSOC3) /* 8-bit addres space */
            #define waterTimer_CAPTURE_LSB         (* (reg16 *) waterTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define waterTimer_CAPTURE_LSB_PTR       ((reg16 *) waterTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define waterTimer_PERIOD_LSB          (* (reg16 *) waterTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define waterTimer_PERIOD_LSB_PTR        ((reg16 *) waterTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define waterTimer_COUNTER_LSB         (* (reg16 *) waterTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define waterTimer_COUNTER_LSB_PTR       ((reg16 *) waterTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 16-bit address space */
            #define waterTimer_CAPTURE_LSB         (* (reg16 *) waterTimer_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define waterTimer_CAPTURE_LSB_PTR       ((reg16 *) waterTimer_TimerUDB_sT16_timerdp_u0__16BIT_F0_REG )
            #define waterTimer_PERIOD_LSB          (* (reg16 *) waterTimer_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define waterTimer_PERIOD_LSB_PTR        ((reg16 *) waterTimer_TimerUDB_sT16_timerdp_u0__16BIT_D0_REG )
            #define waterTimer_COUNTER_LSB         (* (reg16 *) waterTimer_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
            #define waterTimer_COUNTER_LSB_PTR       ((reg16 *) waterTimer_TimerUDB_sT16_timerdp_u0__16BIT_A0_REG )
        #endif /* CY_PSOC3 */
    #elif(waterTimer_Resolution <= 24u)/* 24-bit Timer */
        #define waterTimer_CAPTURE_LSB         (* (reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define waterTimer_CAPTURE_LSB_PTR       ((reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
        #define waterTimer_PERIOD_LSB          (* (reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define waterTimer_PERIOD_LSB_PTR        ((reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
        #define waterTimer_COUNTER_LSB         (* (reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
        #define waterTimer_COUNTER_LSB_PTR       ((reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
    #else /* 32-bit Timer */
        #if(CY_PSOC3 || CY_PSOC5) /* 8-bit address space */
            #define waterTimer_CAPTURE_LSB         (* (reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define waterTimer_CAPTURE_LSB_PTR       ((reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__F0_REG )
            #define waterTimer_PERIOD_LSB          (* (reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define waterTimer_PERIOD_LSB_PTR        ((reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__D0_REG )
            #define waterTimer_COUNTER_LSB         (* (reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
            #define waterTimer_COUNTER_LSB_PTR       ((reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__A0_REG )
        #else /* 32-bit address space */
            #define waterTimer_CAPTURE_LSB         (* (reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define waterTimer_CAPTURE_LSB_PTR       ((reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__32BIT_F0_REG )
            #define waterTimer_PERIOD_LSB          (* (reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define waterTimer_PERIOD_LSB_PTR        ((reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__32BIT_D0_REG )
            #define waterTimer_COUNTER_LSB         (* (reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
            #define waterTimer_COUNTER_LSB_PTR       ((reg32 *) waterTimer_TimerUDB_sT16_timerdp_u0__32BIT_A0_REG )
        #endif /* CY_PSOC3 || CY_PSOC5 */ 
    #endif

    #if (waterTimer_UsingHWCaptureCounter)
        #define waterTimer_CAP_COUNT              (*(reg8 *) waterTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define waterTimer_CAP_COUNT_PTR          ( (reg8 *) waterTimer_TimerUDB_sCapCount_counter__PERIOD_REG )
        #define waterTimer_CAPTURE_COUNT_CTRL     (*(reg8 *) waterTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
        #define waterTimer_CAPTURE_COUNT_CTRL_PTR ( (reg8 *) waterTimer_TimerUDB_sCapCount_counter__CONTROL_AUX_CTL_REG )
    #endif /* (waterTimer_UsingHWCaptureCounter) */


    /***************************************
    *       Register Constants
    ***************************************/

    /* Control Register Bit Locations */
    #define waterTimer_CTRL_INTCNT_SHIFT              0x00u       /* As defined by Verilog Implementation */
    #define waterTimer_CTRL_TRIG_MODE_SHIFT           0x02u       /* As defined by Verilog Implementation */
    #define waterTimer_CTRL_TRIG_EN_SHIFT             0x04u       /* As defined by Verilog Implementation */
    #define waterTimer_CTRL_CAP_MODE_SHIFT            0x05u       /* As defined by Verilog Implementation */
    #define waterTimer_CTRL_ENABLE_SHIFT              0x07u       /* As defined by Verilog Implementation */

    /* Control Register Bit Masks */
    #define waterTimer_CTRL_INTCNT_MASK               ((uint8)((uint8)0x03u << waterTimer_CTRL_INTCNT_SHIFT))
    #define waterTimer_CTRL_TRIG_MODE_MASK            ((uint8)((uint8)0x03u << waterTimer_CTRL_TRIG_MODE_SHIFT))
    #define waterTimer_CTRL_TRIG_EN                   ((uint8)((uint8)0x01u << waterTimer_CTRL_TRIG_EN_SHIFT))
    #define waterTimer_CTRL_CAP_MODE_MASK             ((uint8)((uint8)0x03u << waterTimer_CTRL_CAP_MODE_SHIFT))
    #define waterTimer_CTRL_ENABLE                    ((uint8)((uint8)0x01u << waterTimer_CTRL_ENABLE_SHIFT))

    /* Bit Counter (7-bit) Control Register Bit Definitions */
    /* As defined by the Register map for the AUX Control Register */
    #define waterTimer_CNTR_ENABLE                    0x20u

    /* Status Register Bit Locations */
    #define waterTimer_STATUS_TC_SHIFT                0x00u  /* As defined by Verilog Implementation */
    #define waterTimer_STATUS_CAPTURE_SHIFT           0x01u  /* As defined by Verilog Implementation */
    #define waterTimer_STATUS_TC_INT_MASK_SHIFT       waterTimer_STATUS_TC_SHIFT
    #define waterTimer_STATUS_CAPTURE_INT_MASK_SHIFT  waterTimer_STATUS_CAPTURE_SHIFT
    #define waterTimer_STATUS_FIFOFULL_SHIFT          0x02u  /* As defined by Verilog Implementation */
    #define waterTimer_STATUS_FIFONEMP_SHIFT          0x03u  /* As defined by Verilog Implementation */
    #define waterTimer_STATUS_FIFOFULL_INT_MASK_SHIFT waterTimer_STATUS_FIFOFULL_SHIFT

    /* Status Register Bit Masks */
    /* Sticky TC Event Bit-Mask */
    #define waterTimer_STATUS_TC                      ((uint8)((uint8)0x01u << waterTimer_STATUS_TC_SHIFT))
    /* Sticky Capture Event Bit-Mask */
    #define waterTimer_STATUS_CAPTURE                 ((uint8)((uint8)0x01u << waterTimer_STATUS_CAPTURE_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define waterTimer_STATUS_TC_INT_MASK             ((uint8)((uint8)0x01u << waterTimer_STATUS_TC_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define waterTimer_STATUS_CAPTURE_INT_MASK        ((uint8)((uint8)0x01u << waterTimer_STATUS_CAPTURE_SHIFT))
    /* NOT-Sticky FIFO Full Bit-Mask */
    #define waterTimer_STATUS_FIFOFULL                ((uint8)((uint8)0x01u << waterTimer_STATUS_FIFOFULL_SHIFT))
    /* NOT-Sticky FIFO Not Empty Bit-Mask */
    #define waterTimer_STATUS_FIFONEMP                ((uint8)((uint8)0x01u << waterTimer_STATUS_FIFONEMP_SHIFT))
    /* Interrupt Enable Bit-Mask */
    #define waterTimer_STATUS_FIFOFULL_INT_MASK       ((uint8)((uint8)0x01u << waterTimer_STATUS_FIFOFULL_SHIFT))

    #define waterTimer_STATUS_ACTL_INT_EN             0x10u   /* As defined for the ACTL Register */

    /* Datapath Auxillary Control Register definitions */
    #define waterTimer_AUX_CTRL_FIFO0_CLR             0x01u   /* As defined by Register map */
    #define waterTimer_AUX_CTRL_FIFO1_CLR             0x02u   /* As defined by Register map */
    #define waterTimer_AUX_CTRL_FIFO0_LVL             0x04u   /* As defined by Register map */
    #define waterTimer_AUX_CTRL_FIFO1_LVL             0x08u   /* As defined by Register map */
    #define waterTimer_STATUS_ACTL_INT_EN_MASK        0x10u   /* As defined for the ACTL Register */

#endif /* Implementation Specific Registers and Register Constants */

#endif  /* CY_Timer_v2_30_waterTimer_H */


/* [] END OF FILE */
