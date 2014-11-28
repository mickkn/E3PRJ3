/*******************************************************************************
* File Name: SLC.h  
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

#if !defined(CY_PINS_SLC_H) /* Pins SLC_H */
#define CY_PINS_SLC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SLC_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SLC_Write(uint8 value) ;
void    SLC_SetDriveMode(uint8 mode) ;
uint8   SLC_ReadDataReg(void) ;
uint8   SLC_Read(void) ;
uint8   SLC_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SLC_DRIVE_MODE_BITS        (3)
#define SLC_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SLC_DRIVE_MODE_BITS))
#define SLC_DRIVE_MODE_SHIFT       (0x00u)
#define SLC_DRIVE_MODE_MASK        (0x07u << SLC_DRIVE_MODE_SHIFT)

#define SLC_DM_ALG_HIZ         (0x00u << SLC_DRIVE_MODE_SHIFT)
#define SLC_DM_DIG_HIZ         (0x01u << SLC_DRIVE_MODE_SHIFT)
#define SLC_DM_RES_UP          (0x02u << SLC_DRIVE_MODE_SHIFT)
#define SLC_DM_RES_DWN         (0x03u << SLC_DRIVE_MODE_SHIFT)
#define SLC_DM_OD_LO           (0x04u << SLC_DRIVE_MODE_SHIFT)
#define SLC_DM_OD_HI           (0x05u << SLC_DRIVE_MODE_SHIFT)
#define SLC_DM_STRONG          (0x06u << SLC_DRIVE_MODE_SHIFT)
#define SLC_DM_RES_UPDWN       (0x07u << SLC_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define SLC_MASK               SLC__MASK
#define SLC_SHIFT              SLC__SHIFT
#define SLC_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SLC_PS                     (* (reg32 *) SLC__PS)
/* Port Configuration */
#define SLC_PC                     (* (reg32 *) SLC__PC)
/* Data Register */
#define SLC_DR                     (* (reg32 *) SLC__DR)
/* Input Buffer Disable Override */
#define SLC_INP_DIS                (* (reg32 *) SLC__PC2)


#if defined(SLC__INTSTAT)  /* Interrupt Registers */

    #define SLC_INTSTAT                (* (reg32 *) SLC__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins SLC_H */


/* [] END OF FILE */
