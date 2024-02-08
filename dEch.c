#include <stdio.h>
#include <stdlib.h>

void printMatrix(float **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void toEchelonForm(float **matrix, int n) {
    for (int i = 0; i < n; i++) {
        // Pivot element
        if (matrix[i][i] == 0) {
            // Swap with a non-zero row
            for (int k = i + 1; k < n; k++) {
                if (matrix[k][i] != 0) {
                    // Swap rows
                    for (int j = 0; j <= n; j++) {
                        float temp = matrix[i][j];
                        matrix[i][j] = matrix[k][j];
                        matrix[k][j] = temp;
                    }
                    break;
                }
            }
        }

        // Normalize the pivot row
        float pivot = matrix[i][i];
        if (pivot != 0) { // Avoid division by zero
            for (int j = i; j <= n; j++) {
                matrix[i][j] /= pivot;
            }
        }

        // Eliminate below
        for (int k = i + 1; k < n; k++) {
            float factor = matrix[k][i];
            for (int j = i; j <= n; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    float **matrix = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (float *)malloc((n + 1) * sizeof(float)); // +1 for augmented column
    }

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

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
