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

int main()
{
    // Create objects
    buffer bufferObj;
    buffer_init(&bufferObj);
    
    
    // Init controller
    loadData_init(&bufferObj);
    
    // Start timer
    logDataTimer_Start();
    
    // Create some data in log
    buffer_saveData(&bufferObj, "E001", 4);
    
    
    char * read;
    unsigned int read_len;
    loadData_getBuffer(&read, &read_len);
    
    
    return 0;
}