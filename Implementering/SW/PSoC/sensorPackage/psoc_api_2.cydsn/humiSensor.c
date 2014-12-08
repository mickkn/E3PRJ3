//humiSensor.c
//
//Author: Jakob Schmidt
//Version: 1.2
//Date: 14-11-14

#include "humiSensor.h"
#include "sensorPackage.h"


//Constructor implementation
void humiSensor_init()
{
    //Do nothing
}


//Destructor implementation
void humiSensor_exit()
{
    //Do nothing
}


//Public methods implementation
int humiSensor_getValue(float *val)
{   
    //Varibles 
    int16 ADCresult;
    uint8 ADC_Channel = 0;
    uint8 select = 1;
    float vin_result;
    float pwm_result;
   
    //Set SCL high for humi data out
    P_FT2_Write(select);
    
    //Wait 1000 ms
    CyDelay(1000);
    
    //Start conversion
    ADC_SAR_Seq_0_StartConvert();
   
    //Wait until conversion is done
    ADC_SAR_Seq_0_IsEndConversion(ADC_SAR_Seq_0_WAIT_FOR_RESULT);
    
    //Read value from ADC register
    ADCresult = ADC_SAR_Seq_0_GetResult16(ADC_Channel);

    //Convert to voltage
    vin_result = ADC_SAR_Seq_0_CountsTo_Volts(ADC_Channel, ADCresult);

    //Conver from voltage to PWM
    pwm_result = (vin_result/vin_max);

    //Store trueData in val pointer
    *val = -6+125*(pwm_result);

    return 0;
}


