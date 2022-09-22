#include<bits/stdc++.h>
#include<omp.h>

int main()
{
	
	clock_t start, finish;
    start = clock();
	
	int i;
	
	for(i=1;i <= 4;i++)
		printf("Hello World\n");
	
	finish = clock();
    double tt = (double)(finish-start)/CLOCKS_PER_SEC;
    printf("Exec time is: %lf\n",tt);
	
	return 0;
}
