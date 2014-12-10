/*
* File: onOff.h
* Description: Header for EasyWater8000 controller class onOff
* Project: PRJ3
* 
* Author: Bjørn Sørensen
*/

#ifndef ONOFF_H
#define ONOFF_H

#include "parameters.h"
#include "buffer.h"
#include "sensorPackage.h"

extern void onOff_init(parameters *, buffer *);
extern int onOff_turnOnOff( const unsigned char state );

#endif // ifndef ONOFF_H
