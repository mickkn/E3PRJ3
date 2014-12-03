/*******************************************************************************
* File Name: P_FT1.h  
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

#if !defined(CY_PINS_P_FT1_H) /* Pins P_FT1_H */
#define CY_PINS_P_FT1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "P_FT1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    P_FT1_Write(uint8 value) ;
void    P_FT1_SetDriveMode(uint8 mode) ;
uint8   P_FT1_ReadDataReg(void) ;
uint8   P_FT1_Read(void) ;
uint8   P_FT1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define P_FT1_DRIVE_MODE_BITS        (3)
#define P_FT1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - P_FT1_DRIVE_MODE_BITS))
#define P_FT1_DRIVE_MODE_SHIFT       (0x00u)
#define P_FT1_DRIVE_MODE_MASK        (0x07u << P_FT1_DRIVE_MODE_SHIFT)

#define P_FT1_DM_ALG_HIZ         (0x00u << P_FT1_DRIVE_MODE_SHIFT)
#define P_FT1_DM_DIG_HIZ         (0x01u << P_FT1_DRIVE_MODE_SHIFT)
#define P_FT1_DM_RES_UP          (0x02u << P_FT1_DRIVE_MODE_SHIFT)
#define P_FT1_DM_RES_DWN         (0x03u << P_FT1_DRIVE_MODE_SHIFT)
#define P_FT1_DM_OD_LO           (0x04u << P_FT1_DRIVE_MODE_SHIFT)
#define P_FT1_DM_OD_HI           (0x05u << P_FT1_DRIVE_MODE_SHIFT)
#define P_FT1_DM_STRONG          (0x06u << P_FT1_DRIVE_MODE_SHIFT)
#define P_FT1_DM_RES_UPDWN       (0x07u << P_FT1_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define P_FT1_MASK               P_FT1__MASK
#define P_FT1_SHIFT              P_FT1__SHIFT
#define P_FT1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define P_FT1_PS                     (* (reg32 *) P_FT1__PS)
/* Port Configuration */
#define P_FT1_PC                     (* (reg32 *) P_FT1__PC)
/* Data Register */
#define P_FT1_DR                     (* (reg32 *) P_FT1__DR)
/* Input Buffer Disable Override */
#define P_FT1_INP_DIS                (* (reg32 *) P_FT1__PC2)


#if defined(P_FT1__INTSTAT)  /* Interrupt Registers */

    #define P_FT1_INTSTAT                (* (reg32 *) P_FT1__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins P_FT1_H */


/* [] END OF FILE */
