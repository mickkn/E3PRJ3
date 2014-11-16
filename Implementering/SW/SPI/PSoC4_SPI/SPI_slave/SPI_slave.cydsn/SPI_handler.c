#include "SPI_handler.h"

char spiBuffer[64];
char spiTxBuffer[64];
char testCharArray[] = "DerTestesLog";
char unitNo[] = "1";
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
    int arrayLen = sizeof(testCharArray);
    
	//TP_1_Write(1); // Til måling af ISR gennemløbstid
 
	cmd = SPIS_1_SpiUartReadRxData(); 
    
    spiBuffer[spiCounter] = cmd;
    spiCounter++;
    
    /*
	 * Her switches på cmd iht. dataprotokollen
     *
     *  ’A’   0x41     Aktiver Enhed
     *  ’D’   0x44     Deaktiver Enhed
     *  ’P’   0x50     Parametre sendes til Enhed
     *  ’V’   0x56     Verificer Enhed i systemet
     *  ’L’   0x4c     Forespørg logdata fra Enhed
     *
     *  'C'   0x43     Clear/write function char
     *  'R'   0x52     Read function char
	 */
    
    if (cmd == 'C' || cmd == 'R'){
    	switch (spiBuffer[0]) {
            case 'A':
                    RED_LED_Write(1);
                    GREEN_LED_Write(0);
                    BLUE_LED_Write(1);
                    
                    /* Clear Buffer and Counter */
                    SPIS_1_SpiUartClearTxBuffer();
                    spiCounter = 0;
                    
                break;
            case 'D':
                    GREEN_LED_Write(1);
                    RED_LED_Write(0);
                    BLUE_LED_Write(1);
                    
                    /* Clear Buffer and Counter */
                    SPIS_1_SpiUartClearTxBuffer();
                    spiCounter = 0;
                    
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
                    
                    /* Clear Buffer and Counter */
                    SPIS_1_SpiUartClearTxBuffer();
                    spiCounter = 0;
                    
                    /* Re-enable interrupt */
                    CyGlobalIntEnable;
                break;
    		case 'V':
                    GREEN_LED_Write(1);
                    RED_LED_Write(1);
                    BLUE_LED_Write(0);
    				SPIS_1_SpiUartClearTxBuffer();
    				SPIS_1_SpiUartWriteTxData('V');

                    spiTxBuffer[0] = unitNo[0];

                    SPIS_1_SpiUartClearTxBuffer();
                    spiCounter = 0;
                    SPIS_1_SpiUartWriteTxData(spiTxBuffer[spiCounter]);
                  
    			break;
            case 'L':
                    /* Disable interrupt */
                    CyGlobalIntDisable;
                    
                    for(i = 0 ; i < arrayLen ; i++){
                        spiTxBuffer[i] = testCharArray[i];
                    }
                    
                    SPIS_1_SpiUartClearTxBuffer();
                    spiCounter = 0;
                    SPIS_1_SpiUartWriteTxData(spiTxBuffer[spiCounter]);
                    
                    /* Re-enable interrupt */
                    CyGlobalIntEnable;
                break;
            case 'R':
                    SPIS_1_SpiUartClearTxBuffer();
                    SPIS_1_SpiUartWriteTxData(spiTxBuffer[spiCounter]);
                    spiCounter++;
                break;
    		default:
    			break;
    	}
    }
	
	SPIS_1_ClearRxInterruptSource(SPIS_1_GetRxInterruptSource());
	//TP_1_Write(0); // Til måling af ISR gennemløbstid
}