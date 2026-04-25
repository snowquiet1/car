#include"ultrasound.h"

#define fre 1000000 //Hz
volatile uint32_t echo_rise_time = 0;
volatile uint32_t echo_fall_time = 0;
volatile uint8_t  echo_done = 0;
float distance = 0;

void UStrasound_Init(void)
{
    /* GPIO 组中断使能*/
    DL_GPIO_clearInterruptStatus(GPIO_Soundsensor_PORT, GPIO_Soundsensor_PIN_Echo_PIN);
    DL_GPIO_enableInterrupt(GPIO_Soundsensor_PORT, GPIO_Soundsensor_PIN_Echo_PIN);
    NVIC_EnableIRQ(GPIO_Soundsensor_INT_IRQN);
    
}

void Ustrasound_sendtrig(void)
{

    DL_GPIO_setPins(GPIO_Soundsensor_PORT, GPIO_Soundsensor_Pin_Trig_PIN);
    delay_cycles(1600);
    DL_GPIO_clearPins(GPIO_Soundsensor_PORT, GPIO_Soundsensor_Pin_Trig_PIN);
}

float Ustrasound_getdiatance(void)
{
    return distance;


}

void GROUP1_IRQHandler(void)
{
    uint32_t status;

    status = DL_GPIO_getEnabledInterruptStatus(GPIO_Soundsensor_PORT, GPIO_Soundsensor_PIN_Echo_PIN);

    if (status & GPIO_Soundsensor_PIN_Echo_PIN)
    {
        DL_GPIO_clearInterruptStatus(GPIO_Soundsensor_PORT, GPIO_Soundsensor_PIN_Echo_PIN);

        if (DL_GPIO_readPins(GPIO_Soundsensor_PORT, GPIO_Soundsensor_PIN_Echo_PIN))
        {
            DL_Timer_startCounter(Timer_Sound_INST);
            echo_rise_time = DL_Timer_getTimerCount(Timer_Sound_INST);
        }
        else
        {
            echo_fall_time =  DL_Timer_getTimerCount(Timer_Sound_INST);
            DL_Timer_stopCounter(Timer_Sound_INST);
            DL_Timer_setTimerCount(Timer_Sound_INST, 0);
            distance = 34000000.0 * (echo_fall_time - echo_rise_time) / 2 / fre;
        }
    }
}


