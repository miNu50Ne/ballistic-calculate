/**
 * @file trajectory_overload.c
 * @author your name (you@domain.com)
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
#include "trajectory_overload.h"

// 导弹速度函数
double missile_speed(double t) {
    if (t < 2) {
        return 100 * t;
    } else {
        return 200;
    }
}

// 计算相对方位角 (弧度)
double calculate_angle(double x_m, double y_m, double x_t, double y_t) {
    return atan2(y_t - y_m, x_t - x_m); // 计算导弹与目标之间的方位角
}

// 计算导弹与目标的相对速度
double calculate_relative_velocity(double vx_m, double vy_m, double vx_t, double vy_t) {
    return sqrt(pow(vx_m - vx_t, 2) + pow(vy_m - vy_t, 2));
}

// 计算导弹与目标的相对位置
void speed_tracking_calc() {
    double t = 0, dt = 0.01;       // 时间步长
    double x_m = 0, y_m = 0;       // 导弹位置
    double x_t = 120 * t, y_t = 0; // 目标位置
    double r        = R_0;         // 初始相对距离
    double velocity = missile_speed(t);

    double overload;

    // 文件输出
    FILE* log_file = fopen("speed_tracking.txt", "w");
    FILE* csv_file = fopen("speed_tracking.csv", "w");

    if (log_file == NULL || csv_file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    log_message(log_file, "Starting the calculation...");

    fprintf(csv_file, "time\tmissle_x\tmissle_y\ttarget_x\ttarget_y\toverload\n");

    // 计算轨迹
    while (r > 1) {
        t += dt;
        // 更新目标位置
        x_t = V_T * t;
        // 计算导弹与目标的相对位置
        double dx = x_t - x_m;
        double dy = y_t - y_m;

        r = sqrt(dx * dx + dy * dy);

        // 导弹加速度（简化，忽略空气阻力等）
        double accel    = missile_speed(t) / M;
        double overload = accel / G;

        // 更新导弹位置
        x_m += velocity * dt;

        double data_to_csv[] = {t, x_m, y_m, x_t, y_t, overload};

        log_data(csv_file, data_to_csv, 6);
        log_message(log_file, "Successfully writing data...");
    }

    fclose(log_file);
    fclose(csv_file);

    printf("speed_tracking flying time %f, max overload %f\n", t, overload);
}

void proportional_guidance() {

    FILE* log_file = fopen("proportional_guidance.txt", "w");
    FILE* csv_file = fopen("proportional_guidance.csv", "w");

    if (log_file == NULL || csv_file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    log_message(log_file, "Starting the calculation...");

    fprintf(csv_file, "time\tmissle_x\tmissle_y\ttarget_x\ttarget_y\toverload\n");

    double t = 0, dt = 0.01;       // 时间步长
    double x_m = 0, y_m = 0;       // 导弹位置
    double x_t = 120 * t, y_t = 0; // 目标位置
    double vx_m = 0, vy_m = 0;     // 导弹速度
    double vx_t = V_T, vy_t = 0;   // 目标速度
    double r        = R_0;         // 初始相对距离
    double velocity = missile_speed(t);

    double overload;

    // 计算轨迹并写入文件
    while (r > 1) {
        t += dt;
        // 更新目标位置
        x_t = V_T * t;

        // 计算导弹与目标的相对方位角
        double angle = calculate_angle(x_m, y_m, x_t, y_t);

        // 计算导弹与目标的相对速度
        double Vr = calculate_relative_velocity(vx_m, vy_m, vx_t, vy_t);

        // 比例导引法计算导弹的加速度
        double a = K * Vr * angle;

        // 计算导弹的加速度分量（假设导弹的加速度方向是沿着导弹指向目标的方向）
        double ax = a * cos(angle);
        double ay = a * sin(angle);

        // 更新导弹速度
        vx_m += ax * dt;
        vy_m += ay * dt;

        // 更新导弹位置
        x_m += vx_m * dt;
        y_m += vy_m * dt;

        // 计算导弹与目标的相对距离
        double dx = x_t - x_m;
        double dy = y_t - y_m;
        r         = sqrt(dx * dx + dy * dy);

        // 计算弹道过载
        double accel = a / M;
        overload     = accel / G;

        double data_to_csv[] = {t, x_m, y_m, x_t, y_t, overload};

        log_data(csv_file, data_to_csv, 6);
        log_message(log_file, "Successfully writing data...");
    }

    fclose(log_file);
    fclose(csv_file);

    printf("proportional_guidance flying time %f, max overload %f\n", t, overload);
}
