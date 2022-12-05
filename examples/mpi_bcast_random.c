//==================================
// MPI_Bcast of random number generated at rank 0
//
// Compile (Login Node or Pre/Post Environment)
// $ mpifccpx -Nclang -Kfast -o mpi_bcast_random mpi_bcast_random.c 
//
// Run (Compute Node)
// $ mpiexec -np NUM_NODES ./mpi_bcast_random
//==================================

#include "mpi.h" 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEMENTS 5 // Number of data elements

int main() 
{ 
    int my_rank;   // My MPI process number (Rank)
    int num_procs; // Total number MPI processes     
 
    int i; // counter
    float data[NUM_ELEMENTS]; 

    // Initialize MPI environment
    MPI_Init(NULL, NULL);
  
    // Get the total numberof MPI processes
    MPI_Comm_size( MPI_COMM_WORLD, &num_procs );
    // Get my rank number (Start from ZERO)
    MPI_Comm_rank( MPI_COMM_WORLD, &my_rank );

    // Rank 0: Create Data with NUM_ELEMENTS
    if ( my_rank == 0)
    {
	for ( i = 0; i < NUM_ELEMENTS; i++)
        {
            data[i] = (float)rand() / RAND_MAX;
        }

        printf("Rank %d: \n", my_rank);
        printf("DATA = ");
	for ( i = 0; i < NUM_ELEMENTS; i++)
        {
            printf("%f ", data[i]);
        }
        printf("\n\n");
    }

    // Broadcast data values from Rank 0 to other Ranks
    MPI_Bcast( &data[0], NUM_ELEMENTS, MPI_FLOAT, 0, MPI_COMM_WORLD);
    
    // Print Broadcasted data values from Rank 0
    printf("Rank %d: BCAST_DATA = ", my_rank);
    for ( i = 0; i < NUM_ELEMENTS; i++)
    {
       printf("%f ", data[i]);
    }
   
    // Finalize MPI environment
    MPI_Finalize();

    return EXIT_SUCCESS;
} 
