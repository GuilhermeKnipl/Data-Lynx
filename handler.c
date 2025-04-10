

#include <stdio.h>
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

typedef DataFrame{
	
} ;


void test(Col a){
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
	Col d;
	d.dtype = INT;
	
	test(d);
	return 1;
}
