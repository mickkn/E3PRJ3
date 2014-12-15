/*
* File: onOff.c
* Description: Implementation for EasyWater8000 controller class onOff
* Project: PRJ3
* 
* Author: Bjørn Sørensen
*/

#include "onOff.h"
#include "loadData.h"

// Private data
static parameters * parametersPtr_;
static buffer * bufferPtr_;

// Public methods
void onOff_init(parameters * parPtr, buffer * bufPtr)
{
    parametersPtr_ = parPtr;
    bufferPtr_ = bufPtr;
}

int onOff_turnOnOff(const unsigned char state)
{
    if(state != 0 && state != 1)    // State out of range 0 | 1, record error
    {
        buffer_saveData(bufferPtr_, "E023", 4);
        return -23;
    }
    
    nextState = state;
    
    parameters_setActive(parametersPtr_, state);    // Save state to parameters
    
    if(state == 0)
        sensorPackage_water(state);
    
    return 0;
}