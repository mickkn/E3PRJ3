/*
* File: test_controllers.c
* Description: Test program for controller classes
* Project: PRJ3
* 
* Author: Bjørn Sørensen
*/


#include <project.h>
// Controllers
#include "loadData.h"
#include "onOff.h"
#include "config.h"
#include "addRemove.h"

// Domain
#include "buffer.h"
#include "parameters.h"

int main()
{
    /* Test of class addRemove */
    {
//        int ret;
//        ret = -1;
//        addRemove_init();           // Init controller (nothing done)
//        ret = addRemove_verify();   // Verify, return 0
//        ret = 0;                    // Dummy
    }
    
    /* Test of class config */
    {
//        // Create objects
//        buffer bufferObj;
//        buffer_init(&bufferObj);
//        parameters paramObj;
//        parameters_init(&paramObj);
//        
//        // Create/init controller
//        config_init(&paramObj, &bufferObj);
//        
//        float readT, readH, t, h;
//        parameters_getTemp(&paramObj, &readT);      // Get temp
//        parameters_getHumi(&paramObj, &readH);      // Get humi
//        
//        t = 20.2;
//        h = 40.6;
//        config_config(&t, &h);                      // Set data
//        parameters_getTemp(&paramObj, &readT);      // Get temp
//        parameters_getHumi(&paramObj, &readH);      // Get humi
//        
//        t = 2.2;
//        h = 40;        
//        config_config(&t, &h);                      // Set data
//        parameters_getTemp(&paramObj, &readT);      // Get temp
//        parameters_getHumi(&paramObj, &readH);      // Get humi
//        
    }
    
    /* Test of class onOff */
    {
//        // Create objects
//        buffer bufferObj;
//        buffer_init(&bufferObj);
//        parameters paramObj;
//        parameters_init(&paramObj);
//        
//        // Create/init controller
//        onOff_init(&paramObj, &bufferObj);
//        
//        unsigned char read;
//        parameters_getActive(&paramObj, &read);     // Get active
//        
//        onOff_turnOnOff(1);                         // Turn ON
//        parameters_getActive(&paramObj, &read);     // Get active
//        
//        onOff_turnOnOff(0);                         // Turn OFF
//        parameters_getActive(&paramObj, &read);     // Get active
//        
//        onOff_turnOnOff(10);                        // Call with invalid argument
//        parameters_getActive(&paramObj, &read);     // Get active, no change should appear
//                                                    // Look up the buffer and verify error 23
    }
    
    /* Test of class loadData */
    {
//            
//        CyGlobalIntEnable;
//        // Create objects
//        buffer bufferObj;
//        buffer_init(&bufferObj);
//        parameters paramObj;
//        parameters_init(&paramObj);
//        sensorPackage_init();
//        parameters_setActive(&paramObj, 1);
//        
//        // Init controller
//        loadData_init(&paramObj, &bufferObj);
//        
//        // Read variables
//        char * read;
//        unsigned int read_len;
//        int ret;
//        while(1)
//        {
//            loadData_movementDetect();
//            CyDelay(20000);
//            ret = buffer_getData(&bufferObj, &read, &read_len);
//            
//        }
    }
    
    return 0;
}