#pragma once

#include "parameters.h"



int main()
{
	parameters myStruct;
	parameters * Ptr_ = &myStruct;

	parameters_init(Ptr_);

	printf("active: %u \nhumidity: %f \nTemperature: %f \n", Ptr_->active_, Ptr_->humidity_, Ptr_->temperature_);

	parameters_setActive(Ptr_, 1);
	parameters_setHumi(Ptr_, 80);
	parameters_setTemp(Ptr_, -10);

	printf("active: %u \nhumidity: %f \nTemperature: %f \n", Ptr_->active_, Ptr_->humidity_, Ptr_->temperature_);


	while (1);
}