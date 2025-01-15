#pragma once

#define G   9.81 // 重力加速度
#define M   100  // 导弹质量
#define V_T 120  // 目标速度
#define R_0 200  // 初始相对距离
#define K   4    // 比例导引法导航比

void speed_tracking_calc();
void proportional_guidance();