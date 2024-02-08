#include <stdio.h>

void printMatrix(float matrix[10][11], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void toEchelonForm(float matrix[10][11], int n) {
    for (int i = 0; i < n; i++) {
        // Find pivot
        int pivot = i;
        while (pivot < n && matrix[pivot][i] == 0) {
            pivot++;
        }
        if (pivot == n) {
            continue; // No nonzero pivot in this column, move to next column
        }

        // Swap current row with pivot row
        if (pivot != i) {
            for (int j = 0; j <= n; j++) {
                float temp = matrix[i][j];
                matrix[i][j] = matrix[pivot][j];
                matrix[pivot][j] = temp;
            }
        }

        // Normalize the pivot row
        float pivotValue = matrix[i][i];
        for (int j = 0; j <= n; j++) {
            matrix[i][j] /= pivotValue;
        }

        // Eliminate below
        for (int k = i + 1; k < n; k++) {
            float factor = matrix[k][i];
            for (int j = 0; j <= n; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    float matrix[10][11]; // 10 unknowns max, +1 for augmented column

    printf("Enter the coefficients of each equation, row by row, including the right-hand side:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("Augmented Matrix:\n");
    printMatrix(matrix, n);

    toEchelonForm(matrix, n);

    printf("Matrix in Echelon Form:\n");
    printMatrix(matrix, n);

    return 0;
}
