#include <project.h>
#include "sensorPackage.h"

int main()
{  
    //'Objects' initialize
    sensorPackage_init(); 
    
    //Set testPin to voltage
    testPin_Write(100);

    for(;;)//Never ending story....
    {
        //Varibles to hold sensor data
        float temp = 0;
        float humi = 0;
        
        sensorPackage_getData(&temp, &humi);  
    }
    return 0;
}
