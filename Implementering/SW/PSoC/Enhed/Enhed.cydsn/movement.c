
#include "movement.h"

extern void movement_init()
{
    isr_pir_StartEx(P_PIR);
}

CY_ISR(P_PIR)
{
   loadData_movementDetect(); 
}

