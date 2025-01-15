#pragma once

typedef struct {
    double time_;
    double* independent_variable;
} equation_t;

typedef struct {
    double time_step;
    int formula_num;
} runge_kutta_4_t;

typedef struct {
    const double* sample_x_input;
    const double* sample_y_input;
    double interpole_x_point;
    int rank;
} newton_t;

void runge_kutta_rank4(
    runge_kutta_4_t* runge_kutta_param, equation_t* equations, double*(formula)(double, double[]));

double newton_interpolation(newton_t* newton_params);