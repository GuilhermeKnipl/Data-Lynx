#include <assert.h>
//#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/types.h"
#include "../include/unit_test.h"
#include "../include/handler.h"

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

typedef struct Datetime{
	int day;
	int month;
	int year;
	int hour;
	int minutes;
}Datetime;




int main(){
	test_dtypehandler();	

	dtypehandler("1102");


	printf("\n");
	return 0;
}
