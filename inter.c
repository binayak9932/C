#include <stdio.h>

// Lagrange Interpolation Function
float lagrangeInterpolation(float x[], float y[], int n, float xi) {
    float result = 0;

    for (int i = 0; i < n; i++) {
        float term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    return result;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Given table of x and f(x) values
    float x[n], y[n];
    printf("Enter the table of x and f(x) values:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("f(x)[%d] = ", i);
        scanf("%f", &y[i]);
    }

    // Value to interpolate
    float xi;
    printf("Enter the value of x to interpolate: ");
    scanf("%f", &xi);

    // Find interpolated value
    float interpolatedValue = lagrangeInterpolation(x, y, n, xi);

    printf("Interpolated value of f(%.2f) = %.4f\n", xi, interpolatedValue);

    return 0;
}
