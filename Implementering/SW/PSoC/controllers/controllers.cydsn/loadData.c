/*
* File: loadData.c 
* Description: Implementation of controller class loadData
* Project: PRJ3
* 
* Author: Bjørn Sørensen
*/

#include "loadData.h"

// Private data
/*static parameters * parametersPtr_;
static sensorPackage * sensorPackagePtr_;*/
static buffer * bufferPtr_;
static unsigned char movement_;

// Public methods
extern void loadData_init(buffer *buf)  //  parameters *par, sensorPackage *pack, 
{
    // Set pointers accordingly
    /*parametersPtr_ = par;
    sensorPackagePtr_ = pack;*/
    bufferPtr_ = buf;
    
    // Start logData timer
    
    
}

int loadData_getBuffer( char ** buf, unsigned int * len)
{
    buffer_getData(bufferPtr_, buf, len);
    return 0;
}

int loadData_movementDetect()
{
    // Clear active flag in parameters
    // Start 30 minute timer
    // Set movement flag
    return 0;
}

int loadData_logDataTimeout()
{
    // Collect data from sensorpackage
    // Save data as string i buffer, with movement set accordingly
    // Clear movement flag
    return 0;
}
int  loadData_waterTimeout()
{
    // Set active_ flag in parameters
    return 0;
}