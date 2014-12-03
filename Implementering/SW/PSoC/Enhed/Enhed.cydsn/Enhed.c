/*
* File: Enhed.c
* Description: Samlet application for EasyWater8000 enhed
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
#include "movement.h"

int main()
{
    // Enable global interrupts (Used for SPI, PIR and timers)  
    CyGlobalIntEnable;
    
    // Create objects
    buffer bufferObj;
    buffer_init(&bufferObj);
    
    parameters paramObj;
    parameters_init(&paramObj);

    // Init boundary
    sensorPackage_init();
    movement_init();
    
    // Init controllers
    addRemove_init();
    config_init(&paramObj, &bufferObj);
    loadData_init(&paramObj, &bufferObj);
    onOff_init(&paramObj, &bufferObj);
    
    // Stay here and wait for timer og SPI interrupts
    while(1);
   
    // Exits (Never used)
    sensorPackage_exit();
    
    return 0;
}