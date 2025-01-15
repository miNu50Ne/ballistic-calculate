/**
 * @file reality_trajectory.c
 * @author miNu50Ne (minu50ne@qq.com)
 * @brief
 * @version 0.1
 * @date 2025-01-15
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <math.h>
#include <stdio.h>

#include "components/log/log.h"
#include "missile_trajectory.h"

// 数据更新函数 (updata)
static void updata(double altitude, double* rho_n, double* g, double* Ma) {
    double T_n = T_ON - altitude * 5.86e-3;                    // 温度更新公式
    *rho_n     = RHO_ON * pow(1 - altitude * 2.0323e-5, 4.83); // 气密度更新公式
    *Ma        = sqrt(20.046 * T_n);                           // 马赫数计算公式
    *g         = G * (1 - 2 * altitude / R);                   // 重力加速度更新公式
}

// 插值函数 (inter)
static void inter(
    double x, double alph, double omegazyi, double deltaalph, double* Cx, double* Cy, double* mz) {
    double Ma[]       = {0.6, 0.8, 0.9, 1.0, 1.1};
    double Cx_0[]     = {0.14942, 0.15754, 0.17140, 0.28832, 0.34312};
    double Calpha_x[] = {0.00186, 0.00190, 0.00192, 0.00200, 0.00209};
    double Calpha_y[] = {0.06977, 0.06948, 0.06933, 0.07114, 0.07427};
    double B[]        = {-1.16, -1.17, -1.20, -1.25, -1.17};
    double Cdelta_y[] = {0.03311, 0.03244, 0.03177, 0.03669, 0.03711};
    double mdeltaz[]  = {-0.1323, -0.1323, -0.1322, -0.1531, -0.1525};
    double momegaz[]  = {-13.0898, -12.9252, -13.8327, -14.5677, -15.3393};

    // 插值计算
    double delta_zB = alph / B[(int)x]; // 对应的delta_zB
    if (alph == 0) {
        delta_zB = 0;
    }

    double delta_z = delta_zB + 0.8 * deltaalph;
    *Cx            = Cx_0[(int)x] + Calpha_x[(int)x] * alph * alph;
    *Cy            = Calpha_y[(int)x] * alph + Cdelta_y[(int)x] * delta_z;
    *mz            = -mdeltaz[(int)x] * alph / B[(int)x] + mdeltaz[(int)x] * delta_z
        + momegaz[(int)x] * omegazyi;
}

// 微分方程的右端函数 (odefun)
static void odefun(double t, double y[], double dydt[]) {
    double alphxin   = (t < 3) ? 0 : 5.0 / 57.3;             // 攻角
    double alph      = y[5] - y[1];                          // 实际攻角
    double deltaalph = alph - alphxin;

    double rho_n, g, Ma;
    updata(y[3], &rho_n, &g, &Ma);                           // 更新气密度、重力、马赫数
    double Ma_n       = y[0] / Ma;
    double omegazyiba = y[4] * D / y[0];                     // 计算俯仰角速度
    double Cx, Cy, mz;
    inter(Ma_n, alph, omegazyiba, deltaalph, &Cx, &Cy, &mz); // 计算气动力和力矩

    // 右端微分方程
    dydt[0] = -0.5 * rho_n * pow(y[0], 2) * Cx / M * pow(D, 2) * PI / 4 - g * sin(y[1]);
    dydt[1] = 0.5 * rho_n * pow(y[0], 2) * Cy * D * L / (y[0] * M) - g * cos(y[1]) / y[0];
    dydt[2] = y[0] * cos(y[1]);
    dydt[3] = y[0] * sin(y[1]);
    dydt[4] = mz * pow(y[0], 2) * 0.5 * rho_n * pow(D, 2) * PI / 4 / JZ; // 俯仰角加速度
    dydt[5] = y[4];                                                      // 俯仰角速度
}

// 终止条件函数
int stop(double t, double y[]) {
    return y[3] <= 0; // 终止条件：当高度为 0 时停止
}

void missile_trajectory_calc() {

                      // 初始条件
    double y_0[6]   = {750.0 / 3600.0, 0.0, 0.0, 4000.0, 0.0, 0.0};
    double tspan[2] = {0.0, 200.0};
    double dt       = 0.1; // 时间步长

    // 数值求解：欧拉法或 Runge-Kutta 法
    double t    = tspan[0];
    double y[6] = {y_0[0], y_0[1], y_0[2], y_0[3], y_0[4], y_0[5]};
    double dydt[6];

    // 文件输出
    FILE* log_file = fopen("missile_trajectory.txt", "w");
    FILE* csv_file = fopen("missile_trajectory.csv", "w");

    log_message(log_file, "Starting the calculation...");

    fprintf(csv_file, "time\tvelocity\tpitch_theta\tposition_x\tposition_y\talpha\tdelta_z\n");

    while (t <= tspan[1]) {
        odefun(t, y, dydt); // 求解微分方程

        // 更新状态变量
        for (int i = 0; i < 6; i++) {
            y[i] += dydt[i] * dt;
        }

        double data_to_csv[7] = {t, y[0], y[1], y[2], y[3], y[5] - y[1], dydt[0]};
        log_data(csv_file, data_to_csv, 7);
        log_message(log_file, "Successfully writing data...");
    }

    fclose(log_file);
    fclose(csv_file);
}
