#include "pid_speed.h"

// 定义左右电机的PID结构体实例
pid_t motor_l_pid;
pid_t motor_r_pid;

// 存储最终输出值
static float motor_l_out = 0;
static float motor_r_out = 0;

void Speed_Loop_Init(void)
{
    // 初始化左电机PID (位置式PID)
    // 参数含义：句柄, 模式, 最大PWM输出, 积分限幅, KP, KI, KD
    PID_struct_init(&motor_l_pid, POSITION_PID, 1000, 300, 15.0f, 0.5f, 0.1f);
    
    // 初始化右电机PID
    PID_struct_init(&motor_r_pid, POSITION_PID, 1000, 300, 15.0f, 0.5f, 0.1f);
}

void Speed_Loop_Calculate(float target_l, float target_r, int32_t actual_pulse_l, int32_t actual_pulse_r)
{
    // 1. 单位转换：将编码器脉冲转换为实际速度 (m/s)
    float speed_l_fdb = (float)actual_pulse_l * PULSE_TO_SPEED_RATIO;
    float speed_r_fdb = (float)actual_pulse_r * PULSE_TO_SPEED_RATIO;

    // 2. 调用你 pid.c 里的算法进行计算
    // 注意：pid_calc 会内部处理 error 更新和输出限幅
    motor_l_out = pid_calc(&motor_l_pid, speed_l_fdb, target_l);
    motor_r_out = pid_calc(&motor_r_pid, speed_r_fdb, target_r);
}

float Get_Motor_L_Output(void) { return motor_l_out; }
float Get_Motor_R_Output(void) { return motor_r_out; }