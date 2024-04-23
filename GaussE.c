#include <stdio.h>

#define MAX_VARS 10 // Maximum number of variables

void printMatrix(float a[MAX_VARS][MAX_VARS+1], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%.3f ", a[i][j]);
        }
        printf("\n");
    }
}

void gaussianElimination(float a[MAX_VARS][MAX_VARS+1], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = k+1; i < n; i++) {
            float factor = a[i][k] / a[k][k];
            for (int j = k; j <= n; j++) {
                a[i][j] -= factor * a[k][j];
            }
        }
    }
}

void backSubstitution(float a[MAX_VARS][MAX_VARS+1], float x[MAX_VARS], int n) {
    for (int i = n-1; i >= 0; i--) {
        x[i] = a[i][n];
        for (int j = i+1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
}

int main() {
    float a[MAX_VARS][MAX_VARS+1], x[MAX_VARS];
    int n;

    printf("Enter number of variables (max %d): ", MAX_VARS);
    scanf("%d", &n);
    if (n > MAX_VARS || n < 1) {
        printf("Invalid number of variables. Program supports up to %d variables.\n", MAX_VARS);
        return 1;
    }

    printf("Enter coefficients of the system followed by the constants:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }
     printf("Augmented Matrix:\n");
    printMatrix(a, n);
    gaussianElimination(a, n);
    printf("Upper Triangular Matrix:\n");
    printMatrix(a, n);

    backSubstitution(a, x, n);

    printf("Solution of the system:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %f\n", i + 1, x[i]);
    }

    return 0;
}
