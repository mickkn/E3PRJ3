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

/* Function Prototypes */
CY_ISR_PROTO(isr_spi_rx);

int main()
{
    /* Enable global interrupts */
    CyGlobalIntEnable;
    
    /* Init SPI Slave */
	SPIS_1_Start();
	SPIS_1_SetCustomInterruptHandler(isr_spi_rx);
	SPIS_1_SpiUartClearTxBuffer();
    
    /* Initialize LED */
    
    RED_LED_Write(1);
    GREEN_LED_Write(1);
    BLUE_LED_Write(1);
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/*
 * SPI RX ISR
 * Dekoder SPI RX data og udfører kommando iht.
 */
CY_ISR(isr_spi_rx) {

	char cmd;
    
	//TP_1_Write(1); // Til måling af ISR gennemløbstid
 
	cmd = SPIS_1_SpiUartReadRxData(); 
    
    /*
	 * Her switches på cmd iht. dataprotokollen
     *
     *  ’A’ / ’a’   0x41 / 0x61     Aktiver Enhed
     *  ’D’ / ’d’   0x44 / 0x64     Deaktiver Enhed
     *  ’P’ / ’p’   0x50 / 0x70     Parametre sendes til Enhed
     *  ’V’ / ’v’   0x56 / 0x76     Verificer Enhed i systemet
     *  ’L’ / ’l’   0x4c / 0x6c     Forespørg logdata fra Enhed
     *
     *  'C'         0x43 / 0x63     Clear SPI buffer    
	 */

	switch (cmd) {
        case 'A':
                RED_LED_Write(1);
                GREEN_LED_Write(0);
                BLUE_LED_Write(1);
            break;
        case 'D':
                GREEN_LED_Write(1);
                RED_LED_Write(0);
                BLUE_LED_Write(1);
            break;
        case 'P':
            break;
		case 'V':
				SPIS_1_SpiUartClearTxBuffer();
				SPIS_1_SpiUartWriteTxData('V');
			break;
        case 'L':
            break;
        case 'R':
                SPIS_1_SpiUartClearTxBuffer();
                SPIS_1_SpiUartWriteTxData('R');
                break;
        case 'C':
                SPIS_1_SpiUartClearTxBuffer();
		default:
			break;
	}
	
	SPIS_1_ClearRxInterruptSource(SPIS_1_GetRxInterruptSource());
	//TP_1_Write(0); // Til måling af ISR gennemløbstid
}


/* [] END OF FILE */
