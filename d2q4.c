#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define VECLEN 10

float a[VECLEN], b[VECLEN], sum;

void dotprod ()
{
    int i,tid;

    tid = omp_get_thread_num();
#pragma omp for reduction(+:sum)
    for (i=0; i < VECLEN; i++)
    {
        sum = sum + (a[i]*b[i]);
        printf("  tid= %d i=%d\n",tid,i);
    }
}


int main (int argc, char *argv[]) {
  int i, procs;

  for (i=0; i < VECLEN; i++)
      a[i] = b[i] = 1.0 * i;
  sum = 0.0;

/*
   procs = omp_get_num_procs();
   omp_set_num_threads(procs);
*/

#pragma omp parallel
   dotprod();

   printf("Sum = %f\n",sum);

   return(0);
}