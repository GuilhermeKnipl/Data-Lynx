#include <assert.h>
// #include <time.h>
#include "../include/handler.h"
#include "../include/types.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_fhealth(FILE *file) {
  if (file == NULL) {
    printf("EMPTY FILE");
  } else {
    printf("\nFile Readed\n");
  }
}

void file_printer() {

  FILE *file = fopen(HOUSING_CSV, "r");

  check_fhealth(file);

  char line[256];

  int row = 0;
  int col = 0;
  int columns_iter = 0;
  while (fgets(line, sizeof(line), file)) {
    row++; // Line Index
    col = 0;
    columns_iter++;
    printf("--\nNew line--");
    char *tok = strtok(line, ",");
    while (tok != NULL) {
      printf("\nrow: %d col: %d value: %s", row, col, tok);
      tok = strtok(NULL, ",");
      col++;
    }
    if (row == 3) {
      break;
    }
  }
}

int collen_csv(FILE *file) {

  char lsize[256];
  int row = 0, colidx = 0;

  while (fgets(lsize, sizeof(lsize), file)) {
    char *tok = strtok(lsize, ",");
    while (tok != NULL) {
      tok = strtok(NULL, ",");
      colidx++;
    }
    row++;
    if (row == 1) {
      break;
    };
  };
  int colsize = colidx;

  printf("\nColumn size at collen_csv: %d\n", colsize);

  return colsize;
}
void llocate_vector(int len, DataFrame *df, int idx) {
  if (!df->cols[idx].vector) {
    df->cols[idx].vector = malloc(sizeof(DVector));
  }

  switch (*df->cols[idx].dtype) {
  case INT:
    printf("\nINT");
    df->cols[idx].vector->i = (int *)malloc(len * sizeof(int));
    break;
  case FLOAT:
    df->cols[idx].vector->f = (float *)malloc(len * sizeof(float));
    printf("\nFLOAT");
    break;
  case CHAR:
    df->cols[idx].vector->s = (char **)malloc(len * sizeof(char *));
    printf("\nCHAR");
    break;
  default:
    printf("Invalid dtype on allocation.\n");
    exit(EXIT_FAILURE);
  }
}

// Assign and Allocate space for the Dtype, Insert the Column name
void insert_on(DataFrame *df, int idx, int row, char *value) {
  printf("%i", *df->cols->dtype);
  switch (*df->cols[idx].dtype) {
  case INT:
    df->cols[idx].vector->i[row] = int_handler(value);
    break;
  case FLOAT:
    df->cols[idx].vector->f[row] = float_handler(value);
    break;
  case CHAR:
    df->cols[idx].vector->s[row] = strdup(value);
    break;
  default:
    EXIT_FAILURE;
    break;
  }
};

DataFrame *dataframe_builder(const char * csv_path) {

  DataFrame *dft = (DataFrame *)malloc(sizeof(DataFrame));

  FILE *file = fopen(csv_path, "r");

  int col_len = collen_csv(file);
  rewind(file);
  int rows_len = csv_len(file);
  rewind(file);

  dft->cols = (Col *)malloc(sizeof(Col) * (col_len));
  dft->rows_len = (int *)malloc(sizeof(int));
  dft->col_len = (int*)malloc(sizeof(int));
  //*dft->rows_len = rows_len;

  for (int i = 0; i <= col_len; i++) {
    dft->cols[i].dtype = (Dtype *)malloc(sizeof(Dtype));
    dft->cols[i].vector = (DVector *)malloc(sizeof(DVector));
  }

  char line[256];

  int rowc = 0, colidx = 0;
    while (fgets(line, sizeof(line), file)) {
        if (rowc == 0) {
            printf("COLUMNS");
            char *tok = strtok(line, ",");
            while (tok != NULL) {
                dft->cols[colidx].vector = (DVector *)malloc(sizeof(DVector));
                dft->cols[colidx].column_name = strdup(tok);
                tok = strtok(NULL, ",");
                colidx++;
      }
        }
          if (rowc == 1) {
              colidx = 0;
              char *tok = strtok(line, ",");
              while (tok != NULL) {
                *dft->cols[colidx].dtype = dtypehandler(tok);
                tok = strtok(NULL, ",");
                colidx++;
              }
          }
          rowc++;
          if (rowc== 2) {
            break;
          }        
  }
    

  *dft->rows_len = rows_len;
  *dft->col_len = col_len;

  for (int idx = 0; idx < col_len; idx++) {
    llocate_vector(rows_len, dft, idx);
  }

  int row = -1;
  int col = 0;
  int columns_iter = 0;
  while (fgets(line, sizeof(line), file)) {
    row++; // Line Index
    col = 0;
    columns_iter++;
    char *tok = strtok(line, ",");
    while (tok != NULL) {
        if(row != 0){
          insert_on(dft, col, row, tok);
          printf("\nrow: %d col: %d value: %s", row, col, tok);}
      tok = strtok(NULL, ",");
      col++;
    }
  } 


    return dft;
}


int main() {
    
   DataFrame * dft = dataframe_builder(HOUSING_CSV);
        
    printf("%s", dft->cols[12].column_name);
    printf("%s", dft->cols[12].vector->s[543]);
    printf("%d", *dft->rows_len);
    printf("%d", *dft->col_len);


  // column_constructor(file, dft);

  //	test_dtypehandler();
  // DataFrame * df = dataframe_builder();

  // printf("%f",df->cols[0].vector->f[1]);

  // file_printer();
  printf("\n");
  return 0;
}
