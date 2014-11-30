/*******************************************************************************
* File Name: ADC_in.h  
* Version 2.0
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ADC_in_H) /* Pins ADC_in_H */
#define CY_PINS_ADC_in_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ADC_in_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ADC_in_Write(uint8 value) ;
void    ADC_in_SetDriveMode(uint8 mode) ;
uint8   ADC_in_ReadDataReg(void) ;
uint8   ADC_in_Read(void) ;
uint8   ADC_in_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ADC_in_DRIVE_MODE_BITS        (3)
#define ADC_in_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ADC_in_DRIVE_MODE_BITS))
#define ADC_in_DRIVE_MODE_SHIFT       (0x00u)
#define ADC_in_DRIVE_MODE_MASK        (0x07u << ADC_in_DRIVE_MODE_SHIFT)

#define ADC_in_DM_ALG_HIZ         (0x00u << ADC_in_DRIVE_MODE_SHIFT)
#define ADC_in_DM_DIG_HIZ         (0x01u << ADC_in_DRIVE_MODE_SHIFT)
#define ADC_in_DM_RES_UP          (0x02u << ADC_in_DRIVE_MODE_SHIFT)
#define ADC_in_DM_RES_DWN         (0x03u << ADC_in_DRIVE_MODE_SHIFT)
#define ADC_in_DM_OD_LO           (0x04u << ADC_in_DRIVE_MODE_SHIFT)
#define ADC_in_DM_OD_HI           (0x05u << ADC_in_DRIVE_MODE_SHIFT)
#define ADC_in_DM_STRONG          (0x06u << ADC_in_DRIVE_MODE_SHIFT)
#define ADC_in_DM_RES_UPDWN       (0x07u << ADC_in_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define ADC_in_MASK               ADC_in__MASK
#define ADC_in_SHIFT              ADC_in__SHIFT
#define ADC_in_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADC_in_PS                     (* (reg32 *) ADC_in__PS)
/* Port Configuration */
#define ADC_in_PC                     (* (reg32 *) ADC_in__PC)
/* Data Register */
#define ADC_in_DR                     (* (reg32 *) ADC_in__DR)
/* Input Buffer Disable Override */
#define ADC_in_INP_DIS                (* (reg32 *) ADC_in__PC2)


#if defined(ADC_in__INTSTAT)  /* Interrupt Registers */

    #define ADC_in_INTSTAT                (* (reg32 *) ADC_in__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins ADC_in_H */


/* [] END OF FILE */
