#include "SPI_handler.h"

char spiBuffer[64];
int spiCounter = 0;
char tempBuffer[6]; // T T T . T \0
char humiBuffer[4]; // F F F \0

/*
 * SPI RX ISR
 * Dekoder SPI RX data og udfører kommando iht.
 */
CY_ISR(isr_spi_rx) {

	char cmd;
    int i;

	//TP_1_Write(1); // Til måling af ISR gennemløbstid
 
	cmd = SPIS_1_SpiUartReadRxData(); 
    
    spiBuffer[spiCounter] = cmd;
    spiCounter++;
    
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
    
    if (cmd == 'C'){
    	switch (spiBuffer[0]) {
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
                    /* Disable interrupt */
                    CyGlobalIntDisable;
                    
                    /* Read temp */
                    for(i = 0 ; i < 5 ; i++){
                        tempBuffer[i] = spiBuffer[i+1];
                    }
                    for(i = 0 ; i < 3 ; i++){
                        humiBuffer[i] = spiBuffer[i+6];
                    }
                    
                    float tempValue = 0;
                    float humiValue = 0;
                    
                    /* Parse charArray's to float's */
                    tempValue = (float)atof(tempBuffer);
                    humiValue = (float)atof(humiBuffer);
                    
                    //config( humiValue , tempValue );
                    
                    /* Re-enable interrupt */
                    CyGlobalIntEnable;
                break;
    		case 'V':
                    GREEN_LED_Write(1);
                    RED_LED_Write(1);
                    BLUE_LED_Write(0);
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
                    spiCounter = 0;
    		default:
    			break;
    	}
    }
	
	SPIS_1_ClearRxInterruptSource(SPIS_1_GetRxInterruptSource());
	//TP_1_Write(0); // Til måling af ISR gennemløbstid
}