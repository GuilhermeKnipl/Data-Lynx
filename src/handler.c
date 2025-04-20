#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/types.h"
#include "../include/handler.h"

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

int int_handler(char* value) {
	char* endpointer;
	int parsed = (int)strtol(value , &endpointer, 10);
	return parsed;
}
float float_handler(char* value) {
	char* endpointer;
	float parsed = strtof(value, &endpointer);
	return parsed;
}


//Identifying Dtype of cols
void identify_dtype();

// Allocating Space according to Datatype;
void allocate_vector(int len, DataFrame * df, int idx){  
    if (!df->cols[idx].vector) {
        df->cols[idx].vector = malloc(sizeof(DVector));
    }

    printf("\n%d", len);
	switch(*df->cols[idx].dtype){
        case INT:
			df->cols[idx].vector->i = (int*)malloc(len * sizeof(int));
			break;
		case FLOAT:
			df->cols[idx].vector->f = (float*)malloc(len * sizeof(float));
			break;
		case CHAR:
			df->cols[idx].vector->s = (char **)malloc(len * sizeof(char*));
			break;
		default:
            printf("Invalid dtype on allocation.\n");
            exit(EXIT_FAILURE);
	}
}

int csv_len(FILE * file){


    int lines = 0;
    int ch; 
		
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
    }
    printf("Row count at csv_len: %d \n", lines);
    return lines;
}
