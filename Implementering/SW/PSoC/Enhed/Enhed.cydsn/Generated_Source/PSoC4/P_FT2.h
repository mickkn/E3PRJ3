/*******************************************************************************
* File Name: P_FT2.h  
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

#if !defined(CY_PINS_P_FT2_H) /* Pins P_FT2_H */
#define CY_PINS_P_FT2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "P_FT2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    P_FT2_Write(uint8 value) ;
void    P_FT2_SetDriveMode(uint8 mode) ;
uint8   P_FT2_ReadDataReg(void) ;
uint8   P_FT2_Read(void) ;
uint8   P_FT2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define P_FT2_DRIVE_MODE_BITS        (3)
#define P_FT2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - P_FT2_DRIVE_MODE_BITS))
#define P_FT2_DRIVE_MODE_SHIFT       (0x00u)
#define P_FT2_DRIVE_MODE_MASK        (0x07u << P_FT2_DRIVE_MODE_SHIFT)

#define P_FT2_DM_ALG_HIZ         (0x00u << P_FT2_DRIVE_MODE_SHIFT)
#define P_FT2_DM_DIG_HIZ         (0x01u << P_FT2_DRIVE_MODE_SHIFT)
#define P_FT2_DM_RES_UP          (0x02u << P_FT2_DRIVE_MODE_SHIFT)
#define P_FT2_DM_RES_DWN         (0x03u << P_FT2_DRIVE_MODE_SHIFT)
#define P_FT2_DM_OD_LO           (0x04u << P_FT2_DRIVE_MODE_SHIFT)
#define P_FT2_DM_OD_HI           (0x05u << P_FT2_DRIVE_MODE_SHIFT)
#define P_FT2_DM_STRONG          (0x06u << P_FT2_DRIVE_MODE_SHIFT)
#define P_FT2_DM_RES_UPDWN       (0x07u << P_FT2_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define P_FT2_MASK               P_FT2__MASK
#define P_FT2_SHIFT              P_FT2__SHIFT
#define P_FT2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define P_FT2_PS                     (* (reg32 *) P_FT2__PS)
/* Port Configuration */
#define P_FT2_PC                     (* (reg32 *) P_FT2__PC)
/* Data Register */
#define P_FT2_DR                     (* (reg32 *) P_FT2__DR)
/* Input Buffer Disable Override */
#define P_FT2_INP_DIS                (* (reg32 *) P_FT2__PC2)


#if defined(P_FT2__INTSTAT)  /* Interrupt Registers */

    #define P_FT2_INTSTAT                (* (reg32 *) P_FT2__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins P_FT2_H */


/* [] END OF FILE */
