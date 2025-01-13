#pragma once

typedef struct {
    double time;
    double* independent_variable;
    double* differential_independent_variable;
} equation_t;

typedef struct {
    double start_time;
    double end_time;
    double time_step;
    double* initial_conditions;
    int formula_num;
} runge_kutta_4_t;

typedef struct {
    double* sample_x_input;
    double* sample_y_input;
    double interpole_x_point;
    int rank;
} newton_t;

void runge_kutta_rank4(
    runge_kutta_4_t* runge_kutta_param, equation_t* equations,
    void*(formula)(double, double[], double[]));

double newton_interpolation(newton_t* newton_params);