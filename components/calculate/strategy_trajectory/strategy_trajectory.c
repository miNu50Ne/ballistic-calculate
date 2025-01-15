/**
 * @file strategy_trajectory.c
 * @author miNu50Ne (miNu50Ne@qq.com)
 * @brief
 * @version 0.1
 * @date 2025-01-13
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "strategy_trajectory.h"
#include "components/algorithm/algorithm.h"
#include "components/log/log.h"

#include <math.h>
#include <stdio.h>

static stra_model_params_t strategy_trajectory;
static meteorological_condition_t meteorological_condition;
static ballistics_state_t ballistics_state;

static runge_kutta_4_t runge_kutta_instance;
static equation_t equations_params;

static newton_t meteo_newton_inter_instance;
static aerodynamic_coefficient_t aerodynamic_coefficient;
static aerodynamic_force_t aerodynamic_force;
static double inter_aerodynamic_coefficient[7];

void strategy_params_init() {
    strategy_trajectory.start_time = 0, strategy_trajectory.time_ = 0,
    strategy_trajectory.end_time = 30, strategy_trajectory.time_step = 0.01,

    strategy_trajectory.position_x = 0, strategy_trajectory.position_y = 4000,

    strategy_trajectory.velocity = 750. * KMPH2MPS, strategy_trajectory.pitch_theta = DEG2RAD(0),

    strategy_trajectory.delta_z = 0,

    strategy_trajectory.alpha = 0, strategy_trajectory.star_alpha = 0,
    strategy_trajectory.glid_alpha = DEG2RAD(5),

    strategy_trajectory.diameter = 0.299, strategy_trajectory.quality = 25,
    strategy_trajectory.length = 0.214;
}

void meteorological_params() {
    meteorological_condition.temperature = TEM_ON - 5.86 * 10e-3 * strategy_trajectory.position_y;

    meteorological_condition.sound_speed = 20.046 * pow(meteorological_condition.temperature, 0.5);

    meteorological_condition.gravity =
        GRA_ON * (1.0 - 2 * strategy_trajectory.position_y / EARTH_RAD);

    meteorological_condition.density =
        DEN_ON * pow((1.0 - 2.0323 * 10e-5 + strategy_trajectory.position_y), 4.83);
}

void aero_params_interpolation() {
    const double Ma[] = {0.6, 0.8, 0.9, 1.0, 1.1};

    const double aerodynamic_coefficient[7][5] = {
        { 0.14942,  0.15754,  0.17140,  0.28832,  0.34312},
        { 0.00186,  0.00190,  0.00192,  0.00200,  0.00209},
        { 0.06977,  0.06948,  0.06933,  0.07114,  0.07427},
        {   -1.16,    -1.17,     -1.2,    -1.25,    -1.17},
        {  0.0311,  0.03244,  0.03177,  0.03669,  0.03711},
        { -0.1323,  -0.1323,  -0.1322,  -0.1531,  -0.1525},
        {-13.0898, -13.9252, -13.8327, -14.5677, -15.3393},
    };

    meteo_newton_inter_instance.sample_x_input = Ma;
    meteo_newton_inter_instance.rank           = 5;
    meteo_newton_inter_instance.interpole_x_point =
        strategy_trajectory.velocity / meteorological_condition.sound_speed;

    for (size_t i = 0; i < 7; i++) {
        meteo_newton_inter_instance.sample_y_input = aerodynamic_coefficient[i];
        inter_aerodynamic_coefficient[i] = newton_interpolation(&meteo_newton_inter_instance);
    }
}

void aerodynamic_calc() {
    // aerodynamic coefficient
    aerodynamic_coefficient.C_x =
        inter_aerodynamic_coefficient[CX_0]
        + inter_aerodynamic_coefficient[CX_ALPHA2] * pow(strategy_trajectory.alpha, 2.);

    strategy_trajectory.delta_z =
        strategy_trajectory.alpha / inter_aerodynamic_coefficient[ALPHA_DIV_DELTA_Z_B];

    aerodynamic_coefficient.C_y =
        inter_aerodynamic_coefficient[CY_ALPHA] * strategy_trajectory.alpha
        + inter_aerodynamic_coefficient[CY_DELTA_Z] * strategy_trajectory.delta_z;

    // aerodynamic force
    double windward_square =
        PI * 0.25 * strategy_trajectory.diameter * strategy_trajectory.diameter;

    aerodynamic_force.X_b = meteorological_condition.density * strategy_trajectory.velocity
                          * strategy_trajectory.velocity * windward_square
                          * aerodynamic_coefficient.C_x * 0.5;

    double square = strategy_trajectory.diameter * strategy_trajectory.length;

    aerodynamic_force.Y_b = meteorological_condition.density * strategy_trajectory.velocity
                          * strategy_trajectory.velocity * square * aerodynamic_coefficient.C_y
                          * 0.5;
};

double* dynamics_equations(double time, double* variable) {

    double velocity    = variable[VELOCITY];
    double pitch_theta = variable[PITCH_THETA];
    double position_x  = variable[POSITION_X];
    double position_y  = variable[POSITION_Y];

    ballistics_state.diff_velocity = -aerodynamic_force.X_b / strategy_trajectory.quality
                                   - meteorological_condition.gravity * cos(pitch_theta);

    ballistics_state.diff_pitch_theta =
        aerodynamic_force.Y_b / (strategy_trajectory.quality * velocity)
        - meteorological_condition.gravity * cos(pitch_theta);

    ballistics_state.diff_position_x = velocity * cos(pitch_theta);

    ballistics_state.diff_position_y = velocity * cos(pitch_theta);
}

void strategy_trajectory_calc() {
    printf("hello world!");
    FILE* log_file = fopen("strategy_trajectory_log.txt", "w");
    FILE* csv_file = fopen("strategy_trajectory_data.csv", "w");

    if (log_file == NULL || csv_file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    log_message(log_file, "Starting the calculation...");

    fprintf(csv_file, "time\tvelocity\tpitch_theta\tposition_x\tposition_y\talpha\tdelta_z\n");

    strategy_trajectory.time_ = strategy_trajectory.start_time;

    while (strategy_trajectory.time_ <= strategy_trajectory.end_time) {
        if (strategy_trajectory.time_ > 3.)
            strategy_trajectory.alpha = strategy_trajectory.glid_alpha;
        else
            strategy_trajectory.alpha = strategy_trajectory.star_alpha;

        // meteorological caculation
        meteorological_params();
        // aerodynamic interpolation
        aero_params_interpolation();
        // aerodynamic parameters calculation
        aerodynamic_calc();

        // equations
        equations_params.time_                             = strategy_trajectory.time_;
        equations_params.independent_variable[VELOCITY]    = strategy_trajectory.velocity;
        equations_params.independent_variable[PITCH_THETA] = strategy_trajectory.pitch_theta;
        equations_params.independent_variable[POSITION_X]  = strategy_trajectory.position_x;
        equations_params.independent_variable[POSITION_Y]  = strategy_trajectory.position_y;

        // runge_kutta
        runge_kutta_instance.formula_num = 4;
        runge_kutta_instance.time_step   = strategy_trajectory.time_step;

        runge_kutta_rank4(&runge_kutta_instance, &equations_params, dynamics_equations);

        // update
        strategy_trajectory.time_ += strategy_trajectory.time_step;
        strategy_trajectory.position_x +=
            ballistics_state.diff_position_x * strategy_trajectory.time_step;
        strategy_trajectory.position_y =
            ballistics_state.diff_position_x * strategy_trajectory.time_step;
        strategy_trajectory.velocity =
            ballistics_state.diff_velocity * strategy_trajectory.time_step;
        strategy_trajectory.pitch_theta =
            ballistics_state.diff_pitch_theta * strategy_trajectory.time_step;

        double data_to_csv[7] = {strategy_trajectory.time_,       strategy_trajectory.velocity,
                                 strategy_trajectory.pitch_theta, strategy_trajectory.position_x,
                                 strategy_trajectory.position_y,  strategy_trajectory.alpha,
                                 strategy_trajectory.delta_z};
        log_data(csv_file, data_to_csv, 7);
        log_message(log_file, "Successfully writing data...");

        if (strategy_trajectory.position_y <= 0) {
            break;
        }
    }

    log_message(log_file, "Calculation finished.");

    fclose(log_file);
    fclose(csv_file);
}