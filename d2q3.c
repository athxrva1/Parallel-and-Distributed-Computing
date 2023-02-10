#include <stdio.h> 
#include <omp.h> 
#include <math.h>


int main()
{
    int count = 10;
    double A[count];
    int i;

    for(i = 0;i<count;i++)
    {
        A[i] = i;
    }
    
double avg, sum = 0.0;

#pragma omp parallel for reduction(+ : sum)
for ( i = 0; i < count; i++)
{
    sum += A[i];
}
avg = sum/count;

printf("Thre avg computed by parallel programming with reduction is : %d \n", avg);

    return 0;
}

