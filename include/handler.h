#ifndef HANDLER_H
#define HANDLER_H
#include "types.h"
#include <stdio.h>


extern bool check_value(char inpt[]);

extern Dtype dtypehandler(char value[]);

extern int csv_len(FILE * file);

extern void allocate_vector(int len, Col *column);

#endif
