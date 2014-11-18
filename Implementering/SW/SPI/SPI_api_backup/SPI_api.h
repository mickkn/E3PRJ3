#include <vector>
#include <iostream>
#include <string>
using namespace std;

/* SPI_api ERRORS*/
#define OERR 10
#define WERR 11
#define RERR 12
#define LOGERR 13
#define VERERR 14

class SPI_api{
public:
	int activate(int unit) const;
	int deactivate(int unit) const;
	int verify(int unit) const;
	int config(int unit, float temp, float humi);
	int getLog(vector<string> &data, int* units, int size);
};
