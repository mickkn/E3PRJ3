/*
* File: parameters.h
* Description: Header for EasyWater8000 class parameters
* Project: PRJ3
* 
* Author: Jesper Christensen
*/


#ifndef PARAMETERS_H
#define PARAMETERS_H


typedef struct parameters_type
{
	float temperature_;
	float humidity_;
	unsigned char active_;
} parameters;

extern void parameters_init( parameters * const this );
extern void parameters_exit( parameters * const this );
extern int parameters_setTemp( parameters * const this, const float );
extern int parameters_getTemp( parameters * const this, float * temp);
extern int parameters_setHumi( parameters * const this, const float humi);
extern int parameters_getHumi( parameters * const this, float * humia); 
extern int parameters_setActive( parameters * const this, const unsigned char);
extern int parameters_getActive( parameters * const this, unsigned char *); 

#endif  // ifndef PARAMETERS_H