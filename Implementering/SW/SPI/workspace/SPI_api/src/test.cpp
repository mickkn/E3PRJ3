#include "SPI_api.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	SPI_api test;

	//test.activate(1);
	//test.deactivate(1);
	test.verify(1);

	return 0;
}
