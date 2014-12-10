#include "SPI_api.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

using namespace std;

int main(void)
{
  SPI_api test;

  cout << "Test of SPI_api" << endl << endl
	<< "Input command: " << endl
	<< " - A(ctivate)" << endl
	<< " - D(eactivate)" << endl
	<< " - V(erify)" << endl
	<< " - C(onfig)" << endl
	<< " - L(og)" << endl
	<< " - Q(uit)" << endl;
  
  char input;
  do
  {

    cin >> input;
    
    switch(input)
    {
      case 'A':
	cout << "Activate (Green)" << endl;
	test.activate(1);
	break;
      case 'D':
	cout << "Deactivate (Red)" << endl;
	test.deactivate(1);
	break;
      case 'V':
	cout << "Verify (Blue)" << endl;
	test.verify(1);
	break;
      case 'C':
	float tempTest;
	float humiTest;
	cout << "Config (White)" << endl
	    << "Input temp and humi: ";
	cin >> tempTest >> humiTest;
	test.config(1, tempTest, humiTest);
	break;
      case 'L':
	cout << "Log (Purble)" << endl;
	vector<string> test_data;
	test.getLog(test_data, NULL, 0);
	if(test_data.size() != 0)
	  for(unsigned int i = 0 ; i < test_data.size() ; i++)
	    cout << "test_data[" << i << "]: " << test_data[i] << endl;
	else
	  cout << "No data" << endl;
	break;  
    }
  } while(input != 'Q');
  
  cout << "Shutting down app" << endl;
  return 0;
}
