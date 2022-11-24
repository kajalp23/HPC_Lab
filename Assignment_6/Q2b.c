#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{

    int numtasks, rank, size;
    
    MPI_Status status;

    MPI_Init (&argc, &argv);
    MPI_Comm_size (MPI_COMM_WORLD, &size);
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);

    int send_junk = rank;
    int rec_junk;

    if(rank==0) {
        MPI_Send(&send_junk, 1, MPI_INT, 1, 0, MPI_COMM_WORLD); 
        MPI_Recv(&rec_junk, 1, MPI_INT, size-1, 0, MPI_COMM_WORLD, &status); 
    }
    else if( rank == size-1) { 
        MPI_Recv(&rec_junk, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, &status); 
        MPI_Send(&send_junk, 1, MPI_INT, 0, 0, MPI_COMM_WORLD); 
    }
    else {
        MPI_Recv(&rec_junk, 1, MPI_INT, rank-1, 0, MPI_COMM_WORLD, &status); 
        MPI_Send(&send_junk, 1, MPI_INT, rank+1, 0, MPI_COMM_WORLD); 
    }
    printf("\nProcess %d send %d\n and recieved %d\n", rank, send_junk, rec_junk ); 
    MPI_Finalize ();
    return 0;
}