//==================================
// MPI_AllReduce(SUM) of random number generated at each of the ranks
//
// Compile (Login Node or Pre/Post Environment)
// $ mpifccpx -Nclang -Kfast -o mpi_allreduce_random mpi_allreduce_random.c 
//
// Run (Compute Node)
// $ mpiexec -n NUM_NODES ./mpi_allreduce_random
//==================================

#include "mpi.h" 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 5 // Number of data elements

int main() 
{ 
    int my_rank;   // My MPI process number (Rank)
    int num_procs; // Total number MPI processes     
 
    int i; // counter
    float data[NUM_ELEMENTS]; 
    float result[NUM_ELEMENTS];

    // Initialize MPI environment
    MPI_Init(NULL, NULL);
  
    // Get the total numberof MPI processes
    MPI_Comm_size( MPI_COMM_WORLD, &num_procs );
    // Get my rank number (Start from ZERO)
    MPI_Comm_rank( MPI_COMM_WORLD, &my_rank );

    // Each Rank: Create Data with NUM_ELEMENTS
    srand((unsigned int)time(NULL) + my_rank);
    for ( i = 0; i < NUM_ELEMENTS; i++)
    {
       data[i] = (float)rand() / (double)RAND_MAX;
    }

    // Each Rank: Print generated Data
    printf("Rank %d: \n", my_rank);
    printf("DATA = ");
    for ( i = 0; i < NUM_ELEMENTS; i++)
    {
       printf("%f ", data[i]);
    }
    printf("\n\n");
    
    // AllReduce (SUM) operation
    MPI_Allreduce( &data[0], &result[0], NUM_ELEMENTS, MPI_FLOAT, MPI_SUM, MPI_COMM_WORLD);
    
    // Print AllReduced (SUM) data from other Ranks
    printf("ALLREDUCED_DATA = ");
    for ( i = 0; i < NUM_ELEMENTS; i++)
    {
       printf("%f ", result[i]);
    }
   
    // Finalize MPI environment
    MPI_Finalize();

    return EXIT_SUCCESS;
} 
