/*
* File: test_controllers.c
* Description: Test program for controller classes
* Project: PRJ3
* 
* Author: Bjørn Sørensen
*/


#include <project.h>
#include "loadData.h"
#include "buffer.h"
#include "parameters.h"

int main()
{
    CyGlobalIntEnable;
    
    // Create objects
    buffer bufferObj;
    buffer_init(&bufferObj);
    parameters paramObj;
    parameters_init(&paramObj);
    sensorPackage_init();
    parameters_setActive(&paramObj, 1);
    
    // Init controller
    loadData_init(&paramObj, &bufferObj);
    
    // Read variables
    char * read;
    unsigned int read_len;
    int ret;
    while(1)
    {
        loadData_movementDetect();
        CyDelay(20000);
        ret = buffer_getData(&bufferObj, &read, &read_len);
        
    }
    
    return 0;
}