//humiSensor.h
//
//Author: Jakob Schmidt
//Version: 1.2
//Date: 14-11-14

//#pragma once
#ifndef humiSensor
#define humiSensor
#include <project.h>


//Constructor
extern void humiSensor_init();

//Destructor
extern void humiSensor_exit();

//Public methods
extern int humiSensor_getValue(float *);

#endif
