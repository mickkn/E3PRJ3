
#pragma once

#include "parameters.h"

int setTemp(parameters * const this, const float temp)
{
	this->temperature_ = temp;

	return 0;
}

int getTemp(parameters * const this, float * temp) //const
{
	temp = &this->temperature_;

	return 0;
}

int setHumi(parameters * const this, const float humi)
{
	this->humidity_ = humi;

	return 0;
}

int getHumi(parameters * const this, float * humi)  //const
{
	 humi = &this->humidity_;

	return 0;

}

int setActive(parameters * const this, const unsigned char a)
{
	this->active_ = a;

	return 0;
}

int getActive(parameters * const this, unsigned char * a) //const
{
	a = &this->active_;

	return 0;
}