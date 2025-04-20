#ifndef HANDLER_H
#define HANDLER_H
#include "types.h"
#include <stdio.h>
#include <stdbool.h>

extern bool check_value(char inpt[]);

extern Dtype dtypehandler(char value[]);

extern int csv_len(FILE * file);

extern int int_handler(char*value);

extern float float_handler(char*value);

extern void allocate_vector(int len,DataFrame * df, int idx);

#endif
