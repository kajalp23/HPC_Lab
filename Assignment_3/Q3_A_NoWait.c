#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n = 5, i ,j=99;
    int arr1[n], answer[n],answer2[n];
    for(i = 0; i < n; i++){
        arr1[i] = rand()%100;
    } 
	
	int k=999;  
	clock_t begin = clock(); 
    #pragma omp parallel 
    {
	    #pragma omp for nowait
	    for(i = 0; i < n; i++)
	    {
	        answer[i] = arr1[i] + j;
	        printf("%d by thread %d\n",answer[i],omp_get_thread_num());
	    }
	    
	    #pragma omp for nowait
	    for(i = 0; i < n; i++)
	    {
	        answer2[i] = arr1[i] + k;
	        printf("%d by thread %d\n",answer2[i],omp_get_thread_num());
	    }
	    
    }
    clock_t end = clock();
    double time_execution = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nTime for execution: %lf", time_execution);
    return 0;
}
