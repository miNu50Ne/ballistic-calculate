/**
 * @file calc.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-11-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <math.h>
#include <stdio.h>

// 常数定义
#define G              9.806     // 重力加速度 (m/s^2)
#define R              6371000.0 // 地球半径 (m)
#define RHO_ON         1.225     // 海平面空气密度 (kg/m^3)
#define TAU_ON         288.34    // 海平面温度 (K)
#define PI             3.14159265359
#define DEG2RAD(angle) ((angle) * PI / 180.0)
#define RAD2DEG(angle) ((angle) * 180.0 / PI)

// 插值函数：返回给定马赫数对应的气动力系数
void interpolate_coefficients(double Mach, double alpha, double* Cx, double* Cy, double* Mz_dz) {
    // 数据表
    double Ma[]         = {0.6, 0.8, 0.9, 1.0, 1.1};
    double Cx0[]        = {0.14942, 0.15754, 0.17140, 0.28832, 0.34312};
    double Cx_alpha2[]  = {0.00186, 0.00190, 0.00192, 0.00200, 0.00209};
    double Cy_alpha[]   = {0.06977, 0.06948, 0.06933, 0.07114, 0.07427};
    double Mz_delta_z[] = {-0.1323, -0.1323, -0.1322, -0.1531, -0.1525};

    // 线性插值
    int n = sizeof(Ma) / sizeof(Ma[0]);
    int i;
    for (i = 0; i < n - 1; i++) {
        if (Mach >= Ma[i] && Mach <= Ma[i + 1]) {
            double t = (Mach - Ma[i]) / (Ma[i + 1] - Ma[i]);
            *Cx      = Cx0[i] + t * (Cx0[i + 1] - Cx0[i])
                + (Cx_alpha2[i] + t * (Cx_alpha2[i + 1] - Cx_alpha2[i])) * alpha * alpha;
            *Cy         = Cy_alpha[i] + t * (Cy_alpha[i + 1] - Cy_alpha[i]) * alpha;
            *Mz_delta_z = Mz_delta_z[i] + t * (Mz_delta_z[i + 1] - Mz_delta_z[i]);
            return;
        }
    }

    // 超出插值范围，取边界值
    if (Mach < Ma[0]) {
        *Cx         = Cx0[0] + Cx_alpha2[0] * alpha * alpha;
        *Cy         = Cy_alpha[0] * alpha;
        *Mz_delta_z = Mz_delta_z[0];
    } else {
        *Cx         = Cx0[n - 1] + Cx_alpha2[n - 1] * alpha * alpha;
        *Cy         = Cy_alpha[n - 1] * alpha;
        *Mz_delta_z = Mz_delta_z[n - 1];
    }
}

// 主程序
int main() {
    // 初始条件
    double t = 0, dt = 0.01, t_max = 60;   // 时间和时间步长
    double x = 0, y = 4000;                // 位置 (m)
    double theta      = DEG2RAD(0);        // 初始俯仰角 (rad)
    double V          = 750 * 1000 / 3600; // 初始速度 (m/s)
    double m          = 225;               // 质量 (kg)
    double d          = 0.299;             // 弹体直径 (m)
    double alpha_star = 0;                 // 初始攻角 (rad)
    double alpha_glid = DEG2RAD(5);        // 滑翔攻角 (rad)
    double alpha_B    = 0;                 // 攻角修正 (rad)

    // 文件输出
    FILE* file = fopen("trajectory.txt", "w");
    if (!file) {
        printf("无法打开文件！\n");
        return -1;
    }
    fprintf(file, "Time\tX\tY\tV\tAlpha\tTheta\n");

    // 时间循环
    while (t <= t_max) {
        // 切换攻角
        if (t > 3) {
            alpha_star = alpha_glid;
        }

        // 计算马赫数
        double Mach = V / 340.0; // 假设音速为 340 m/s

        // 插值气动力系数
        double Cx, Cy, Mz_delta_z;
        interpolate_coefficients(Mach, alpha_B, &Cx, &Cy, &Mz_delta_z);

        // 气动力计算
        double rho = RHO_ON * pow(1.0 - 2.0323e-5 * y, 4.83); // 空气密度
        double X_B = 0.5 * rho * V * V * d * Cx;
        double Y_B = 0.5 * rho * V * V * d * Cy;

        // 重力修正
        double g = G * (1 - 2 * y / R);

        // 动力学方程
        double dV     = (-X_B - m * g * sin(theta)) / m;
        double dTheta = (Y_B - m * g * cos(theta)) / m;
        double dx     = V * cos(theta);
        double dy     = V * sin(theta);

        // 状态更新
        V += dV * dt;
        theta += dTheta * dt;
        x += dx * dt;
        y += dy * dt;
        alpha_B = alpha_star;

        // 输出结果
        fprintf(
            file, "%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", t, x, y, V, RAD2DEG(alpha_B),
            RAD2DEG(theta));

        // 时间更新
        t += dt;

        // 检查结束条件
        if (y <= 0) {
            break; // 弹体落地
        }
    }

    fclose(file);
    printf("弹道计算完成，结果已保存到 trajectory.txt。\n");
    return 0;
}