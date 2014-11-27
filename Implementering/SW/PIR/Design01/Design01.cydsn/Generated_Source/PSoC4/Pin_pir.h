/*******************************************************************************
* File Name: Pin_pir.h  
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

#if !defined(CY_PINS_Pin_pir_H) /* Pins Pin_pir_H */
#define CY_PINS_Pin_pir_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Pin_pir_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Pin_pir_Write(uint8 value) ;
void    Pin_pir_SetDriveMode(uint8 mode) ;
uint8   Pin_pir_ReadDataReg(void) ;
uint8   Pin_pir_Read(void) ;
uint8   Pin_pir_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Pin_pir_DRIVE_MODE_BITS        (3)
#define Pin_pir_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Pin_pir_DRIVE_MODE_BITS))
#define Pin_pir_DRIVE_MODE_SHIFT       (0x00u)
#define Pin_pir_DRIVE_MODE_MASK        (0x07u << Pin_pir_DRIVE_MODE_SHIFT)

#define Pin_pir_DM_ALG_HIZ         (0x00u << Pin_pir_DRIVE_MODE_SHIFT)
#define Pin_pir_DM_DIG_HIZ         (0x01u << Pin_pir_DRIVE_MODE_SHIFT)
#define Pin_pir_DM_RES_UP          (0x02u << Pin_pir_DRIVE_MODE_SHIFT)
#define Pin_pir_DM_RES_DWN         (0x03u << Pin_pir_DRIVE_MODE_SHIFT)
#define Pin_pir_DM_OD_LO           (0x04u << Pin_pir_DRIVE_MODE_SHIFT)
#define Pin_pir_DM_OD_HI           (0x05u << Pin_pir_DRIVE_MODE_SHIFT)
#define Pin_pir_DM_STRONG          (0x06u << Pin_pir_DRIVE_MODE_SHIFT)
#define Pin_pir_DM_RES_UPDWN       (0x07u << Pin_pir_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Pin_pir_MASK               Pin_pir__MASK
#define Pin_pir_SHIFT              Pin_pir__SHIFT
#define Pin_pir_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pin_pir_PS                     (* (reg32 *) Pin_pir__PS)
/* Port Configuration */
#define Pin_pir_PC                     (* (reg32 *) Pin_pir__PC)
/* Data Register */
#define Pin_pir_DR                     (* (reg32 *) Pin_pir__DR)
/* Input Buffer Disable Override */
#define Pin_pir_INP_DIS                (* (reg32 *) Pin_pir__PC2)


#if defined(Pin_pir__INTSTAT)  /* Interrupt Registers */

    #define Pin_pir_INTSTAT                (* (reg32 *) Pin_pir__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Pin_pir_H */


/* [] END OF FILE */
