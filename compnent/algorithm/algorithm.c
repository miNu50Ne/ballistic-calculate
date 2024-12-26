/**
 * @file algorithm.c
 * @author MiNu50Ne (minus0ne@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-11-11
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "algorithm.h"

// 插值函数：返回给定马赫数对应的气动力系数
// void interpolate_coefficients(double Mach, double alpha, double* Cx, double* Cy, double* Mz) {
//     // 数据表

//     // 线性插值
//     int n = sizeof(Ma) / sizeof(Ma[0]);
//     int i;
//     for (i = 0; i < n - 1; i++) {
//         if (Mach >= Ma[i] && Mach <= Ma[i + 1]) {
//             double t = (Mach - Ma[i]) / (Ma[i + 1] - Ma[i]);

//             *Cx = Cx0[i] + t * (Cx0[i + 1] - Cx0[i])
//                 + (Cx_alpha2[i] + t * (Cx_alpha2[i + 1] - Cx_alpha2[i])) * alpha * alpha;

//             *Cy = Cy_alpha[i] + t * (Cy_alpha[i + 1] - Cy_alpha[i]) * alpha;

//             *Mz_delta_z = Mz_delta_z[i] + t * (Mz_delta_z[i + 1] - Mz_delta_z[i]);
//             return;
//         }
//     }

//     // 超出插值范围，取边界值
//     if (Mach < Ma[0]) {
//         *Cx         = Cx0[0] + Cx_alpha2[0] * alpha * alpha;
//         *Cy         = Cy_alpha[0] * alpha;
//         *Mz_delta_z = Mz_delta_z[0];
//     } else {
//         *Cx         = Cx0[n - 1] + Cx_alpha2[n - 1] * alpha * alpha;
//         *Cy         = Cy_alpha[n - 1] * alpha;
//         *Mz_delta_z = Mz_delta_z[n - 1];
//     }
// }