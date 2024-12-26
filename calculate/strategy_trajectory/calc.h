#pragma once
typedef struct Aeroforce {
    double Ma[5];
};
double Ma[]         = {0.6, 0.8, 0.9, 1.0, 1.1};
double Cx0[]        = {0.14942, 0.15754, 0.17140, 0.28832, 0.34312};
double Cx_alpha2[]  = {0.00186, 0.00190, 0.00192, 0.00200, 0.00209};
double Cy_alpha[]   = {0.06977, 0.06948, 0.06933, 0.07114, 0.07427};
double Mz_delta_z[] = {-0.1323, -0.1323, -0.1322, -0.1531, -0.1525};
