#pragma once

#define EARTH_RAD 6371000.0 // m
#define DEN_ON    1.225     // g/m3
#define TEM_ON    288.34    // K
#define GRA_ON    9.806     // m/s2

#define KMPH2MPS (1000 / 3600.0f)

#define PI             3.14159265359
#define DEG2RAD(angle) ((angle) * PI / 180.0)
#define RAD2DEG(angle) ((angle) * 180.0 / PI)

#define VELOCITY    0
#define PITCH_THETA 1
#define POSITION_X  2
#define POSITION_Y  3

#define CX_0                0
#define CX_ALPHA2           1
#define CY_ALPHA            2
#define ALPHA_DIV_DELTA_Z_B 3
#define CY_DELTA_Z          4
#define MZ_DELTA_Z          5
#define MZ_OMEGA_z          6

typedef struct {
    // resistance force coefficient
    double C_x;
    // lateral force coefficient
    double C_y;
} aerodynamic_coefficient_t;

typedef struct {
    // resistance force
    double X_b;
    // lateral force
    double Y_b;
} aerodynamic_force_t;

typedef struct {
    // time
    double time_;
    double start_time;
    double end_time;
    double time_step;

    // position
    double position_x;
    double position_y;

    // status
    double pitch_theta;
    double velocity;
    double delta_z;

    double alpha;
    double star_alpha;
    double glid_alpha;

    // projectile
    double quality;
    double diameter;
    double length;
} stra_model_params_t;

typedef struct {
    double temperature;
    double density;
    double sound_speed;
    double gravity;
} meteorological_condition_t;

typedef struct {
    double diff_position_x;
    double diff_position_y;
    double diff_pitch_theta;
    double diff_velocity;
} ballistics_state_t;

void strategy_params_init();
void meteorological_params();
void aero_params_interpolation();
void aerodynamic_calc();
double* dynamics_equations(double time, double* variable);
void strategy_trajectory_calc();
