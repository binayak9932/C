#include <stdio.h>
#include "math.h"
#define N 4
int main()
{
  float a[N][N+1], x[N], aerr, maxerr, t, s, err;
  int i, j, itr, maxitr;

  /* first initializing the array */
  for(i=0; i<N; i++)
    x[i]=0;
  printf("Enter the elements of the "
          "argumented matrix rowwise: \n");
  for(i=0; i<N; i++)
    for(j=0; j<N+1; j++)
      scanf("%f", &a[i][j]);
  printf("Enter the allowed error, "
          "maximum iterations\n");
  scanf("%f %d", &aerr, &maxitr);
  printf("Iteration x[1] x[2] x[3]\n");
  for(itr=1; itr<=maxitr; itr++)
  {
    maxerr = 0;
    for (i = 0; i < N; i++) {
      s = 0;
      for(j=0; j< N; j++)
        if(j!=i)
          s += a[i][j]*x[j];
      t = (a[i][N]-s)/a[i][i];
      err = fabs(x[i]-t);
      if (err > maxerr)
        maxerr = err;
      x[i]=t;
    }
    printf ("%5d", itr);
    for (i=0; i<N; i++)
      printf("%9.4f", x[i]);
    printf("\n");

    if (maxerr<aerr)
      {
        printf("Converges in %3d "
              "iterations\n", itr);
        for(i=0; i<N; i++)
          printf("x[%3d]=%7.4f\n",i+1,x[i]);
        return 0;
      }
  }
  printf("Solution does not converge, "
        "iterations not sufficient\n");
  return 1;
}
