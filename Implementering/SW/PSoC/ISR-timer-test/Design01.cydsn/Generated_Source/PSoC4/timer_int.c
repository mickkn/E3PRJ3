/*******************************************************************************
* File Name: timer_int.c  
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
#include <timer_int.h>

#if !defined(timer_int__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START timer_int_intc` */

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: timer_int_Start
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
void timer_int_Start(void)
{
    /* For all we know the interrupt is active. */
    timer_int_Disable();

    /* Set the ISR to point to the timer_int Interrupt. */
    timer_int_SetVector(&timer_int_Interrupt);

    /* Set the priority. */
    timer_int_SetPriority((uint8)timer_int_INTC_PRIOR_NUMBER);

    /* Enable it. */
    timer_int_Enable();
}


/*******************************************************************************
* Function Name: timer_int_StartEx
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
void timer_int_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    timer_int_Disable();

    /* Set the ISR to point to the timer_int Interrupt. */
    timer_int_SetVector(address);

    /* Set the priority. */
    timer_int_SetPriority((uint8)timer_int_INTC_PRIOR_NUMBER);

    /* Enable it. */
    timer_int_Enable();
}


/*******************************************************************************
* Function Name: timer_int_Stop
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
void timer_int_Stop(void)
{
    /* Disable this interrupt. */
    timer_int_Disable();

    /* Set the ISR to point to the passive one. */
    timer_int_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: timer_int_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for timer_int.
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
CY_ISR(timer_int_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START timer_int_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: timer_int_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling timer_int_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use timer_int_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void timer_int_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + timer_int__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: timer_int_GetVector
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
cyisraddress timer_int_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + timer_int__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: timer_int_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling timer_int_Start
*   or timer_int_StartEx will override any effect this method would 
*   have had. This method should only be called after timer_int_Start or 
*   timer_int_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void timer_int_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((timer_int__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *timer_int_INTC_PRIOR = (*timer_int_INTC_PRIOR & (uint32)(~timer_int__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: timer_int_GetPriority
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
uint8 timer_int_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((timer_int__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*timer_int_INTC_PRIOR & timer_int__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: timer_int_Enable
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
void timer_int_Enable(void)
{
    /* Enable the general interrupt. */
    *timer_int_INTC_SET_EN = timer_int__INTC_MASK;
}


/*******************************************************************************
* Function Name: timer_int_GetState
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
uint8 timer_int_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*timer_int_INTC_SET_EN & (uint32)timer_int__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: timer_int_Disable
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
void timer_int_Disable(void)
{
    /* Disable the general interrupt. */
    *timer_int_INTC_CLR_EN = timer_int__INTC_MASK;
}


/*******************************************************************************
* Function Name: timer_int_SetPending
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
void timer_int_SetPending(void)
{
    *timer_int_INTC_SET_PD = timer_int__INTC_MASK;
}


/*******************************************************************************
* Function Name: timer_int_ClearPending
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
void timer_int_ClearPending(void)
{
    *timer_int_INTC_CLR_PD = timer_int__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
