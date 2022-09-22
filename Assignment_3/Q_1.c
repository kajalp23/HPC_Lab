#include<stdio.h>
#include<omp.h>

int sort(int arr[], int n)
{
    int i, j;
    
    for (i = 0; i < n-1; i++){
    	#pragma omp parallel for default(none) shared(arr,i,n) private(j) schedule(static,n/8)
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int sort_des(int arr[], int n)
{
    int i,j;
   
    for (i = 0; i < n; ++i)
    {
    	#pragma omp parallel for default(none) shared(arr,i,n) private(j) schedule(static,n/8)
        for (j = i + 1; j < n; ++j)
        {
            if (arr[i] < arr[j])
            {
                int a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
}
int main()
{   
    //fill the code;
    int n;
    printf("Enter Size: ");
    scanf("%d",&n);
    int arr1[n], arr2[n];
    int i;

    for(i = 0; i < n ; i++)
    {
         arr1[i] = rand()%1000;
    }

    for(i = 0; i < n ; i++)
    {
        arr2[i] = rand()%1000;
    }
	double startTime = omp_get_wtime();
    sort(arr1, n);
    
    sort_des(arr2, n);
    double endTime = omp_get_wtime();
    int sum = 0;
    
    for(i = 0; i < n ; i++)
    {
         printf("%d ",arr1[i]);
    }
	printf("\n");
    for(i = 0; i < n ; i++)
    {
        printf("%d ",arr2[i]);
    }
    
    for(i = 0; i < n ; i++)
    {
        sum = sum + (arr1[i] * arr2[i]);
    }

    printf("\nExecution Time: %f\n",endTime - startTime);
    printf("Sum: %d",sum);
    return 0;
}
