#ifndef MAHONYAHRS_H
#define MAHONYAHRS_H

// 算法核心参数 (根据你的控制周期修改 sampleFreq)
#define sampleFreq  100.0f  // 100Hz = 10ms 中断周期
#define twoKpDef    (2.0f * 0.5f) 
#define twoKiDef    (2.0f * 0.0f) 

typedef struct {
    float Roll;
    float Pitch;
    float Yaw;
} EulerAngle_t;

void Mahony_Init(void);
void Mahony_Update(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz);
void Mahony_ComputeAngles(EulerAngle_t *angles);

#endif