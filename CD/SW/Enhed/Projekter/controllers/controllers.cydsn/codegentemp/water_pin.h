/*******************************************************************************
* File Name: water_pin.h  
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

#if !defined(CY_PINS_water_pin_H) /* Pins water_pin_H */
#define CY_PINS_water_pin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "water_pin_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    water_pin_Write(uint8 value) ;
void    water_pin_SetDriveMode(uint8 mode) ;
uint8   water_pin_ReadDataReg(void) ;
uint8   water_pin_Read(void) ;
uint8   water_pin_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define water_pin_DRIVE_MODE_BITS        (3)
#define water_pin_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - water_pin_DRIVE_MODE_BITS))
#define water_pin_DRIVE_MODE_SHIFT       (0x00u)
#define water_pin_DRIVE_MODE_MASK        (0x07u << water_pin_DRIVE_MODE_SHIFT)

#define water_pin_DM_ALG_HIZ         (0x00u << water_pin_DRIVE_MODE_SHIFT)
#define water_pin_DM_DIG_HIZ         (0x01u << water_pin_DRIVE_MODE_SHIFT)
#define water_pin_DM_RES_UP          (0x02u << water_pin_DRIVE_MODE_SHIFT)
#define water_pin_DM_RES_DWN         (0x03u << water_pin_DRIVE_MODE_SHIFT)
#define water_pin_DM_OD_LO           (0x04u << water_pin_DRIVE_MODE_SHIFT)
#define water_pin_DM_OD_HI           (0x05u << water_pin_DRIVE_MODE_SHIFT)
#define water_pin_DM_STRONG          (0x06u << water_pin_DRIVE_MODE_SHIFT)
#define water_pin_DM_RES_UPDWN       (0x07u << water_pin_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define water_pin_MASK               water_pin__MASK
#define water_pin_SHIFT              water_pin__SHIFT
#define water_pin_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define water_pin_PS                     (* (reg32 *) water_pin__PS)
/* Port Configuration */
#define water_pin_PC                     (* (reg32 *) water_pin__PC)
/* Data Register */
#define water_pin_DR                     (* (reg32 *) water_pin__DR)
/* Input Buffer Disable Override */
#define water_pin_INP_DIS                (* (reg32 *) water_pin__PC2)


#if defined(water_pin__INTSTAT)  /* Interrupt Registers */

    #define water_pin_INTSTAT                (* (reg32 *) water_pin__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins water_pin_H */


/* [] END OF FILE */
