#ifndef __PID_SPEED_H__
#define __PID_SPEED_H__

#include "pid.h"

// --- 硬件参数配置 (根据你的实际情况修改) ---
#define WHEEL_CIRCUMFERENCE    0.2041f  // 轮子周长 (米)，假设直径65mm: 0.065 * 3.1415
#define ENCODER_RESOLUTION     440.0f   // 编码器一圈的脉冲数 (线数 * 倍频 * 减速比)
#define CONTROL_PERIOD_S       0.010f   // PID执行周期 (10ms = 0.01s)

// 单位转换系数：(脉冲数 / 分辨率) * 周长 / 时间 = 速度(m/s)
#define PULSE_TO_SPEED_RATIO   (WHEEL_CIRCUMFERENCE / (ENCODER_RESOLUTION * CONTROL_PERIOD_S))

// --- 外部声明 ---
extern pid_t motor_l_pid; // 左电机PID句柄
extern pid_t motor_r_pid; // 右电机PID句柄

/**
 * @brief 初始化速度内环
 */
void Speed_Loop_Init(void);

/**
 * @brief 速度环计算逻辑 (应在10ms定时器中断中调用)
 * @param target_l 左轮目标速度 (m/s)
 * @param target_r 右轮目标速度 (m/s)
 * @param actual_pulse_l 编码器左轮读到的原始脉冲数
 * @param actual_pulse_r 编码器右轮读到的原始脉冲数
 */
void Speed_Loop_Calculate(float target_l, float target_r, int32_t actual_pulse_l, int32_t actual_pulse_r);

/**
 * @brief 获取PID计算后的PWM输出
 */
float Get_Motor_L_Output(void);
float Get_Motor_R_Output(void);

#endif