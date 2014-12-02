/*
* File: config.h
* Description: Header for EasyWater8000 controller class config
* Project: PRJ3
* 
* Author: Bjørn Sørensen
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "parameters.h"
#include "buffer.h"


extern void config_init(parameters *, buffer *);
extern int config_config( const float * temp, const float * humi );

#endif // ifndef CONFIG_H
