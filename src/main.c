#include <assert.h>
//#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/types.h"
#include "../include/unit_test.h"
#include "../include/handler.h"


void check_fhealth(FILE *file){
	if (file == NULL){
		printf("EMPTY FILE");
	}else{
		printf("\nFile Readed\n");
	}
}

void file_printer(){

	FILE *file = fopen(HOUSING_CSV, "r");

	check_fhealth(file);

	char line[256];

	int row  = 0;
	int col = 0;
	int columns_iter = 0;
	while (fgets(line, sizeof(line), file)) {
		row++ ; // Line Index
		col = 0;
		columns_iter++ ;
		printf("--\nNew line--");
		char* tok = strtok(line,",");
		while (tok != NULL){
			//printf("\nrow: %d col: %d value: %s", row , col , tok);
			tok = strtok(NULL, ",");
			col++;
		}
		if(row == 3){break;}
	}
}

typedef struct Datetime{
	int day;
	int month;
	int year;
	int hour;
	int minutes;
}Datetime;

int collen_csv(FILE * file){

	char lsize[256];
	int row = 0, colidx = 0;

	while (fgets(lsize, sizeof(lsize), file)) {
			char * tok = strtok(lsize,",");
		while (tok != NULL) {
			printf("\nColumn index: %d Value: %s\n", colidx,tok);
			tok = strtok(NULL,",");
			colidx++;
		}
		row++;
		if(row == 1){break;};

	    };
    int colsize = colidx + 1;
	return colsize;
}

void ias(){

	FILE *file = fopen(HOUSING_CSV, "r");

	if (!file) {
		perror("Failed to open file");
    	}

	int col_len = collen_csv(file);
	int rows_len = csv_len(file);

	DataFrame * df = (DataFrame*)malloc(sizeof(DataFrame));
		
	
	df->cols = malloc(sizeof(Col)*col_len);
}	

int main(){


//	test_dtypehandler();		
	
	DataFrame df;
	df.cols = (Col*)malloc(sizeof(int)*12);

	char *val = "hello";	
	Col *b = (Col*)malloc(sizeof(Col));
	
	b->dtype = dtypehandler(val);
	
		
        allocate_vector(100, b);	
	b->idx = 0;
	b->vector.s[0] = strdup("hello");
	b->vector.s[1] = strdup("hello2");

	printf("\nIndex is: %d", b->idx);
	printf("\nVal %s", b->vector.s[0]);
	printf("\nVal %s", b->vector.s[1]);

	file_printer();
	printf("\n");
	return 0;
}
