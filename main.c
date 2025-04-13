#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


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


void file_printer(){

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



}

typedef char *String[] ;

bool check_value(char inpt[]){

	if (strchr(inpt, '.')){
		return true;
	}else {
	 return false;
	}
}

Dtype dtypehandler(char value[]){
	
	bool is_float = check_value(value);
	char* endpointer;
	
	double parsed =strtod(value , &endpointer);

	bool is_num = (*endpointer == '\0');
	if (is_num && is_float != true) {
		printf("\nInput: %s  Is An Integer", value);
		return INT; 
	}else if (is_num && is_float) {
		printf("\nInput: %f  Is float", parsed);
		return FLOAT;
	}else {
		printf("\nInput: %s  Is a String", value);
		return CHAR;
	}

}

typedef struct{
	int* i;
	char* s;
	float* f;
}Test_DtypeHandler;

void test_dtypehandler(){

	srand(time(NULL));

	char *string_test[] = {"asda","223.1gui32", "Dotr","122D1!", "NAN", 
		"NULL", "#ND", "NA", "nan","Nan", "null","true", "false","NaN"};

	int size = sizeof(string_test) / sizeof(string_test[0]);

	for (int i = 0; i < size; i++){
		dtypehandler(string_test[i]);	
		assert(true == true);
	};
		
	for (int it = 0; it < 5; it++){
		int randomint = rand() % 1000 ;
		char str[12];
		sprintf(str, "%d", randomint);
		assert(INT == dtypehandler(str));
	}


	return ; 
};


int main(){
	test_dtypehandler();	

	dtypehandler("1102");


	printf("\n");
	return 0;
}
