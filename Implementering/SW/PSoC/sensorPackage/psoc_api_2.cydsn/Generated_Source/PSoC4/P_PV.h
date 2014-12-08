/*******************************************************************************
* File Name: P_PV.h  
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

#if !defined(CY_PINS_P_PV_H) /* Pins P_PV_H */
#define CY_PINS_P_PV_H

#include "cytypes.h"
#include "cyfitter.h"
#include "P_PV_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    P_PV_Write(uint8 value) ;
void    P_PV_SetDriveMode(uint8 mode) ;
uint8   P_PV_ReadDataReg(void) ;
uint8   P_PV_Read(void) ;
uint8   P_PV_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define P_PV_DRIVE_MODE_BITS        (3)
#define P_PV_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - P_PV_DRIVE_MODE_BITS))
#define P_PV_DRIVE_MODE_SHIFT       (0x00u)
#define P_PV_DRIVE_MODE_MASK        (0x07u << P_PV_DRIVE_MODE_SHIFT)

#define P_PV_DM_ALG_HIZ         (0x00u << P_PV_DRIVE_MODE_SHIFT)
#define P_PV_DM_DIG_HIZ         (0x01u << P_PV_DRIVE_MODE_SHIFT)
#define P_PV_DM_RES_UP          (0x02u << P_PV_DRIVE_MODE_SHIFT)
#define P_PV_DM_RES_DWN         (0x03u << P_PV_DRIVE_MODE_SHIFT)
#define P_PV_DM_OD_LO           (0x04u << P_PV_DRIVE_MODE_SHIFT)
#define P_PV_DM_OD_HI           (0x05u << P_PV_DRIVE_MODE_SHIFT)
#define P_PV_DM_STRONG          (0x06u << P_PV_DRIVE_MODE_SHIFT)
#define P_PV_DM_RES_UPDWN       (0x07u << P_PV_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define P_PV_MASK               P_PV__MASK
#define P_PV_SHIFT              P_PV__SHIFT
#define P_PV_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define P_PV_PS                     (* (reg32 *) P_PV__PS)
/* Port Configuration */
#define P_PV_PC                     (* (reg32 *) P_PV__PC)
/* Data Register */
#define P_PV_DR                     (* (reg32 *) P_PV__DR)
/* Input Buffer Disable Override */
#define P_PV_INP_DIS                (* (reg32 *) P_PV__PC2)


#if defined(P_PV__INTSTAT)  /* Interrupt Registers */

    #define P_PV_INTSTAT                (* (reg32 *) P_PV__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins P_PV_H */


/* [] END OF FILE */
