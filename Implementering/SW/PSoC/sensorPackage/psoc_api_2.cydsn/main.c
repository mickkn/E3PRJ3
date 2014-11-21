#include <project.h>
#include "sensorPackage.h"

int main()
{  
    for(;;)//Never ending story....
    {
    sensorPackage_init();
    
    //Varibles to hold sensor data
    float temp = 0;
    float humi = 0;
    
    sensorPackage_getData(&temp, &humi);  
    }
    return 0;
}

