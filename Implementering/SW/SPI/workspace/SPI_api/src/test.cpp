#include "SPI_api.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	vector<string> test_config;
	test_config.push_back("Fugt");
	test_config.push_back("Temp");

	vector<string> test_data;

	int testData = 1;

	SPI_api test;

	//test.activate(1);
	//test.deactivate(1);
	test.verify(1);
	//test.config(1, test_config);
	//test.getLog(test_data, &testData, 1);

	return 0;
}
