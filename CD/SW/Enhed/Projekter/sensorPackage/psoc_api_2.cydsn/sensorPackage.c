//sensorPackage.c
//
//Author: Jakob Schmidt
//Version: 1.2
//Date: 17-14-11

#include "sensorPackage.h"

//Private attributes

//Private operations

//Implementations
void sensorPackage_init()
{
    //Start components
    ADC_SAR_Seq_0_Start();
    
    //initialize "objects"
    sprinkler_init();
    tempSensor_init();
    humiSensor_init();
    
}

void sensorPackage_exit()
{
    //Stop components
    ADC_SAR_Seq_0_Stop();
}

//Public methods implementations
int sensorPackage_getData(float *temp_, float *humi_)
{
    tempSensor_getValue(temp_);
    humiSensor_getValue(humi_);
    
    return 0; 
}

int sensorPackage_water(unsigned char water)
{
    if(water != 1 || water != 0)
        return -15;
    
    //Set pin to water (1/0);
    water_pin_Write(water);
    
    return 0;
}