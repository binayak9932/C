#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
    float factorial(float k)
    {
        if(k==0.0)
        {
            return 1.0;
        }
        else return k*factorial(k-1);
    }
    float result(float p, int k)
    {
        int m;
        float pro=1;
        if(k==0)
        {
            return 1;
        }
        else
        for(m=0;m<k;m++)
        {
            pro=pro*(p-m);
        }
        return pro;
    }
    int main()
     {
        float arr[50][50];
        int i,j,k,n;
        float p,h,x,res=0.0;
        printf("Enter the point at which corresponding value to be obtained:\n");
        scanf("%f",&x);
        printf("Enter the no. of points:\n");
        scanf("%d",&n);
        printf("Enter the points of table:\n");
        for(i=0;i<n;i++)
        {
            scanf("%f",&arr[i][0]);
        }
        printf("Enter the corresponding values of points:\n");
        for(i=0;i<n;i++)
        {
            scanf("%f",&arr[i][1]);
        }
        for(j=2;j<n+1;j++)
        {
            for(i=0;i<n-j+1;i++)
            {
                arr[i][j]=arr[i+1][j-1]-arr[i][j-1];
            }
        }
        printf("Newton Forward Difference Table:\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<n+1;j++)
            {
                if(arr[i][j]==0.00)
                    break;
                printf("%.5f   ",arr[i][j]);
            }
            printf("\n");
        }
        h=arr[1][0]-arr[0][0];
        printf("%.2f\n",h);
        p=(x-arr[0][0])/h;
        printf("%.2f\n",p);
        for(k=0;k<n;k++)
        {
            res=(float) res+(result(p,k)/factorial(k))*arr[0][k+1];
        }
        printf("The value of point %.2f is %.5f.",x,res);
        return 0;
    }
