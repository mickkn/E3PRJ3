/*******************************************************************************
* File Name: logDataInterrupt.c  
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
#include <logDataInterrupt.h>

#if !defined(logDataInterrupt__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START logDataInterrupt_intc` */

/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: logDataInterrupt_Start
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
void logDataInterrupt_Start(void)
{
    /* For all we know the interrupt is active. */
    logDataInterrupt_Disable();

    /* Set the ISR to point to the logDataInterrupt Interrupt. */
    logDataInterrupt_SetVector(&logDataInterrupt_Interrupt);

    /* Set the priority. */
    logDataInterrupt_SetPriority((uint8)logDataInterrupt_INTC_PRIOR_NUMBER);

    /* Enable it. */
    logDataInterrupt_Enable();
}


/*******************************************************************************
* Function Name: logDataInterrupt_StartEx
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
void logDataInterrupt_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    logDataInterrupt_Disable();

    /* Set the ISR to point to the logDataInterrupt Interrupt. */
    logDataInterrupt_SetVector(address);

    /* Set the priority. */
    logDataInterrupt_SetPriority((uint8)logDataInterrupt_INTC_PRIOR_NUMBER);

    /* Enable it. */
    logDataInterrupt_Enable();
}


/*******************************************************************************
* Function Name: logDataInterrupt_Stop
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
void logDataInterrupt_Stop(void)
{
    /* Disable this interrupt. */
    logDataInterrupt_Disable();

    /* Set the ISR to point to the passive one. */
    logDataInterrupt_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: logDataInterrupt_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for logDataInterrupt.
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
CY_ISR(logDataInterrupt_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START logDataInterrupt_Interrupt` */

    /* `#END` */
}


/*******************************************************************************
* Function Name: logDataInterrupt_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling logDataInterrupt_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use logDataInterrupt_StartEx instead.
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void logDataInterrupt_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + logDataInterrupt__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: logDataInterrupt_GetVector
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
cyisraddress logDataInterrupt_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + logDataInterrupt__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: logDataInterrupt_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. Note calling logDataInterrupt_Start
*   or logDataInterrupt_StartEx will override any effect this method would 
*   have had. This method should only be called after logDataInterrupt_Start or 
*   logDataInterrupt_StartEx has been called. To set the initial
*   priority for the component use the cydwr file in the tool.
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 3, 0 being the highest.
*
* Return:
*   None
*
*******************************************************************************/
void logDataInterrupt_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((logDataInterrupt__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *logDataInterrupt_INTC_PRIOR = (*logDataInterrupt_INTC_PRIOR & (uint32)(~logDataInterrupt__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: logDataInterrupt_GetPriority
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
uint8 logDataInterrupt_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((logDataInterrupt__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*logDataInterrupt_INTC_PRIOR & logDataInterrupt__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: logDataInterrupt_Enable
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
void logDataInterrupt_Enable(void)
{
    /* Enable the general interrupt. */
    *logDataInterrupt_INTC_SET_EN = logDataInterrupt__INTC_MASK;
}


/*******************************************************************************
* Function Name: logDataInterrupt_GetState
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
uint8 logDataInterrupt_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*logDataInterrupt_INTC_SET_EN & (uint32)logDataInterrupt__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: logDataInterrupt_Disable
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
void logDataInterrupt_Disable(void)
{
    /* Disable the general interrupt. */
    *logDataInterrupt_INTC_CLR_EN = logDataInterrupt__INTC_MASK;
}


/*******************************************************************************
* Function Name: logDataInterrupt_SetPending
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
void logDataInterrupt_SetPending(void)
{
    *logDataInterrupt_INTC_SET_PD = logDataInterrupt__INTC_MASK;
}


/*******************************************************************************
* Function Name: logDataInterrupt_ClearPending
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
void logDataInterrupt_ClearPending(void)
{
    *logDataInterrupt_INTC_CLR_PD = logDataInterrupt__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
