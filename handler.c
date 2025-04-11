

#include <stdio.h>
#include <stdlib.h>
typedef enum{
	FLOAT,
	INT,
	CHAR
}Dtype;


typedef struct{
	char column_name;
	int idx;
	Dtype dtype;
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




int main(){
	Col *a = (Col*)malloc(sizeof(Col));
	Col *b = (Col*)malloc(sizeof(Col));
	//a->idx = (int*)malloc(sizeof(int));

	a->dtype = INT;
	a->idx = 0;
	b->idx = 1;

	DataFrame df;
	df.cols = (Col*)malloc(2* sizeof(Col));
	df.cols[0] = *a;
	df.cols[1] = *b;

	for(int i = 0; i < 2; i++){
		printf("%d",df.cols[i].idx);
	}

	Col d;
	d.dtype = INT;
	
	DType(d);
	return 1;
}
