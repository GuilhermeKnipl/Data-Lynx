#include <stdio.h>
#include <string.h>


typedef enum{
	INT,
	FLOAT,
	CHAR,
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



void PDatatype(Col a){
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
	

	FILE *file = fopen("debug/Housing.csv", "r");



	if (file == NULL){
		printf("empty file\n");
	}else{
		printf("Readed\n");
	}
	char line[256];

	int a = 0;
	int b = 0;
	int columns_iter = 0;
	while (fgets(line, sizeof(line), file)) {
		a++ ;
		b = 0;
		columns_iter++ ;
		printf("--\nNew line--");
		char* tok = strtok(line,",");
		while (tok != NULL){
			printf("\n%s",tok);
			tok = strtok(NULL, ",");
		}
		if(a == 3){break;}
	}


	return 0;
}
