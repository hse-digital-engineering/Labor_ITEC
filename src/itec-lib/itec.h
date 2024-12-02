#pragma once
#include <time.h> //c_clock for time measurement

void swap(int* i, int *j);

void printf_array(int length, int *arr);

void printf_elapsed_time(clock_t end, clock_t start);