#pragma once

#include <stdio.h>

void log_message(FILE* log_file, const char* message);

void log_data(FILE* csv_file, double data[], int data_size);
