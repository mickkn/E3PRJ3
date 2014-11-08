#include <vector>
#include <iostream>
using namespace std;

class SPI_api{
public:
	int activate(int unit) const;
	int deactivate(int unit) const;
	int verify(int unit) const;
	int config(int unit, vector<string>);
};
