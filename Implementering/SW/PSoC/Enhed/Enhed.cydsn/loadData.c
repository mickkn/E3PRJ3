/*
* File: loadData.c 
* Description: Implementation of controller class loadData
* Project: PRJ3
* 
* Author: Bjørn Sørensen
*/

#include "loadData.h"
#include <stdio.h>

// Private data
static parameters * parametersPtr_;
static buffer * bufferPtr_;
static unsigned char movement_;
// sensorPackage is implicit known, as it contains only methods
static unsigned int logDataTimeoutCounter_;
static unsigned int waterTimeoutCounter_;


// Public methods
CY_ISR(logDataISR)
{
    if(logDataTimeoutCounter_ >= LOGDATATIMEOUT*1000/10.923)   // Timer max: 10.923 ms. 
    {
        loadData_logDataTimeout();
        logDataTimeoutCounter_ = 0;
    }
    else
        logDataTimeoutCounter_++;
}

CY_ISR(waterISR)
{
    if(waterTimeoutCounter_ >= WATERTIMEOUT*1000/10.923)   // Timer max: 10.923 ms. 
    {
        loadData_waterTimeout();
        waterTimeoutCounter_ = 0;
    }
    else
        waterTimeoutCounter_++;
}


extern void loadData_init(parameters *par, buffer *buf) 
{
    // Set pointers accordingly
    parametersPtr_ = par;
    bufferPtr_ = buf;
    // sensorPackage is implicit known, as it contains only methods
    
    
    // Start logData timer
    logDataTimeoutCounter_ = 0;
    logDataTimer_Start();
    logDataInterrupt_StartEx(logDataISR);
    
    // Initialize water timer
    waterTimeoutCounter_ = 0;
    waterInterrupt_StartEx(waterISR);
    // Get first sensor reading
    loadData_logDataTimeout();
    
    
}

int loadData_getBuffer( char ** buf, unsigned int * len)
{
    buffer_getData(bufferPtr_, buf, len);
    return 0;
}

int loadData_movementDetect()
{
    // Clear active flag in parameters
    parameters_setActive(parametersPtr_, 0);
    
    // Start 30 minute timer
    waterTimer_Start();
    
    // Set movement flag
    movement_ = 1;
    
    return 0;
}

int loadData_logDataTimeout()
{
    int ret;    // Error flag
    
    // Collect data limits from parameters
    unsigned char active;
    float tempLimit, humiLimit;
    parameters_getActive(parametersPtr_, &active);
    parameters_getTemp(parametersPtr_, &tempLimit);
    parameters_getHumi(parametersPtr_, &humiLimit);
    
    
    // Collect data from sensorpackage
    float temp, humi;
    //sensorPackage_getData(&temp, &humi);
    temp = logDataTimeoutCounter_%100;
    humi = 40;
    
    // Create water flag and initialize
    unsigned char water;
    water = '0';
    
    // Save data as string i buffer, with movement set accordingly
    
    char data[11];
    data[0] = 'D';

    ret = snprintf(data + 1, 6, "%05.1f", temp);   // Convert temp float to 4 character, 1 decimal point, 0 left-padded string
    if(ret != 5) // In case of failure, write error to buffer
    {
        buffer_saveData(bufferPtr_, "E022", 4);
        return -22;
    }
    
    ret = snprintf(data + 6, 4, "%03.0f", humi);  // Convert humi float to 3 character, 0 left-padded string
    if(ret != 3) // In case of failure, write error to buffer
    {
        buffer_saveData(bufferPtr_, "E023", 4);
        return -23;
    }
    
    // If sensor values are out of parameter limits and system is active, activate water
    if(active == 1 && (temp > tempLimit || humi < humiLimit))
    {
        sensorPackage_water(1);
        // Start water timer
        
        water = '1';
    }
    
    data[9] = water;
    if(movement_ == 0)
        data[10] = '0';
    else
        data[10] = '1';
     
    // Save data in buffer object for later use
    buffer_saveData(bufferPtr_, data, 11);
        
    // Clear movement flag
    movement_ = 0;
    
    return 0;
}
int  loadData_waterTimeout()
{
    // Set active_ flag in parameters
    parameters_setActive(parametersPtr_, 1);
    
    waterTimer_Stop();
    
    return 0;
}
