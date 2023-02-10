#include <stdio.h> 
#include <omp.h> 
#include <math.h>


int main()
{
    int arr[10],i, count = 10;

    #pragma omp parallel for
    for ( i = 0; i < count; i++)
    {
        arr[i] = 2 * i;
    }

    for ( i = 0; i < count; i++)
    {
       printf("%d \n", arr[i]);
    }
    
    
    return 0;
}

