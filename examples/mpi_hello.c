//==================================
// MPI version of Hello World...
//
// Compile (Login Node or Pre/Post Environment)
// $ mpifccpx -Nclang -Kfast -o hello hello.c 
//
// Run (Compute Node)
// $ mpiexec -np NUM_NODES ./hello
//==================================

#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int my_rank;   // My MPI process number (Rank)
    int num_procs; // Total number MPI processes     

    // Initialize MPI environment
    MPI_Init(NULL, NULL);
  
    // Get the total numberof MPI processes
    MPI_Comm_size( MPI_COMM_WORLD, &num_procs );
    // Get my rank number (Start from ZERO)
    MPI_Comm_rank( MPI_COMM_WORLD, &my_rank );

    printf("Hello World... from %d of %d \n", my_rank, num_procs);

    // Finalize MPI environment
    MPI_Finalize();

    return EXIT_SUCCESS;
}

