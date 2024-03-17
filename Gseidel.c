#include <stdio.h>
#include <math.h>

#define MAX_VARS 10
#define MAX_ITER 1000

void gauss_seidel(double A[MAX_VARS][MAX_VARS], double B[MAX_VARS], double X[MAX_VARS], int n, double tol) {
    int i, j, k;
    double newX[MAX_VARS], error, sum;

    for (k = 0; k < MAX_ITER; k++) {
        error = 0.0;
        for (i = 0; i < n; i++) {
            sum = 0.0;
            for (j = 0; j < n; j++) {
                if (j != i) {
                    sum += A[i][j] * X[j];
                }
            }
            newX[i] = (B[i] - sum) / A[i][i];
            error += fabs(newX[i] - X[i]);
            X[i] = newX[i];
        }
        if (error < tol) {
            printf("Converged after %d iterations\n", k + 1);
            break;
        }
    }

    if (k == MAX_ITER) {
        printf("Did not converge after %d iterations\n", MAX_ITER);
    }
}

int main() {
    int n, i, j;
    double A[MAX_VARS][MAX_VARS], B[MAX_VARS], X[MAX_VARS], tol;

    printf("Enter the number of variables (maximum %d): ", MAX_VARS);
    scanf("%d", &n);

    printf("Enter the coefficients of the equations:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter the constants on the right-hand side:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &B[i]);
    }

    printf("Enter the tolerance limit: ");
    scanf("%lf", &tol);

    for (i = 0; i < n; i++) {
        X[i] = 0.0;
    }

    gauss_seidel(A, B, X, n, tol);

    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("X[%d] = %lf\n", i, X[i]);
    }

    return 0;
}
