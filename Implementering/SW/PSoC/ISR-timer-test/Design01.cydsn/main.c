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

CY_ISR(TIMER_ISR)
{
    RED_LED_Write(!RED_LED_Read());
}
uint32 ms_count = 0;
CY_ISR(TIMER1_ISR)
{
    ms_count++;
    
    if(ms_count >= 10000)
    {
        BLUE_LED_Write(!BLUE_LED_Read());
        ms_count = 0;
    }
}

int main()
{
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    Timer_Start();
    Timer_1_Start();
    timer_int_StartEx(TIMER_ISR);
    timer1_int_StartEx(TIMER1_ISR);
    CyGlobalIntEnable; /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
