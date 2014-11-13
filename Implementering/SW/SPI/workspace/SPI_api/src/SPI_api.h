#include <vector>
#include <iostream>
#include <string>
using namespace std;

/* SPI_api ERRORS*/
#define OERR 10
#define WERR 11
#define RERR 12

class SPI_api{
public:
	int activate(int unit) const;
	int deactivate(int unit) const;
	int verify(int unit) const;
	int config(int unit, vector<string> data);
	int getLog(vector<string> &data, int* units, int size);
};
