#include <mpi.h>
#include <stdio.h>
int main( int argc, char *argv[] )
{
    MPI_Init( &argc, &argv );
    int my_rank;
    MPI_Status status;
    MPI_Comm_rank (MPI_COMM_WORLD, &my_rank);

    double d=100.0;int tag=1;
    if (my_rank == 0) {
        MPI_Ssend (&d, 1, MPI_DOUBLE, 1, tag, MPI_COMM_WORLD);
        MPI_Recv (&d, 1, MPI_DOUBLE, 1, tag, MPI_COMM_WORLD, &status);
        
    } else {
        MPI_Ssend (&d, 1, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);
        MPI_Recv (&d, 1, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD, &status);
    }
    MPI_Finalize();
    return 0;
}