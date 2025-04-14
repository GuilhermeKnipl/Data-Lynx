#ifndef TYPES_H
#define TYPES_H

static const char *HOUSING_CSV = "databases/Housing.csv";

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
    char** s;  
} DVector;

typedef struct{
	char column_name;
	int idx;
	Dtype dtype;
	DVector vector;
}Col;

typedef struct DataFrame{
	Col* cols;	
}DataFrame ;

#endif


