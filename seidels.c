#include <stdio.h>
#include <math.h>

void gauss_seidel(int n, double a[n][n+1], double x[n], double tol) {
    int i, j;
    double sum, error, xnew[n];

    printf("Initial guess values:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %lf\n", i, x[i]);
    }

    int iter = 0;
    while (1) {
        error = 0.0;
        for (i = 0; i < n; i++) {
            if (a[i][i] == 0.0) {
                printf("Error: Division by zero encountered.\n");
                return;
            }
            sum = a[i][n];
            for (j = 0; j < n; j++) {
                if (j != i) {
                    sum -= a[i][j] * x[j];
                }
            }
            xnew[i] = sum / a[i][i];
            error += fabs(xnew[i] - x[i]);
            x[i] = xnew[i];
        }

        iter++;

        if (error <= tol) {
            printf("\nSolution found after %d iterations:\n", iter);
            for (i = 0; i < n; i++) {
                printf("x%d = %lf\n", i, x[i]);
            }
            return;
        }
    }
}

int main() {
    int n, i, j;
    double tol;
    double a[20][21], x[20];

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    printf("Enter the coefficients of the equations:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    printf("Enter the initial guess values:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = ", i);
        scanf("%lf", &x[i]);
    }

    printf("Enter the tolerance limit: ");
    scanf("%lf", &tol);

    gauss_seidel(n, a, x, tol);

    return 0;
}