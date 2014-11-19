#include "SPI_api.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int testData = 1;

	vector<string> test_data;

	float tempTest = 100.1;
	float humiTest = 48;

	SPI_api test;

	//test.activate(1);
	//test.deactivate(1);
	//test.config(1, tempTest, humiTest);
	//test.verify(1);
	test.getLog(test_data, &testData, 1);

	// TEST

	/*
	for(int i = 0 ; i < test_data.size() ; i++)
		std::cout << "test_data: " << test_data[i] << endl;
	*/

	return 0;
}
