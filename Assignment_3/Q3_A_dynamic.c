#include<omp.h>
#include<stdio.h>
#include<stdlib.h>


int main(){
    
    int a[200];
	int i;
    for(i=0;i<200;i++){
        a[i] = rand()*1000;
    }

    int scalar  = 100;


    double startTime = omp_get_wtime();

    #pragma omp parallel for schedule(dynamic , 1)
    for(i=0;i<16;i++){
        a[i] = a[i] + scalar;
        printf("%d -> %d\n",i,omp_get_thread_num());
    }

    double endTime = omp_get_wtime();

    printf("\nExecution Time : %f" , endTime - startTime);

    return 0;

    
}
