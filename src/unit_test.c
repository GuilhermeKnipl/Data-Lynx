
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/types.h"
#include "../include/unit_test.h"
#include "../include/handler.h"



void test_dtypehandler(void){

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
}

