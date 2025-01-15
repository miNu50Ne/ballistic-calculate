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

#include "components/calculate/strategy_trajectory/strategy_trajectory.h"
#include "components/log/log.h"
#include <math.h>
#include <stdio.h>

// int main() {
//     strategy_params_init();
//     strategy_trajectory_calc();
//     return 0;
// }
void interpolate_coefficients(
    double Mach, double alpha, double* Cx, double* Cy, double* Mz, double* alpha_div_delta_z_B) {
    // 数据表
    double Ma[]                = {0.6, 0.8, 0.9, 1.0, 1.1};
    double Cx0[]               = {0.14942, 0.15754, 0.17140, 0.28832, 0.34312};
    double Cx_alpha2[]         = {0.00186, 0.00190, 0.00192, 0.00200, 0.00209};
    double Cy_alpha[]          = {0.06977, 0.06948, 0.06933, 0.07114, 0.07427};
    double Mz_delta_z[]        = {-0.1323, -0.1323, -0.1322, -0.1531, -0.1525};
    double alpha_div_delta_B[] = {-1.16, -1.17, -1.20, -1.25, -1.17};

    // 线性插值
    int n = sizeof(Ma) / sizeof(Ma[0]);
    int i;
    for (i = 0; i < n - 1; i++) {
        if (Mach >= Ma[i] && Mach <= Ma[i + 1]) {
            double t = (Mach - Ma[i]) / (Ma[i + 1] - Ma[i]);

            *Cx = Cx0[i] + t * (Cx0[i + 1] - Cx0[i])
                + (Cx_alpha2[i] + t * (Cx_alpha2[i + 1] - Cx_alpha2[i])) * alpha * alpha;

            *Cy = Cy_alpha[i] + t * (Cy_alpha[i + 1] - Cy_alpha[i]) * alpha;

            *Mz_delta_z = Mz_delta_z[i] + t * (Mz_delta_z[i + 1] - Mz_delta_z[i]);

            *alpha_div_delta_z_B =
                alpha_div_delta_B[i] + t * (alpha_div_delta_B[i + 1] - alpha_div_delta_B[i]);
            return;
        }
    }

    // 超出插值范围，取边界值
    if (Mach < Ma[0]) {
        *Cx                  = Cx0[0] + Cx_alpha2[0] * alpha * alpha;
        *Cy                  = Cy_alpha[0] * alpha;
        *Mz_delta_z          = Mz_delta_z[0];
        *alpha_div_delta_z_B = alpha_div_delta_B[0];
    } else {
        *Cx                  = Cx0[n - 1] + Cx_alpha2[n - 1] * alpha * alpha;
        *Cy                  = Cy_alpha[n - 1] * alpha;
        *Mz_delta_z          = Mz_delta_z[n - 1];
        *alpha_div_delta_z_B = alpha_div_delta_B[n - 1];
    }
}
// // 主程序
int main() {
    // 初始条件
    double t = 0, dt = 0.01, t_max = 30;    // 时间和时间步长
    double x = 0, y = 4000;                 // 位置 (m)
    double theta      = DEG2RAD(0);         // 初始俯仰角 (rad)
    double V          = 750. * 1000 / 3600; // 初始速度 (m/s)
    double m          = 225;                // 质量 (kg)
    double d          = 0.299;              // 弹体直径 (m)
    double alpha_star = 0;                  // 初始攻角 (rad)
    double alpha_glid = DEG2RAD(5);         // 滑翔攻角 (rad)
    double alpha_B    = 0;                  // 攻角修正 (rad)
    double delta_z    = 0;

    // 文件输出
    printf("hello world!");
    FILE* log_file = fopen("strategy_trajectory_log.txt", "w");
    FILE* csv_file = fopen("strategy_trajectory_data.csv", "w");

    if (log_file == NULL || csv_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    log_message(log_file, "Starting the calculation...");

    fprintf(csv_file, "time\tvelocity\tpitch_theta\tposition_x\tposition_y\talpha\tdelta_z\n");

    // 时间循环
    while (t <= t_max) {
        // 切换攻角
        if (t > 3) {
            alpha_star = alpha_glid;
        }

        // 计算马赫数
        double Mach = V / 340.0; // 假设音速为 340 m/s

        // 插值气动力系数
        double Cx, Cy, Mz_delta_z, alpha_div_delta_z_B;
        interpolate_coefficients(Mach, alpha_B, &Cx, &Cy, &Mz_delta_z, &alpha_div_delta_z_B);

        // 气动力计算
        double rho = DEN_ON * pow(1.0 - 2.0323e-5 * y, 4.83); // 空气密度
        double X_B = 0.5 * rho * V * V * d * Cx;
        double Y_B = 0.5 * rho * V * V * d * Cy;

        // 重力修正
        double g = GRA_ON * (1 - 2 * y / EARTH_RAD);

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
        delta_z = alpha_B / alpha_div_delta_z_B;
        // 输出结果
        fprintf(
            csv_file, "%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", t, V, RAD2DEG(theta), x, y,
            RAD2DEG(alpha_B), RAD2DEG(delta_z));

        log_message(log_file, "Successfully writing data...");

        // 时间更新
        t += dt;

        // 检查结束条件
        if (y <= 0) {
            break; // 弹体落地
        }
    }
    log_message(log_file, "Calculation finished.");
    fclose(log_file);
    fclose(csv_file);
    return 0;
}