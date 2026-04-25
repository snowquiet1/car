#ifndef __ULTRASOUND_H
#define __ULTRASOUND_H

#include "ti_msp_dl_config.h"
#include"stdint.h"

extern float distance;

void UStrasound_Init(void);
void Ustrasound_sendtrig(void);
float Ustrasound_getdiatance(void);
void GROUP1_IRQHandler(void);

#endif