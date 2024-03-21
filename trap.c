#include<stdio.h>
#include<math.h>
void main()
    {
        int i,n,b,a;
        printf("Enter the number of interpolating points\n");
        scanf("%d",&n);
        printf("Enter the upper & lower limit of the given function:\n");
        scanf("%d",&b);
        scanf("%d",&a);
        float X[n],h,res=0.0,sum=0.0;
        X[n]=b,X[0]=a;
        h=(float)(b-a)/n;
        printf("Value of  h: %0.4f\n",h);
        for(i=1;i<n;i++)
        {
           X[i]=X[0]+(i*h);
           sum+=(1/X[i]);
        }
        res+=(h/2)*(((1/X[0])+(1/X[n]))+(2*sum));
        printf("The result of interpolation: %f\n",res);

    }   





