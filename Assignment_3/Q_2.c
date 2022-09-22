#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main(){
    

    int row , col;


    printf("Enter No. of Rows : ");
    scanf("%d",&row);

    printf("Enter No of Columns : ") ;
    scanf("%d",&col);

    long long a[row][col] , b[row][col] ,c[row][col];
	int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            a[i][j] = rand()*1000;
            b[i][j] = rand()*1000;
        }
    }

    

    double startTime = omp_get_wtime();

	//int i,j;
    #pragma omp parallel for shared(a,b,c,row,col) schedule(static,row/8) collapse(2)
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
        	
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    double endTime = omp_get_wtime();

    printf("execution time: %f",endTime - startTime);
}





