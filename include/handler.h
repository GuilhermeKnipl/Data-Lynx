#ifndef HANDLER_H
#define HANDLER_H
#include "types.h"


extern bool check_value(char inpt[]);

extern Dtype dtypehandler(char value[]);

extern int csv_len(const char* filename);

extern void allocate_vector(int len, Col *column);

#endif
