#pragma once

// 常数定义
#define EARTH_RAD 6371000.0 // 地球半径 (m)
#define DEN_ON    1.225     // 海平面空气密度 (kg/m^3)
#define TEM_ON    288.34    // 海平面温度 (K)
#define GRA_ON    9.806     // 重力加速度 (m/s^2)

#define PI             3.14159265359
#define DEG2RAD(angle) ((angle) * PI / 180.0)
#define RAD2DEG(angle) ((angle) * 180.0 / PI)

typedef struct {
    double temperature;
    double density;
    double sound_speed;
    double gravity;
} meteorological_condition_t;

void meteorological_params(meteorological_condition_t* meteorological_condition);

void kinetic_equations();

// double Ma[]         = {0.6, 0.8, 0.9, 1.0, 1.1};
// double Cx0[]        = {0.14942, 0.15754, 0.17140, 0.28832, 0.34312};
// double Cx_alpha2[]  = {0.00186, 0.00190, 0.00192, 0.00200, 0.00209};
// double Cy_alpha[]   = {0.06977, 0.06948, 0.06933, 0.07114, 0.07427};
// double Mz_delta_z[] = {-0.1323, -0.1323, -0.1322, -0.1531, -0.1525};
