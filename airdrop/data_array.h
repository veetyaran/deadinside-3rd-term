#include "data.h"
#ifndef DATA_ARRAY_H
#define DATA_ARRAY_H
int f(int s, int n, int i);
int read_array(data* data_arr, int n, const char* filename);
void init_array(data* data_arr, int n, int s);
void print_array(data* data_arr, int n);
int diff(data* data_arr, int n);
#endif