//tempSensor.h
//
//Author: Jakob Schmidt
//Version: 1.2
//Date: 14-11-14

//#pragma once
#ifndef tempSensor
#define tempSensor
#include <project.h>

//Constructor 
extern void tempSensor_init(); 

//Destructor
extern void tempSensor_exit();

//Public methods
extern int tempSensor_getValue(float *);

#endif
