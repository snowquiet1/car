#include "MahonyAHRS.h"
#include <math.h>

volatile float q0 = 1.0f, q1 = 0.0f, q2 = 0.0f, q3 = 0.0f;
volatile float integralFBx = 0.0f,  integralFBy = 0.0f, integralFBz = 0.0f;

// 快速计算平方根倒数
static float invSqrt(float x) {
    float halfx = 0.5f * x;
    float y = x;
    long i = *(long*)&y;
    i = 0x5f3759df - (i>>1);
    y = *(float*)&i;
    y = y * (1.5f - (halfx * y * y));
    return y;
}

void Mahony_Init(void) {
    q0 = 1.0f; q1 = 0.0f; q2 = 0.0f; q3 = 0.0f;
    integralFBx = 0.0f; integralFBy = 0.0f; integralFBz = 0.0f;
}

// 核心更新算法 (gx,gy,gz: 弧度/秒; a和m可以是原始ADC值，会自动归一化)
void Mahony_Update(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz) {
    float recipNorm;
    float q0q0, q0q1, q0q2, q0q3, q1q1, q1q2, q1q3, q2q2, q2q3, q3q3;  
    float hx, hy, bx, bz;
    float halfvx, halfvy, halfvz, halfwx, halfwy, halfwz;
    float halfex, halfey, halfez;
    float qa, qb, qc;

    // 只有在磁力计有效时才使用9轴，否则退化为6轴
    if((mx == 0.0f) && (my == 0.0f) && (mz == 0.0f)) {
        // 退化为6轴逻辑（省略，同上一版）
        return;
    }

    // 只在加速度有效时运算
    if(!((ax == 0.0f) && (ay == 0.0f) && (az == 0.0f))) {
        
        // 1. 归一化加速度计
        recipNorm = invSqrt(ax * ax + ay * ay + az * az);
        ax *= recipNorm; ay *= recipNorm; az *= recipNorm;

        // 2. 归一化磁力计
        recipNorm = invSqrt(mx * mx + my * my + mz * mz);
        mx *= recipNorm; my *= recipNorm; mz *= recipNorm;

        // 辅助变量预计算
        q0q0 = q0 * q0; q0q1 = q0 * q1; q0q2 = q0 * q2; q0q3 = q0 * q3;
        q1q1 = q1 * q1; q1q2 = q1 * q2; q1q3 = q1 * q3;
        q2q2 = q2 * q2; q2q3 = q2 * q3; q3q3 = q3 * q3;

        // 3. 计算参考磁场方向 (Reference direction of Earth's magnetic field)
        hx = 2.0f * (mx * (0.5f - q2q2 - q3q3) + my * (q1q2 - q0q3) + mz * (q1q3 + q0q2));
        hy = 2.0f * (mx * (q1q2 + q0q3) + my * (0.5f - q1q1 - q3q3) + mz * (q2q3 - q0q1));
        bx = sqrtf(hx * hx + hy * hy);
        bz = 2.0f * (mx * (q1q3 - q0q2) + my * (q2q3 + q0q1) + mz * (0.5f - q1q1 - q2q2));

        // 4. 提取重力和磁场的预估方向
        halfvx = q1q3 - q0q2;
        halfvy = q0q1 + q2q3;
        halfvz = q0q0 - 0.5f + q3q3;
        halfwx = bx * (0.5f - q2q2 - q3q3) + bz * (q1q3 - q0q2);
        halfwy = bx * (q1q2 - q0q3) + bz * (q0q1 + q2q3);
        halfwz = bx * (q0q2 + q1q3) + bz * (0.5f - q1q1 - q2q2);

        // 5. 误差计算 (叉乘求和：重力误差 + 磁场误差)
        halfex = (ay * halfvz - az * halfvy) + (my * halfwz - mz * halfwy);
        halfey = (az * halfvx - ax * halfvz) + (mz * halfwx - mx * halfwz);
        halfez = (ax * halfvy - ay * halfvx) + (mx * halfwy - my * halfwx);

        // 6. 应用 PI 补偿 (与6轴一致)
        if(twoKiDef > 0.0f) {
            integralFBx += twoKiDef * halfex * (1.0f / sampleFreq);
            integralFBy += twoKiDef * halfey * (1.0f / sampleFreq);
            integralFBz += twoKiDef * halfez * (1.0f / sampleFreq);
            gx += integralFBx; gy += integralFBy; gz += integralFBz;
        }
        gx += twoKpDef * halfex; gy += twoKpDef * halfey; gz += twoKpDef * halfez;
    }

    // 7. 四元数积分与归一化 (与6轴一致)
    gx *= (0.5f * (1.0f / sampleFreq));
    gy *= (0.5f * (1.0f / sampleFreq));
    gz *= (0.5f * (1.0f / sampleFreq));
    qa = q0; qb = q1; qc = q2;

    q0 += (-qb * gx - qc * gy - q3 * gz);
    q1 += (qa * gx + qc * gz - q3 * gy);
    q2 += (qa * gy - qb * gz + q3 * gx);
    q3 += (qa * gz + qb * gy - qc * gx);

    recipNorm = invSqrt(q0 * q0 + q1 * q1 + q2 * q2 + q3 * q3);
    q0 *= recipNorm; q1 *= recipNorm; q2 *= recipNorm; q3 *= recipNorm;
}

// 输出欧拉角
void Mahony_ComputeAngles(EulerAngle_t *angles) {
    angles->Roll  = atan2f(q0*q1 + q2*q3, 0.5f - q1*q1 - q2*q2) * 57.29578f;
    angles->Pitch = asinf(-2.0f * (q1*q3 - q0*q2)) * 57.29578f;
    // 此时的 Yaw 已经是绝对航向角了！
    angles->Yaw   = atan2f(q1*q2 + q0*q3, 0.5f - q2*q2 - q3*q3) * 57.29578f;
}