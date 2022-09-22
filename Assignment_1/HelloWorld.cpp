#include <stdio.h>
#include <omp.h>
#include<time.h>


int main() {
	clock_t start, finish;
    start = clock();
    int numt;
    #pragma omp parallel
    {
        int tnum;
        tnum=omp_get_thread_num();
        numt=omp_get_num_threads();
        if(tnum==0)
            printf("No of threads : %d \n",numt);
        printf("Hello world from thread %d \n",tnum);

    }
    finish = clock();
    double tt = (double)(finish-start)/CLOCKS_PER_SEC;
    printf("Exec time is: %lf",tt);
    return 0;
}

