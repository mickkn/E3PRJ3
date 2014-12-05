/*
* File: loadData.c 
* Description: Implementation of controller class loadData
* Project: PRJ3
* 
* Author: Bjørn Sørensen
*/

#include "loadData.h"

// Private data
static parameters * parametersPtr_;
static buffer * bufferPtr_;
static unsigned char movement_;
static unsigned char dataIndex_;
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
    dataIndex_ = 0;
    
    // Start logData timer
    logDataTimeoutCounter_ = 0;
    logDataTimer_Start();
    logDataInterrupt_StartEx(logDataISR);
    
    // Initialize water timer
    waterTimeoutCounter_ = 0;
    waterInterrupt_StartEx(waterISR);
    
    // Set LED green
    RED_LED_Write(1);
    GREEN_LED_Write(0);
    BLUE_LED_Write(1);
    
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
    unsigned char val;
    parameters_getActive(parametersPtr_, &val);
    if(val == 1)
     {
        // Clear active flag in parameters
        parameters_setActive(parametersPtr_, 0);
        GREEN_LED_Write(1);
        RED_LED_Write(0);
        BLUE_LED_Write(1);
        
        
        // Start 30 minute timer
        waterTimer_Start();
        
        // Set movement flag
        movement_ = 1;
    }
    
    return 0;
}

int loadData_logDataTimeout()
{
    // Get LED color and change. Set back at the end.
    uint8 blue, red, green;
    blue = BLUE_LED_Read();
    red = RED_LED_Read();
    green = GREEN_LED_Read();
    RED_LED_Write(0);
    GREEN_LED_Write(1);
    BLUE_LED_Write(0);
    
    int ret;    // Error flag
    
    // Collect data limits from parameters
    unsigned char active;
    float tempLimit, humiLimit;
    parameters_getActive(parametersPtr_, &active);
    parameters_getTemp(parametersPtr_, &tempLimit);
    parameters_getHumi(parametersPtr_, &humiLimit);
    
    // Collect data from sensorpackage
    float temp, humi;
    sensorPackage_getData(&temp, &humi);
    
    // Create water flag and initialize
    unsigned char water;
    water = '0';
    
    // Save data as string i buffer, with movement set accordingly
    char data[11];
    data[0] = 'D';

    ret = snprintf(data + 1, 4, "%03i", (int)temp);   // Convert temp int to 3 character, 0 left-padded string
    if(ret != 3) // In case of failure, write error to buffer
    {
        buffer_saveData(bufferPtr_, "E022", 4);
        return -22;
    }
    // Add fake decimals
    data[4] = '.';
    data[5] = '0';
    
    ret = snprintf(data + 6, 4, "%03i", (int)humi);  // Convert humi int to 3 character, 0 left-padded string
    if(ret != 3) // In case of failure, write error to buffer
    {
        buffer_saveData(bufferPtr_, "E023", 4);
        return -23;
    }
    
    // If sensor values are out of parameter limits and system is active, activate water
    if(active == 1 && (temp > tempLimit || humi < humiLimit))
    {
        // Start water timer
        sensorPackage_water(1);
                
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

    RED_LED_Write(red);
    GREEN_LED_Write(green);
    BLUE_LED_Write(blue);
    
    return 0;
}
int  loadData_waterTimeout()
{
    // Set active_ flag in parameters
    parameters_setActive(parametersPtr_, 1);
    
    RED_LED_Write(1);
    GREEN_LED_Write(0);
    BLUE_LED_Write(1);
    
    waterTimer_Stop();
    
    return 0;
}
