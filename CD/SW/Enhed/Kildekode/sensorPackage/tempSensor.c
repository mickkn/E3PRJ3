//tempSensor.c
//
//Author: Jakob Schmidt
//Version: 1.1
//Date: 14-11-14

#include "tempSensor.h"

#define vin_max 3.3
#define CHANNEL_1 0

void tempSensor_init()
{
   //Do nothing
}


void tempSensor_exit()
{
    //Do nothing
}


//Public methods implementation
int tempSensor_getValue(float *val)
{
    //Varibles
    int16 ADCresult;
    //uint8 ADC_Channel = 0;
    uint8 select = 0;
    float vin_result;
    float pwm_result;
    
    //Set SCL low for temp data out
    SLC_Write(select);
    
    //Start conversion
    ADC_SAR_Seq_0_StartConvert();
    
    //Wait until conversion is done
    ADC_SAR_Seq_0_IsEndConversion(ADC_SAR_Seq_0_WAIT_FOR_RESULT);
    
    //Read value from ADC register
    ADCresult = ADC_SAR_Seq_0_GetResult16(CHANNEL_1);

    //Convert to voltage
    vin_result = ADC_SAR_Seq_0_CountsTo_Volts(CHANNEL_1, ADCresult);

    //Conver from voltage to PWM
    pwm_result = (vin_result/vin_max);
    
    //Store trueData in val pointer
    *val = -46.85+175.72*(pwm_result);
    
    return 0;
}