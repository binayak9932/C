#include<stdio.h>
#include<math.h>
    float fx(float x)
    {
        return(1/(1+x));
    }
    int main()
    {
        float a,b,n,h,res=0;
        int i;
        printf("Enter the lower limit of the given function:\n");
        scanf("%f",&a);
        printf("Enter the upper limit of the given function:\n");
        scanf("%f",&b);
        printf("Enter no. of steps:\n");
        scanf("%f",&n);
        h=(b-a)/n;
        for(i=0;i<=n;i++)
        {
            if(i==0 || i==n)
            {
                res=res+fx(a+i*h);
            }
            else  res=res+2*fx(a+i*h);
        }
        res=(h*res)/2;
        printf("The result is %.5f\n",res);
        return 0;
    }
