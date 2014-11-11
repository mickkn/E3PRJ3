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

	char rxvalue;
	char cmd;
	//uint8 addr;
	//uint8 rddata;
	//TP_1_Write(1); // Til måling af ISR gennemløbstid
 
	rxvalue = SPIS_1_SpiUartReadRxData(); 
	
	/* Protocol - Write 8-bit: 
	 * |CMD|  ADDR  |    DATA    |
	 *  1 1 1      8 7          0
	 *	5 4 3
	 */

	/* Protocol - Read 16-bit: 
	 * |CMD|  ADDR  |  Not Used  |       |           DATA          |
	 *  1 1 1      8 7          0         1                       0
	 *	5 4 3                             5
	 */

    /*
	cmd = (rxvalue >> 14) & 0x3;  // cmd = rdvalue[15:14]
	addr = (rxvalue >> 8) & 0x3f; // addr = rdvalue[13:8]
	rddata = rxvalue & 0xff;      // data = rdvalue[7:0]
    */
    
    cmd = rxvalue;
    
	/*
	 * Her switches på adressen. Kan der læses og skrives fra det pågældende
	 * register, implementeres dette under den pågældende adresse.
	 * I tilfælde af en read skal vi levere data tilbage. Dette skal gøres så hurtigt
	 * som muligt, da SPI masteren venter på data. Data antages at ligge klar til læsning. 
	 * Det eneste vi dermed skal gøre, er at kopiere variablen til SPI tx bufferen. 
	 * For at holde styr på hvad som udlæses, skal TX bufferen først cleares. 
	 * Devkit 8000 driveren forventer at kunne udlæse data efter 120 us (eller hvad som
	 * er specificeret i driveren).
	 */

	switch (cmd) {
		case 'V':
				SPIS_1_SpiUartClearTxBuffer();
				SPIS_1_SpiUartWriteTxData('G');
			break;
		default:
			break;
	}
	
	SPIS_1_ClearRxInterruptSource(SPIS_1_GetRxInterruptSource());
	//TP_1_Write(0); // Til måling af ISR gennemløbstid
}


/* [] END OF FILE */
