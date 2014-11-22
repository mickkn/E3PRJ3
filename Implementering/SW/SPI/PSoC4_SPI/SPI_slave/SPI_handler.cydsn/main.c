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
#include "SPI_handler.h"

int main(void)
{
    /* Enable global interrupts */
    CyGlobalIntEnable;
    
    /* Init SPI Slave */
	SPIS_1_Start();
	SPIS_1_SetCustomInterruptHandler(isr_spi_rx);
	SPIS_1_SpiUartClearTxBuffer();
    
    /* Initialize LEDs */
    RED_LED_Write(1);
    GREEN_LED_Write(1);
    BLUE_LED_Write(1);
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
