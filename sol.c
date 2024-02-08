#include <stdio.h>
#include <stdlib.h>

void printMatrix(float **a, int n, char *title) {
    printf("%s:\n", title);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) { // Note: <= n to include augmented column
            printf("%9.3f ", a[i][j]);
        }
        printf("\n");
    }
}

void gaussianElimination(float **a, int n) {
    int i, j, k;
    float factor;
    for (k = 0; k < n; k++) {
        for (i = k + 1; i < n; i++) {
            factor = a[i][k] / a[k][k];
            for (j = k; j <= n; j++) {
                a[i][j] -= factor * a[k][j];
            }
        }
        printMatrix(a, n, "Upper Triangular Matrix Step");
    }
}

void backSubstitution(float **a, float *x, int n) {
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }
}

int main() {
    int n, i, j;
    printf("Enter number of variables: ");
    scanf("%d", &n);

    float **a = (float **)malloc(n * sizeof(float *));
    for (i = 0; i < n; i++) {
        a[i] = (float *)malloc((n + 1) * sizeof(float)); // +1 for augmented column
    }
    float *x = (float *)malloc(n * sizeof(float));

    printf("Enter coefficients of the system followed by the constants:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) { // <= n to include the augmented column
            scanf("%f", &a[i][j]);
        }
    }

    printMatrix(a, n, "Augmented Matrix");

    gaussianElimination(a, n);
    printMatrix(a, n, "Upper Triangular Matrix");

    backSubstitution(a, x, n);

    printf("Solution of the system:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %f\n", i + 1, x[i]);
    }

    // Free allocated memory
    for (i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    free(x);

    return 0;
}
