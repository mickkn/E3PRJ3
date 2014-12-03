/*******************************************************************************
* File Name: P_VP.h  
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

#if !defined(CY_PINS_P_VP_H) /* Pins P_VP_H */
#define CY_PINS_P_VP_H

#include "cytypes.h"
#include "cyfitter.h"
#include "P_VP_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    P_VP_Write(uint8 value) ;
void    P_VP_SetDriveMode(uint8 mode) ;
uint8   P_VP_ReadDataReg(void) ;
uint8   P_VP_Read(void) ;
uint8   P_VP_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define P_VP_DRIVE_MODE_BITS        (3)
#define P_VP_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - P_VP_DRIVE_MODE_BITS))
#define P_VP_DRIVE_MODE_SHIFT       (0x00u)
#define P_VP_DRIVE_MODE_MASK        (0x07u << P_VP_DRIVE_MODE_SHIFT)

#define P_VP_DM_ALG_HIZ         (0x00u << P_VP_DRIVE_MODE_SHIFT)
#define P_VP_DM_DIG_HIZ         (0x01u << P_VP_DRIVE_MODE_SHIFT)
#define P_VP_DM_RES_UP          (0x02u << P_VP_DRIVE_MODE_SHIFT)
#define P_VP_DM_RES_DWN         (0x03u << P_VP_DRIVE_MODE_SHIFT)
#define P_VP_DM_OD_LO           (0x04u << P_VP_DRIVE_MODE_SHIFT)
#define P_VP_DM_OD_HI           (0x05u << P_VP_DRIVE_MODE_SHIFT)
#define P_VP_DM_STRONG          (0x06u << P_VP_DRIVE_MODE_SHIFT)
#define P_VP_DM_RES_UPDWN       (0x07u << P_VP_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define P_VP_MASK               P_VP__MASK
#define P_VP_SHIFT              P_VP__SHIFT
#define P_VP_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define P_VP_PS                     (* (reg32 *) P_VP__PS)
/* Port Configuration */
#define P_VP_PC                     (* (reg32 *) P_VP__PC)
/* Data Register */
#define P_VP_DR                     (* (reg32 *) P_VP__DR)
/* Input Buffer Disable Override */
#define P_VP_INP_DIS                (* (reg32 *) P_VP__PC2)


#if defined(P_VP__INTSTAT)  /* Interrupt Registers */

    #define P_VP_INTSTAT                (* (reg32 *) P_VP__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins P_VP_H */


/* [] END OF FILE */
