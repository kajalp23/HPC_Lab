#include<stdio.h>
#include<omp.h>


int fib(int n){
    int i;
    int f[n+2];

    #pragma omp parallel for schedule(static, 8)
    for(i=0;i<n+2;i++){
        f[i] = -1;
    }

    f[0] = 1;
    f[1] = 1;

    #pragma omp parallel for private(i) shared(f) schedule(static, 8)
    for(i=2;i<=n;i++)
    {
        while(f[i-1] == -1 || f[i-2] == -1);

        #pragma omp critical
        {
            f[i] = f[i-1] + f[i-2];
        }

    }
    
    return f[n];

}



int main ()
{
    int n = 100000; 

    double startTime = omp_get_wtime();

    #pragma omp parallel shared(n)
    {   
        #pragma omp single
        printf("Answer: %d\n", fib(n)); 
    }
    
    double endTime = omp_get_wtime();

    printf("Execution Time: %f\n" , endTime - startTime);


    return 0;

}
