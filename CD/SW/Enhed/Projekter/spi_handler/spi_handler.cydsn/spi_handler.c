/*
* File: spi_handler.c
* Description: Implementation for EasyWater8000 class buffer
* Project: PRJ3
* 
* Author: Mick Kirkegaard & Poul Overgaard
*/

#include "SPI_handler.h"

char spiBuffer[64];
char spiTxBuffer[256]; 
char testGetLog[] = "DTTT.TFFFVBEXXX"; // (D)ata+(E)rror: TTT.TFFFVB+EXXX
char unitNo = '1';
int spiCounter = 0;
int spiReadCounter = 0;
unsigned int len = sizeof(testGetLog);
char tempBuffer[6]; // T T T . T \0
char humiBuffer[4]; // F F F \0

/*
 * SPI RX ISR
 * Dekoder SPI RX data og udfører kommando iht. protokol
 */
CY_ISR(isr_spi_rx) {

	char cmd = '0';
    int i;
    unsigned int c;
    
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
    
    if ((cmd == 'R') || (cmd == 'C') || (cmd == 'L') || (cmd == 'V')){
    	switch (spiBuffer[0]) {
            case 'A':
                    RED_LED_Write(1);
                    GREEN_LED_Write(0);
                    BLUE_LED_Write(1);
                    
                    /* Clear Buffer and Counter */
                    SPIS_1_SpiUartClearTxBuffer();
                    spiCounter = 0;
                    
                    /*Call method*/
                    //turnOnOff(true)
                    
                break;
            case 'D':
                    GREEN_LED_Write(1);
                    RED_LED_Write(0);
                    BLUE_LED_Write(1);
                    
                    /* Clear Buffer and Counter */
                    SPIS_1_SpiUartClearTxBuffer();
                    spiCounter = 0;
                    
                    /*Call method*/
                    //turnOnOff(false)
                    
                break;
            case 'P':
                    /* Disable interrupt */
                    CyGlobalIntDisable;
                 
                    GREEN_LED_Write(0);
                    RED_LED_Write(0);
                    BLUE_LED_Write(0);
                    
                    
                    
                    /* Read temp */
                    for(i = 0 ; i < 5 ; i++){
                        tempBuffer[i] = spiBuffer[i+1];
                        //
                    }
                    for(i = 0 ; i < 3 ; i++){
                        humiBuffer[i] = spiBuffer[i+6];
                    }
                    
                    float tempValue = 0;
                    float humiValue = 0;
                    
                    /* Parse charArray's to float's */
                    tempValue = (float)atof(tempBuffer);
                    humiValue = (float)atof(humiBuffer);
                    
                    /* Call method */
                    //config( &tempValue, &humiValue);
                    
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
                    SPIS_1_SpiUartWriteTxData(unitNo);
                    spiCounter = 0;
    			break;
            case 'L':
                    GREEN_LED_Write(1);
                    RED_LED_Write(0);
                    BLUE_LED_Write(0);
                    
                    /* Call method */
                    //getBuffer(*buf, len);
                    
                    //for(c = 0 ; c < len ; c++){
                    //spiTxBuffer[c] = buf[c];
                    //}
                    
                    // Test metode
                    for(c = 0 ; c < len ; c++){
                        spiTxBuffer[c] = testGetLog[c];
                    }
                    
                    SPIS_1_SpiUartClearTxBuffer();
                    SPIS_1_SpiUartWriteTxData((char)len);
                    spiCounter = 0;
                    spiReadCounter = 0;
                break;
            case 'R':
                    SPIS_1_SpiUartClearTxBuffer();
                    SPIS_1_SpiUartWriteTxData(spiTxBuffer[spiReadCounter]);
                    spiCounter = 0;
                    spiReadCounter++;
                break;
            case 'C':
                    SPIS_1_SpiUartClearRxBuffer();
                    spiCounter = 0;
    		default:
    			break;
    	}
    }
	
	SPIS_1_ClearRxInterruptSource(SPIS_1_GetRxInterruptSource());
	//TP_1_Write(0); // Til måling af ISR gennemløbstid
}