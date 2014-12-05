/*******************************************************************************
* File Name: TP_1.h  
* Version 2.5
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

#if !defined(CY_PINS_TP_1_H) /* Pins TP_1_H */
#define CY_PINS_TP_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "TP_1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    TP_1_Write(uint8 value) ;
void    TP_1_SetDriveMode(uint8 mode) ;
uint8   TP_1_ReadDataReg(void) ;
uint8   TP_1_Read(void) ;
uint8   TP_1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define TP_1_DRIVE_MODE_BITS        (3)
#define TP_1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - TP_1_DRIVE_MODE_BITS))
#define TP_1_DRIVE_MODE_SHIFT       (0x00u)
#define TP_1_DRIVE_MODE_MASK        (0x07u << TP_1_DRIVE_MODE_SHIFT)

#define TP_1_DM_ALG_HIZ         (0x00u << TP_1_DRIVE_MODE_SHIFT)
#define TP_1_DM_DIG_HIZ         (0x01u << TP_1_DRIVE_MODE_SHIFT)
#define TP_1_DM_RES_UP          (0x02u << TP_1_DRIVE_MODE_SHIFT)
#define TP_1_DM_RES_DWN         (0x03u << TP_1_DRIVE_MODE_SHIFT)
#define TP_1_DM_OD_LO           (0x04u << TP_1_DRIVE_MODE_SHIFT)
#define TP_1_DM_OD_HI           (0x05u << TP_1_DRIVE_MODE_SHIFT)
#define TP_1_DM_STRONG          (0x06u << TP_1_DRIVE_MODE_SHIFT)
#define TP_1_DM_RES_UPDWN       (0x07u << TP_1_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define TP_1_MASK               TP_1__MASK
#define TP_1_SHIFT              TP_1__SHIFT
#define TP_1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define TP_1_PS                     (* (reg32 *) TP_1__PS)
/* Port Configuration */
#define TP_1_PC                     (* (reg32 *) TP_1__PC)
/* Data Register */
#define TP_1_DR                     (* (reg32 *) TP_1__DR)
/* Input Buffer Disable Override */
#define TP_1_INP_DIS                (* (reg32 *) TP_1__PC2)


#if defined(TP_1__INTSTAT)  /* Interrupt Registers */

    #define TP_1_INTSTAT                (* (reg32 *) TP_1__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins TP_1_H */


/* [] END OF FILE */
