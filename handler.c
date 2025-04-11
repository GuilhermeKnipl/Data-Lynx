

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum{
	FLOAT,
	INT,
	CHAR
}Dtype;

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


void DType(Col a){
	switch (a.dtype){
	case INT:
		printf("Integer\n");
		break;
	case FLOAT:
		printf("FLOAT\n");
		break;
	case CHAR:
		printf("CHAR\n");
		break;
	}
}

// Swich case
void allocating_vector();

int main(){
	Col *a = (Col*)malloc(sizeof(Col));
	Col *b = (Col*)malloc(sizeof(Col));
	Col *c = (Col*)malloc(sizeof(Col));
	

	//a->idx = (int*)malloc(sizeof(int));
	int len = 2;
	a->dtype = INT;
	b->dtype = INT;
	c->dtype = CHAR;

	switch (a->dtype) {
		case INT:
			a->vector.i = (int*)malloc(len*sizeof(int));
			b->vector.i =(int*) malloc(len*sizeof(int));
				c->vector.s = (char*)malloc(len*sizeof(char));
			break;
		case FLOAT:
			NULL;
			break;
		case CHAR:
			c->vector.s = (char*)malloc(len*sizeof(char));
			break;

	
	};

	*b->vector.i = 44;
	*a->vector.i = 10;
	strcpy(c->vector.s, "Hello");
	a->idx = 0;
	b->idx = 1;
	c->idx = 2;

	DataFrame df;
	df.cols = (Col*)malloc(3* sizeof(Col));
	df.cols[0] = *a;
	df.cols[1] = *b;
	df.cols[2] = *c;

	for(int i = 0; i < 3; i++){
		if (i!=2){
			printf("\nidx = %d",df.cols[i].idx);
			printf("\nvalue = %d", *df.cols[i].vector.i);
		}else{
			printf("\n%s", df.cols[i].vector.s);
	}
	}
	Col d;
	d.dtype = INT;
	
	DType(d);
	return 1;
}
