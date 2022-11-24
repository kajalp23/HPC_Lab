#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// size of array
#define n 10

int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// Temporary array for slave process
int a2[1000];

int main(int argc, char *argv[])
{

    int pid, np=2,elements_per_process,n_elements_recieved;
    
    MPI_Status status;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    // MPI_Comm_size(MPI_COMM_WORLD, &np);

    if (pid == 0)
    {
        int index, i;
        elements_per_process = n / np;

        MPI_Send(&elements_per_process, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Send(&a[elements_per_process], n-elements_per_process, MPI_INT, 1, 0, MPI_COMM_WORLD);
        // master process add its own sub array
        int sum = 0;
        for (i = 0; i < elements_per_process; i++)
            sum += a[i];

        int tmp;
        
        MPI_Recv(&tmp, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
        int sender = status.MPI_SOURCE;

        sum += tmp;
        printf("Sum of array is: %d\n", sum);
    }
    else
    {
        MPI_Recv(&n_elements_recieved, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

        MPI_Recv(&a2, n_elements_recieved, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);

        int partial_sum = 0;
        for (int i = 0; i < n_elements_recieved; i++)
            partial_sum += a2[i];

        MPI_Send(&partial_sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();

    return 0;
}


//https://gist.github.com/Rubix982/e0f611c449b20c2647822c4f57f21357