#ifndef __MOTOR_H
#define __MOTOR_H

//该库是rz7899驱动库，使用前需要将TIMer_PWM命名为PWM_Motor_INST

#include "ti_msp_dl_config.h"
#include"stdint.h"

void Motor_Init(void);
void Motor_setLeftSpeed(int32_t LeftSpeed);
void Motor_setRightSpeed(int32_t RightSpeed);
void Motor_setSpeed(int32_t LeftSpeed,int32_t RightSpeed);

#endif