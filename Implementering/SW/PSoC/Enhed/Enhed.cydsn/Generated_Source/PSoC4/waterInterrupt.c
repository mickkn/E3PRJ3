/*******************************************************************************
* File Name: waterInterrupt.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <waterInterrupt.h>

#if !defined(waterInterrupt__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START waterInterrupt_intc` */

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: waterInterrupt_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void waterInterrupt_Start(void)
{
    /* For all we know the interrupt is active. */
    waterInterrupt_Disable();

    /* Set the ISR to point to the waterInterrupt Interrupt. */
    waterInterrupt_SetVector(&waterInterrupt_Interrupt);

    /* Set the priority. */
    waterInterrupt_SetPriority((uint8)waterInterrupt_INTC_PRIOR_NUMBER);

    /* Enable it. */
    waterInterrupt_Enable();
}


/*******************************************************************************
* Function Name: waterInterrupt_StartEx
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void waterInterrupt_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    waterInterrupt_Disable();

    /* Set the ISR to point to the waterInterrupt Interrupt. */
    waterInterrupt_SetVector(address);

    /* Set the priority. */
    waterInterrupt_SetPriority((uint8)waterInterrupt_INTC_PRIOR_NUMBER);

    /* Enable it. */
    waterInterrupt_Enable();
}


/*******************************************************************************
* Function Name: waterInterrupt_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
* Return:
*   None
*
*******************************************************************************/
void waterInterrupt_Stop(void)
{
    /* Disable this interrupt. */
    waterInterrupt_Disable();

    /* Set the ISR to point to the passive one. */
    waterInterrupt_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: waterInterrupt_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for waterInterrupt.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(waterInterrupt_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START waterInterrupt_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: waterInterrupt_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling waterInterrupt_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use waterInterrupt_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void waterInterrupt_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + waterInterrupt__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: waterInterrupt_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress waterInterrupt_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + waterInterrupt__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: waterInterrupt_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling waterInterrupt_Start
*   or waterInterrupt_StartEx will override any effect this method would 
*   have had. This method should only be called after waterInterrupt_Start or 
*   waterInterrupt_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void waterInterrupt_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((waterInterrupt__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *waterInterrupt_INTC_PRIOR = (*waterInterrupt_INTC_PRIOR & (uint32)(~waterInterrupt__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: waterInterrupt_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt. 0 - 3, 0 being the highest.
*
*******************************************************************************/
uint8 waterInterrupt_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((waterInterrupt__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*waterInterrupt_INTC_PRIOR & waterInterrupt__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: waterInterrupt_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void waterInterrupt_Enable(void)
{
    /* Enable the general interrupt. */
    *waterInterrupt_INTC_SET_EN = waterInterrupt__INTC_MASK;
}


/*******************************************************************************
* Function Name: waterInterrupt_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 waterInterrupt_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*waterInterrupt_INTC_SET_EN & (uint32)waterInterrupt__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: waterInterrupt_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void waterInterrupt_Disable(void)
{
    /* Disable the general interrupt. */
    *waterInterrupt_INTC_CLR_EN = waterInterrupt__INTC_MASK;
}


/*******************************************************************************
* Function Name: waterInterrupt_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void waterInterrupt_SetPending(void)
{
    *waterInterrupt_INTC_SET_PD = waterInterrupt__INTC_MASK;
}


/*******************************************************************************
* Function Name: waterInterrupt_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void waterInterrupt_ClearPending(void)
{
    *waterInterrupt_INTC_CLR_PD = waterInterrupt__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
