//sensorPackage.h
//
//Author: Jakob Schmidt
//Version: 1.2
//Date: 17-11-14
#ifndef sensorPackage
#define sensorPackage
//#pragma once
#include "sprinkler.h"
#include "tempSensor.h"
#include "humiSensor.h"


//Constructor
extern void sensorPackage_init();

//Deconstructor
extern void sensorPackage_exit();

//Public methods
extern int sensorPackage_getData(float *, float *);
extern int sensorPackage_water(unsigned char);

#endif