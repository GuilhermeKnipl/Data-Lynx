#ifndef TYPES_H
#define TYPES_H


typedef enum{
	FLOAT,
	INT,
	CHAR
}Dtype;


// vector datatype specification
typedef union {
    int* i;
    float* f;
    double* d;
    char* s;  
} DVector;

typedef struct{
	char clumn_name;
	int idx;
	Dtype dtype;
	DVector vector;
}Col;

typedef struct DataFrame{
	Col* cols;	
}DataFrame ;

#endif


