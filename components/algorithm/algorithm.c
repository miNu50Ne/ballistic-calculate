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
    runge_kutta_4_t* runge_kutta_param, equation_t* equations,
    void*(formula)(double, double[], double[])) {
    double start_time          = runge_kutta_param->start_time;
    double end_time            = runge_kutta_param->end_time;
    double time_step           = runge_kutta_param->time_step;
    double* initial_conditions = runge_kutta_param->initial_conditions;
    int formula_num            = runge_kutta_param->formula_num;

    double k_1[formula_num];
    double k_2[formula_num];
    double k_3[formula_num];
    double k_4[formula_num];
    double temp[formula_num];

    formula(equations->time, equations->independent_variable, k_1);

    for (int i = 0; i < formula_num; i++)
        temp[i] = equations->independent_variable[i] + 0.5 * time_step * k_1[i];
    formula(equations->time + 0.5 * time_step, temp, k_2);

    for (int i = 0; i < formula_num; i++)
        temp[i] = equations->independent_variable[i] + 0.5 * time_step * k_2[i];
    formula(equations->time + 0.5 * time_step, temp, k_3);

    for (int i = 0; i < formula_num; i++)
        temp[i] = equations->independent_variable[i] + time_step * k_3[i];
    formula(equations->time + time_step, equations->independent_variable, k_4);
    for (int i = 0; i < formula_num; i++) {
        equations->independent_variable[i] +=
            (time_step / 6.0) * (k_1[i] + 2 * k_2[i] + 2 * k_3[i] + k_4[i]);
    }
}
/**
 * @brief newton interpolation function
 *
 */
double newton_interpolation(newton_t* newton_params) {
    double* sample_x_input = newton_params->sample_x_input;
    double* sample_y_input = newton_params->sample_y_input;
    double interpole_x     = newton_params->interpole_x_point;
    int rank               = newton_params->rank;

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

    for (int k = 1; k < rank; k++) {
        term *= (interpole_x - sample_x_input[k - 1]);
        interpole_y += divided_differences[k][k] * term;
    }

    return interpole_y;
}