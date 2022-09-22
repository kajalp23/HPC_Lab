#include<stdio.h>
#include<omp.h>


int fib(int n){
    int i;
    int f[n+2];
    f[0] = 1;
    f[1] = 1;

    for (i = 2; i <= n; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];

}



int main ()
{
    int n = 100000; 

    double startTime = omp_get_wtime();
    printf("Answer: %d\n", fib(n)); 
    double endTime = omp_get_wtime();

    printf("Execution Time: %f\n" , endTime - startTime);


    return 0;

}
