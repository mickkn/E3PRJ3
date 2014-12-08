/*******************************************************************************
* File Name: testPin.h  
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

#if !defined(CY_PINS_testPin_H) /* Pins testPin_H */
#define CY_PINS_testPin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "testPin_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    testPin_Write(uint8 value) ;
void    testPin_SetDriveMode(uint8 mode) ;
uint8   testPin_ReadDataReg(void) ;
uint8   testPin_Read(void) ;
uint8   testPin_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define testPin_DRIVE_MODE_BITS        (3)
#define testPin_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - testPin_DRIVE_MODE_BITS))
#define testPin_DRIVE_MODE_SHIFT       (0x00u)
#define testPin_DRIVE_MODE_MASK        (0x07u << testPin_DRIVE_MODE_SHIFT)

#define testPin_DM_ALG_HIZ         (0x00u << testPin_DRIVE_MODE_SHIFT)
#define testPin_DM_DIG_HIZ         (0x01u << testPin_DRIVE_MODE_SHIFT)
#define testPin_DM_RES_UP          (0x02u << testPin_DRIVE_MODE_SHIFT)
#define testPin_DM_RES_DWN         (0x03u << testPin_DRIVE_MODE_SHIFT)
#define testPin_DM_OD_LO           (0x04u << testPin_DRIVE_MODE_SHIFT)
#define testPin_DM_OD_HI           (0x05u << testPin_DRIVE_MODE_SHIFT)
#define testPin_DM_STRONG          (0x06u << testPin_DRIVE_MODE_SHIFT)
#define testPin_DM_RES_UPDWN       (0x07u << testPin_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define testPin_MASK               testPin__MASK
#define testPin_SHIFT              testPin__SHIFT
#define testPin_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define testPin_PS                     (* (reg32 *) testPin__PS)
/* Port Configuration */
#define testPin_PC                     (* (reg32 *) testPin__PC)
/* Data Register */
#define testPin_DR                     (* (reg32 *) testPin__DR)
/* Input Buffer Disable Override */
#define testPin_INP_DIS                (* (reg32 *) testPin__PC2)


#if defined(testPin__INTSTAT)  /* Interrupt Registers */

    #define testPin_INTSTAT                (* (reg32 *) testPin__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins testPin_H */


/* [] END OF FILE */
