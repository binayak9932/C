#include<stdio.h>
#include<math.h>

float fx(float x, float y)
{
    return (y-x)/(y+x);
}

int main()
{
    float x0, y0, y, h, xn, n, tolerance;
    int c = 0;
    
    printf("Enter the value of x0:\n");
    scanf("%f", &x0);
    
    printf("Enter the value of y0:\n");
    scanf("%f", &y0);
    
    printf("Enter the value of h:\n");
    scanf("%f", &h);
    
    printf("Enter the value of tolerance:\n");
    scanf("%f", &tolerance);
    
    printf("Enter the value x at which y needs to be evaluated:\n");
    scanf("%f", &xn);
    
    n = (xn - x0) / h;
    
    while(c < n)
    {
        float prev_y = y0;
        y = y0 + (h * fx(x0, y0));
        x0 = x0 + h;
        y0 = y;
        c++;
        
        // Check if the change in y is within tolerance
        if (fabs(y - prev_y) <= tolerance) {
            printf("The value of y at %.3f = %.4f (within tolerance).\n", x0, y0);
            return 0;
        }
    }
    
    printf("The value of y at %.3f = %.4f (tolerance not met).\n", x0, y0);
    return 0;
}
