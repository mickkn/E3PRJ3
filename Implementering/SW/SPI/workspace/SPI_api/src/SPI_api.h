#include <vector>
#include <iostream>
#include <string>
using namespace std;

class SPI_api{
public:
	int activate(int unit) const;
	int deactivate(int unit) const;
	int verify(int unit) const;
	int config(int unit, vector<string>);
	int getLog(vector<string> &data, int* units, int size);
};
