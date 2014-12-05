/*
* File: spi_handler.h
* Description: Implementation for EasyWater8000 spi handler
* Project: PRJ3
* 
* Author: Mick Kirkegaard & Poul Overgaard
*/

#ifndef SPI_HANDLER_H
#define SPI_HANDLER_H
    
#include <project.h>
#include <stdio.h>
#include <stdlib.h>
#include "onOff.h"
#include "config.h"
#include "addRemove.h"
#include "loadData.h"

/* Function Prototypes */
extern void spi_init();

CY_ISR_PROTO(isr_spi_rx);

#endif // #ifndef SPI_HANDLER_H