/*
* File: config.c
* Description: Implementation for EasyWater8000 controller class config
* Project: PRJ3
* 
* Author: Bjørn Sørensen
*/

#include "config.h"

// Private data
static parameters * parametersPtr_;
static buffer * bufferPtr_;

// Public methods
void config_init(parameters * parPtr, buffer * bufPtr)
{
    parametersPtr_ = parPtr;
    bufferPtr_ = bufPtr;
}

int config_config(const float * temp, const float * humi)
{
    parameters_setTemp(parametersPtr_, *temp);
    parameters_setHumi(parametersPtr_, *humi);
    
    return 0;
}