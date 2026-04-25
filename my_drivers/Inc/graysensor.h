#ifndef GRAYSENSOR_H
#define GRAYSENSOR_H

//本驱动库需要将gpioport命名为GPIO_GraySensor，七个pin命名为PIN_Leftx，x = 1，2，3，4，5，6，7
//实在不行自己宏定义一下


#include "ti_msp_dl_config.h"
#include"stdint.h"
extern int8_t Track_currentdata[7];
extern int8_t Track_lastdata[7];

void Graysensor_Init(void);
float Graysensor_GetPosition(void);

#endif