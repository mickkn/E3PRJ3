/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include "movement.h"



int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    CyGlobalIntEnable; /* Her bliver global interrupts aktiveret. */
    
    isr_pir_StartEx(P_PIR); /*Her bliver pir interruptet startet*/
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
