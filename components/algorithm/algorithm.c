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

/**
 * @brief Fourth level Runge-Kutta method
 *
 */
void runge_kutta_rank4(
    runge_kutta_4_t* runge_kutta_param, equation_t* equations, double*(formula)(double, double[])) {

    double time_step = runge_kutta_param->time_step;
    int formula_num  = runge_kutta_param->formula_num;

    double* k_1;
    double* k_2;
    double* k_3;
    double* k_4;

    double temp[formula_num];

    k_1 = formula(equations->time_, equations->independent_variable);

    for (int i = 0; i < formula_num; i++)
        temp[i] = equations->independent_variable[i] + 0.5 * time_step * k_1[i];

    k_2 = formula(equations->time_ + 0.5 * time_step, temp);

    for (int i = 0; i < formula_num; i++)
        temp[i] = equations->independent_variable[i] + 0.5 * time_step * k_2[i];

    k_3 = formula(equations->time_ + 0.5 * time_step, temp);
    for (int i = 0; i < formula_num; i++)
        temp[i] = equations->independent_variable[i] + time_step * k_3[i];

    k_4 = formula(equations->time_ + time_step, temp);

    for (int i = 0; i < formula_num; i++)
        equations->independent_variable[i] =
            equations->independent_variable[i]
            + (time_step / 6.) * (k_1[i] + 2 * k_2[i] + 2 * k_3[i] + k_4[i]);
}
/**
 * @brief newton interpolation function
 *
 */
double newton_interpolation(newton_t* newton_params) {
    const double* sample_x_input = newton_params->sample_x_input;
    const double* sample_y_input = newton_params->sample_y_input;
    double interpole_x           = newton_params->interpole_x_point;
    int rank                     = newton_params->rank;

    double divided_differences[rank][rank] = {};

    for (int i = 0; i < rank; i++) {
        divided_differences[i][0] = sample_y_input[i];
    }

    for (int j = 1; j < rank; j++) {
        for (int i = j; i < rank; i++) {
            divided_differences[i][j] =
                (divided_differences[i][j - 1] - divided_differences[i - 1][j - 1])
                / (sample_x_input[i] - sample_x_input[i - j]);
        }
    }
    double interpole_y = divided_differences[0][0];
    double term        = 1.0;
    if (interpole_x >= sample_x_input[0] && interpole_x <= sample_x_input[rank - 1]) {
        for (int k = 1; k < rank; k++) {
            term *= (interpole_x - sample_x_input[k - 1]);
            interpole_y += divided_differences[k][k] * term;
        }
    }
    if (interpole_x < sample_x_input[0]) {
        interpole_y = sample_y_input[0];
    } else if (interpole_x > sample_x_input[rank - 1]) {
        interpole_y = sample_y_input[rank - 1];
    }

    return interpole_y;
}

// void linear_interpolation(double Mach, double alpha, double* Cx, double* Cy, double* Mz) {
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

// // 超出插值范围，取边界值
// if (Mach < Ma[0]) {
//     *Cx         = Cx0[0] + Cx_alpha2[0] * alpha * alpha;
//     *Cy         = Cy_alpha[0] * alpha;
//     *Mz_delta_z = Mz_delta_z[0];
// } else {
//     *Cx         = Cx0[n - 1] + Cx_alpha2[n - 1] * alpha * alpha;
//     *Cy         = Cy_alpha[n - 1] * alpha;
//     *Mz_delta_z = Mz_delta_z[n - 1];
// }
// }