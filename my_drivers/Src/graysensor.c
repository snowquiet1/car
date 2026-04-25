#include"graysensor.h"
#include <string.h>

#define Black 1
#define White 0
#define Middle 4

int8_t Track_currentdata[7] = {0};
int8_t Track_lastdata[7] = {White,White,White,Black,White,White,White};//保证开始时是直行


//黑为1，白为0

void Graysensor_Init(void)
{
    //暂时无
}
float Graysensor_GetPosition(void)
{
    float sum = 0;
    float Black_num = 0;

    Track_currentdata[0] = (DL_GPIO_readPins(GPIO_GraySensor_PORT, GPIO_GraySensor_PIN_Left1_PIN) != 0);
    Track_currentdata[1] = (DL_GPIO_readPins(GPIO_GraySensor_PORT, GPIO_GraySensor_PIN_Left2_PIN) != 0);
    Track_currentdata[2] = (DL_GPIO_readPins(GPIO_GraySensor_PORT, GPIO_GraySensor_PIN_Left3_PIN) != 0);
    Track_currentdata[3] = (DL_GPIO_readPins(GPIO_GraySensor_PORT, GPIO_GraySensor_PIN_Left4_PIN) != 0);
    Track_currentdata[4] = (DL_GPIO_readPins(GPIO_GraySensor_PORT, GPIO_GraySensor_PIN_Left5_PIN) != 0);
    Track_currentdata[5] = (DL_GPIO_readPins(GPIO_GraySensor_PORT, GPIO_GraySensor_PIN_Left6_PIN) != 0);
    Track_currentdata[6] = (DL_GPIO_readPins(GPIO_GraySensor_PORT, GPIO_GraySensor_PIN_Left7_PIN) != 0);

    if((Track_currentdata[0] == White) && (Track_currentdata[1] == White) && (Track_currentdata[2] == White) && (Track_currentdata[3] == White) && 
       (Track_currentdata[4] == White) && (Track_currentdata[5] == White) && (Track_currentdata[6] == White))
    {
        memcpy(Track_currentdata,Track_lastdata,sizeof(Track_lastdata));
    }
    else
    {
        memcpy(Track_lastdata,Track_currentdata,sizeof(Track_lastdata));
    }
    for(int i = 0;i < 7;i ++)
    {
        if(Track_currentdata[i] == Black)
        {
            Black_num ++;
        }
        sum += Track_currentdata[i] * (i + 1);
    }
    if (Black_num == 0)
    {
        return Middle;
    }

    return sum / Black_num;
}









