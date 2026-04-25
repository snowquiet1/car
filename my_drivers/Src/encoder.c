#include"encoder.h"

#define QEI_Initcount 5000



void Encoder_Init(void)
{
    DL_Timer_startCounter(QEI_left_INST);
    DL_Timer_startCounter(QEI_right_INST);
    DL_Timer_setTimerCount(QEI_left_INST,QEI_Initcount);
    DL_Timer_setTimerCount(QEI_right_INST,QEI_Initcount);

}

void Encoder_getspeed(void)
{
    speedlr[0] = DL_Timer_getTimerCount(QEI_left_INST);
    speedlr[1] = DL_Timer_getTimerCount(QEI_right_INST);
}


