#include"Track.h"

#define Distance_need 20
#define Middle 4


float KP0 = 20,KI0 = 20,P0 = 0,I0 = 0 ,Speedbase = 0;
float distance_error = 0;

float KP1 = 20,KI1 = 20,P1  = 0,I1  = 0,Speedvary = 0;
float position = 0;

int count =  0;

void Track_Init(void)
{
    UStrasound_Init();
}

void Track_go(void)
{
    distance_error = distance - Distance_need;
    P0  = KP0 * distance_error;
    
    if (distance > Distance_need)
    {
        Speedbase = P0;
    }
    else
    {
        Speedbase = 0;
    }

    position = Graysensor_GetPosition();
    P1 = KP1 * (position - Middle);
    I1 = KI1 * (position - Middle) + I1;
    Speedvary = P1 + I1;

    Motor_setSpeed(Speedbase + Speedvary,Speedbase - Speedvary);
}




void Timer_Track_INST_IRQHandler(void)
{
    switch (DL_Timer_getPendingInterrupt(Timer_Track_INST))
    {
        case DL_TIMER_IIDX_LOAD:
            Track_go();
            count ++;
            if(count == 5)
            {
                Ustrasound_sendtrig();
                count  = 0;;
            }
            break;

        default:
            break;
    }
}
