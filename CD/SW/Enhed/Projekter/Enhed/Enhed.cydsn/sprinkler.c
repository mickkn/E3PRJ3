//sprinkler.c
//
//Authour: Jakob Schmidt
//Version: 1.0
//Date: 14-11-14

#include "sprinkler.h"

//Constructor implementation
void sprinkler_init()
{
    //Do nothing
}

void sprinkler_exit()
{
    //Do nothing
}

int sprinkler_setValue(unsigned char active)
{   
    if(active != 1 && active != 0)
        return -16;
    
    //Set pin to water (1/0);
    P_VP_Write(active);
    
    return 0;
}