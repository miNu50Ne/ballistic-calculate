#pragma once

// 定义常量
#define M      225.0   // 导弹质量 (kg)
#define D      0.299   // 导弹直径 (m)
#define L      2.14    // 导弹长度 (m)
#define JZ     60.85   // 俯仰力矩惯量
#define G      9.806   // 重力加速度 (m/s^2)
#define R      6371000 // 地球半径 (m)
#define PI     3.14159265358979323846
#define T_ON   288.34  // 标准温度 (K)
#define RHO_ON 1.225   // 标准气密度 (kg/m^3)

typedef struct {
    double x;
    double y;
    double V;
    double theta;
    double alpha;
    double delta_z;
} missile_state_t;

void missile_trajectory_calc();