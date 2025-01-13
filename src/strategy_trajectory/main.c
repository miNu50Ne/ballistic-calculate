/**
 * @file strategy_trajectory
 * @author miNu50Ne (minu50ne@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-11-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "components/algorithm/algorithm.h"
#include "components/condition/strategy_trajectory.h"
#include <math.h>
#include <stdio.h>

static equation_t strategy_trajectory_equations;
static runge_kutta_4_t runge_kutta_params;
int main() {}

// // 主程序
// int main() {
//     // 初始条件
//     double t = 0, dt = 0.01, t_max = 60;    // 时间和时间步长
//     double x = 0, y = 4000;                 // 位置 (m)
//     double theta      = DEG2RAD(0);         // 初始俯仰角 (rad)
//     double V          = 750. * 1000 / 3600; // 初始速度 (m/s)
//     double m          = 225;                // 质量 (kg)
//     double d          = 0.299;              // 弹体直径 (m)
//     double alpha_star = 0;                  // 初始攻角 (rad)
//     double alpha_glid = DEG2RAD(5);         // 滑翔攻角 (rad)
//     double alpha_B    = 0;                  // 攻角修正 (rad)

//     // 文件输出
//     FILE* file = fopen("trajectory.txt", "w");
//     if (!file) {
//         printf("无法打开文件！\n");
//         return -1;
//     }
//     fprintf(file, "Time\tX\tY\tV\tAlpha\tTheta\n");

//     // 时间循环
//     while (t <= t_max) {
//         // 切换攻角
//         if (t > 3) {
//             alpha_star = alpha_glid;
//         }

//         // 计算马赫数
//         double Mach = V / 340.0; // 假设音速为 340 m/s

//         // 插值气动力系数
//         double Cx, Cy, Mz_delta_z;
//         interpolate_coefficients(Mach, alpha_B, &Cx, &Cy, &Mz_delta_z);

//         // 气动力计算
//         double rho = RHO_ON * pow(1.0 - 2.0323e-5 * y, 4.83); // 空气密度
//         double X_B = 0.5 * rho * V * V * d * Cx;
//         double Y_B = 0.5 * rho * V * V * d * Cy;

//         // 重力修正
//         double g = G * (1 - 2 * y / R);

//         // 动力学方程
//         double dV     = (-X_B - m * g * sin(theta)) / m;
//         double dTheta = (Y_B - m * g * cos(theta)) / m;
//         double dx     = V * cos(theta);
//         double dy     = V * sin(theta);

//         // 状态更新
//         V += dV * dt;
//         theta += dTheta * dt;
//         x += dx * dt;
//         y += dy * dt;
//         alpha_B = alpha_star;

//         // 输出结果
//         fprintf(
//             file, "%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", t, x, y, V, RAD2DEG(alpha_B),
//             RAD2DEG(theta));

//         // 时间更新
//         t += dt;

//         // 检查结束条件
//         if (y <= 0) {
//             break; // 弹体落地
//         }
//     }

//     fclose(file);
//     printf("弹道计算完成，结果已保存到 trajectory.txt。\n");
//     return 0;
// }