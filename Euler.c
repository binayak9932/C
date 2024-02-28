#include<stdio.h>
#include<math.h>
    float fx(float x, float y)
    {
        return (y-x)/(y+x);
    }
    int main()
    {
        float x0,y0,y,h,xn,n;
        int c=0;
        printf("Enter the value of x0:\n");
        scanf("%f",&x0);
        printf("Enter the value of y0:\n");
        scanf("%f",&y0);
        printf("Enter the value of h:\n");
        scanf("%f",&h);
        printf("Enter the value x at which y need to be evaluated:\n");
        scanf("%f",&xn);
        n=(xn-x0)/h;
        while(c<n)
        {
            y=y0+(h*fx(x0,y0));
            x0=x0+h;
            y0=y;
            c++;
        }
        printf("The value of y at %.3f = %.4f.",x0,y0);
        return 0;
    }
