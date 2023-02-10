#include <stdio.h> 
#include <omp.h> 
#include <math.h>


int main()
{
    int arr1[10], arr2[10],i, count = 10;

    #pragma omp sections
    {
        #pragma omp section
            #pragma omp parallel for
                for ( i = 0; i < count; i++)
                {
                    arr1[i] = 2 * i;
                }
        
                for ( i = 0; i < count; i++)
                {
                   printf("The element is from section 1: %d\n", arr1[i]);
                }
                
        #pragma omp section
            #pragma omp parallel for
            for ( i = 0; i < count; i++)
            {
                arr2[i] = 5 * i;
            }

            for ( i = 0; i < count; i++)
                {
                    printf("The element is from section 2: %d\n", arr2[i]);
                }
      
    }
    
    
    return 0;
}

