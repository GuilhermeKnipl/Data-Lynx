#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


//Identifying Dtype of cols
void identify_dtype();

// Allocating Space according to Datatype;
void allocate_vector(int len, Col *column){  
	switch(column->dtype){
		case INT:
			column->vector.i = (int*)malloc(len*sizeof(int));
			break;
		case FLOAT:
			column->vector.f = (float*)malloc(len*sizeof(float));
			break;
		case CHAR:
			column->vector.s = (char*)malloc(len*sizeof(char));
			break;
	}
	
};

int csv_len(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    int lines = 0;
    int ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }
    fclose(file);
    return lines;
}


int main(){
	Col *a = (Col*)malloc(sizeof(Col));
	Col *b = (Col*)malloc(sizeof(Col));
	Col *c = (Col*)malloc(sizeof(Col));
	
	char *filepath = "debug/Housing.csv";

	int len_csv = csv_len(filepath);

	printf("\n=--%d", len_csv);
	
	//a->idx = (int*)malloc(sizeof(int));
	int len = 2;
	a->dtype = INT;
	b->dtype = INT;
	c->dtype = CHAR;

	allocate_vector(len_csv, a);
	allocate_vector(len_csv, b);
	allocate_vector(len_csv, c);

		

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
			printf("\nidx = %d",df.cols[i].idx);
			printf("\nvalue = %s\n", df.cols[i].vector.s);
	}
	}
	Col d;
	d.dtype = INT;
	
	//DType(d);
	return 1;
}
