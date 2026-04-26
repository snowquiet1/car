#ifndef __PID_ANGLE_H__
#define __PID_ANGLE_H__

#include "pid.h"

// --- 外部句柄 ---
extern pid_t yaw_angle_pid; 

/**
 * @brief 初始化角度环
 */
void Angle_Loop_Init(void);

/**
 * @brief 角度环计算逻辑
 * @param target_yaw 目标角度 (单位: 度, 建议范围 -180 到 180)
 * @param actual_yaw 当前陀螺仪反馈角度
 * @return float 偏向速度输出 (用于叠加到左右轮速度上)
 */
float Angle_Loop_Calculate(float target_yaw, float actual_yaw);

#endif