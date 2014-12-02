/*
* File: parameters.c
* Description: Implementation of EasyWater8000 class parameters
* Project: PRJ3
* 
* Author: Jesper Christensen
*/

#include "parameters.h"


extern void parameters_init(parameters * const this)
{
	this->active_ = 0;
	this->humidity_ = 10;
	this->temperature_ = 30;
}

extern void parameters_exit(parameters * const this)
{

}

int parameters_setTemp(parameters * const this, const float temp)
{
	this->temperature_ = temp;

	return 0;
}

int parameters_getTemp(parameters * const this, float * temp)
{
	*temp = this->temperature_;

	return 0;
}

int parameters_setHumi(parameters * const this, const float humi)
{
	this->humidity_ = humi;

	return 0;
}

int parameters_getHumi(parameters * const this, float * humi)
{
	 *humi = this->humidity_;

	return 0;

}

int parameters_setActive(parameters * const this, const unsigned char a)
{
	this->active_ = a;

	return 0;
}

int parameters_getActive(parameters * const this, unsigned char * a)
{
	*a = this->active_;

	return 0;
}