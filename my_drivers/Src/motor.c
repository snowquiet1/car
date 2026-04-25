#include "motor.h"

#define Timer_ARR 1000-1

void Motor_Init(void)
{
    DL_Timer_startCounter(PWM_Motor_INST);
}
void Motor_setLeftSpeed(int32_t LeftSpeed)
{
    if(LeftSpeed > Timer_ARR)
    {
       LeftSpeed = Timer_ARR; 
    }
    if(LeftSpeed < -Timer_ARR)
    {
        LeftSpeed = -Timer_ARR;
    }

    if(LeftSpeed > 0)
    {
        DL_Timer_setCaptureCompareValue(PWM_Motor_INST, LeftSpeed, DL_TIMER_CC_0_INDEX);
        DL_Timer_setCaptureCompareValue(PWM_Motor_INST, 0, DL_TIMER_CC_1_INDEX);
    }
    else 
    {
        DL_Timer_setCaptureCompareValue(PWM_Motor_INST, -LeftSpeed, DL_TIMER_CC_1_INDEX);
        DL_Timer_setCaptureCompareValue(PWM_Motor_INST, 0, DL_TIMER_CC_0_INDEX);  
    }   
}

void Motor_setRightSpeed(int32_t RightSpeed)
{
    if(RightSpeed > Timer_ARR)
    {
       RightSpeed = Timer_ARR; 
    }
    if(RightSpeed < -Timer_ARR)
    {
        RightSpeed = -Timer_ARR;
    }    
    if(RightSpeed > 0)
    {
        DL_Timer_setCaptureCompareValue(PWM_Motor_INST, RightSpeed, DL_TIMER_CC_2_INDEX);
        DL_Timer_setCaptureCompareValue(PWM_Motor_INST, 0, DL_TIMER_CC_3_INDEX);
    }
    else 
    {
        DL_Timer_setCaptureCompareValue(PWM_Motor_INST, -RightSpeed, DL_TIMER_CC_3_INDEX);
        DL_Timer_setCaptureCompareValue(PWM_Motor_INST, 0, DL_TIMER_CC_2_INDEX);  
    }   
}

void Motor_setSpeed(int32_t LeftSpeed,int32_t RightSpeed)
{
    Motor_setLeftSpeed(LeftSpeed);
    Motor_setRightSpeed(RightSpeed);
}