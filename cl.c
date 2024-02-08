#include <stdio.h>

#define ROWS 3  
#define COLS 4

void printMatrix(float mat[][COLS], int rows, int cols);
void gaussJordan(float mat[][COLS], int rows, int cols);

int main() {
  float mat[ROWS][COLS] = {{2, 3, -1, 9}, 
                           {3, 2, 0, 10},
                           {1, 3, 1, 8}};  

  printf("Original Augmented Matrix:\n");
  printMatrix(mat, ROWS, COLS);
  
  gaussJordan(mat, ROWS, COLS);

  printf("\nMatrix in Row Reduced Echelon form:\n");
  printMatrix(mat, ROWS, COLS);

  return 0;  
}

void printMatrix(float mat[][COLS], int rows, int cols) {

  int i, j;
  for(i=0; i<rows; i++) {
    for(j=0; j<cols; j++) {
      printf("%.2f ", mat[i][j]); 
    }
    printf("\n");
  }
}

void gaussJordan(float mat[][COLS], int rows, int cols) {

  int i, j, k;
  float temp;

  // Convert matrix into echelon form  
  for(i=0; i<rows; i++) {

    int pivot = i;
    for(j=i+1; j<rows; j++) {
     if(mat[j][i] > mat[pivot][i]) 
        pivot = j;
    }

    if(pivot != i) {
      for(j=0; j<cols; j++) {
        temp = mat[i][j];
        mat[i][j] = mat[pivot][j];
        mat[pivot][j] = temp;
      }
    }

    for(j=0; j<rows; j++) {
      if(j != i) {
        float factor = mat[j][i]/mat[i][i];
        for(k=0; k<cols; k++) {    
          mat[j][k] -= factor * mat[i][k];
        }
      }
    }
  }

  // Convert echelon form to reduced echelon form
  for(i=rows-1; i>=0; i--) {
    for(j=i-1; j>=0; j--) {
      float factor = mat[j][i]/mat[i][i];
      for(k=0; k<cols; k++) {  
        mat[j][k] -= factor * mat[i][k];
      } 
    }
  }
}