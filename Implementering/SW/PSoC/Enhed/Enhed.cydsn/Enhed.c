/*
* File: test_controllers.c
* Description: Test program for controller classes
* Project: PRJ3
* 
* Author: Bjørn Sørensen
*/


#include <project.h>
// Controllers
#include "loadData.h"
#include "onOff.h"
#include "config.h"
#include "addRemove.h"

// Domain
#include "buffer.h"
#include "parameters.h"

// Boundary
#include "sensorPackage.h"
#include "spi_handler.h"

int main()
{
    // Enable global interrupts (Used for SPI, PIR and timers)  
    CyGlobalIntEnable;
    
    // Create objects
    buffer bufferObj;
    buffer_init(&bufferObj);
    
    parameters paramObj;
    parameters_init(&paramObj);
    
    // Init controllers
    addRemove_init();
    config_init(&paramObj, &bufferObj);
    loadData_init(&paramObj, &bufferObj);
    onOff_init(&paramObj, &bufferObj);
    
    // Init boundary
    sensorPackage_init();
    
    // Stay here and wait for timer og SPI interrupts
    while(1);
    
    return 0;
}