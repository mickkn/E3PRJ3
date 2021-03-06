/*
* File: loadData.h
* Description: Header for controller class loadData
* Project: PRJ3
* 
* Author: Bjørn Sørensen
*/

#ifndef LOADDATA_H
#define LOADDATA_H

#include "buffer.h"
#include "parameters.h"
#include "sensorPackage.h"
#define LOGDATATIMEOUT 8   // in sec
#define WATERTIMEOUT 10     // in sec
    
// Private methods

// Public methods
extern void loadData_init(parameters *, buffer *);
extern int loadData_getBuffer( char **, unsigned int * len);
extern int loadData_movementDetect();
extern int loadData_logDataTimeout();
extern int loadData_waterTimeout();

#endif // ifndef LOADDATA_H