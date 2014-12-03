/*******************************************************************************
* File Name: logDataInterrupt.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_logDataInterrupt_H)
#define CY_ISR_logDataInterrupt_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void logDataInterrupt_Start(void);
void logDataInterrupt_StartEx(cyisraddress address);
void logDataInterrupt_Stop(void);

CY_ISR_PROTO(logDataInterrupt_Interrupt);

void logDataInterrupt_SetVector(cyisraddress address);
cyisraddress logDataInterrupt_GetVector(void);

void logDataInterrupt_SetPriority(uint8 priority);
uint8 logDataInterrupt_GetPriority(void);

void logDataInterrupt_Enable(void);
uint8 logDataInterrupt_GetState(void);
void logDataInterrupt_Disable(void);

void logDataInterrupt_SetPending(void);
void logDataInterrupt_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the logDataInterrupt ISR. */
#define logDataInterrupt_INTC_VECTOR            ((reg32 *) logDataInterrupt__INTC_VECT)

/* Address of the logDataInterrupt ISR priority. */
#define logDataInterrupt_INTC_PRIOR             ((reg32 *) logDataInterrupt__INTC_PRIOR_REG)

/* Priority of the logDataInterrupt interrupt. */
#define logDataInterrupt_INTC_PRIOR_NUMBER      logDataInterrupt__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable logDataInterrupt interrupt. */
#define logDataInterrupt_INTC_SET_EN            ((reg32 *) logDataInterrupt__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the logDataInterrupt interrupt. */
#define logDataInterrupt_INTC_CLR_EN            ((reg32 *) logDataInterrupt__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the logDataInterrupt interrupt state to pending. */
#define logDataInterrupt_INTC_SET_PD            ((reg32 *) logDataInterrupt__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the logDataInterrupt interrupt. */
#define logDataInterrupt_INTC_CLR_PD            ((reg32 *) logDataInterrupt__INTC_CLR_PD_REG)



#endif /* CY_ISR_logDataInterrupt_H */


/* [] END OF FILE */
