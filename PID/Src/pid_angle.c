#include "pid_angle.h"
#include "math.h"

// 实例化角度PID结构体
pid_t yaw_angle_pid;

/**
 * @brief 初始化角度PID参数
 */
void Angle_Loop_Init(void)
{
    // 使用位置式PID
    // 参数：句柄, 模式, 最大输出(速度偏移量), 积分限幅, KP, KI, KD
    // 假设最大偏向速度限制在 0.8m/s，防止转弯太猛导致甩尾
    PID_struct_init(&yaw_angle_pid, POSITION_PID, 0.8f, 0.1f, 0.02f, 0.0f, 0.001f);
}

/**
 * @brief 角度环计算逻辑
 */
float Angle_Loop_Calculate(float target_yaw, float actual_yaw)
{
    float error;

    // 1. 计算原始误差
    error = target_yaw - actual_yaw;

    // 2. 核心：处理角度过零点 (最短路径逻辑)
    // 如果误差大于180度，说明反向转弯更近
    if (error > 180.0f) 
    {
        error -= 360.0f;
    }
    else if (error < -180.0f) 
    {
        error += 360.0f;
    }

    // 3. 将处理后的误差送入 PID 计算
    // 注意：这里的 pid_calc 会根据你 pid.c 里的逻辑自动处理 P/I/D 和限幅
    // 由于 pid_calc 内部是 error = set - get，我们直接把误差传进去，set传error，get传0
    return pid_calc(&yaw_angle_pid, 0, error);
}