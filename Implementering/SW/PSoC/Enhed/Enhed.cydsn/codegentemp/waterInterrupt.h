/*******************************************************************************
* File Name: waterInterrupt.h
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
#if !defined(CY_ISR_waterInterrupt_H)
#define CY_ISR_waterInterrupt_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void waterInterrupt_Start(void);
void waterInterrupt_StartEx(cyisraddress address);
void waterInterrupt_Stop(void);

CY_ISR_PROTO(waterInterrupt_Interrupt);

void waterInterrupt_SetVector(cyisraddress address);
cyisraddress waterInterrupt_GetVector(void);

void waterInterrupt_SetPriority(uint8 priority);
uint8 waterInterrupt_GetPriority(void);

void waterInterrupt_Enable(void);
uint8 waterInterrupt_GetState(void);
void waterInterrupt_Disable(void);

void waterInterrupt_SetPending(void);
void waterInterrupt_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the waterInterrupt ISR. */
#define waterInterrupt_INTC_VECTOR            ((reg32 *) waterInterrupt__INTC_VECT)

/* Address of the waterInterrupt ISR priority. */
#define waterInterrupt_INTC_PRIOR             ((reg32 *) waterInterrupt__INTC_PRIOR_REG)

/* Priority of the waterInterrupt interrupt. */
#define waterInterrupt_INTC_PRIOR_NUMBER      waterInterrupt__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable waterInterrupt interrupt. */
#define waterInterrupt_INTC_SET_EN            ((reg32 *) waterInterrupt__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the waterInterrupt interrupt. */
#define waterInterrupt_INTC_CLR_EN            ((reg32 *) waterInterrupt__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the waterInterrupt interrupt state to pending. */
#define waterInterrupt_INTC_SET_PD            ((reg32 *) waterInterrupt__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the waterInterrupt interrupt. */
#define waterInterrupt_INTC_CLR_PD            ((reg32 *) waterInterrupt__INTC_CLR_PD_REG)



#endif /* CY_ISR_waterInterrupt_H */


/* [] END OF FILE */
