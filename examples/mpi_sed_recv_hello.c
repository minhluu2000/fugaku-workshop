//==================================
// MPI Send/Recv version of Hello
//
// Compile (Login Node or Pre/Post Environment)
// $ mpifccpx -Nclang -Kfast -o mpi_send_rev_hello mpi_send_recv_hello.c 
//
// Run (Compute Node) using even number on nodes]
// $ mpiexec -np NUM_NODES ./mpi_send_recv_hello
//==================================

#include "mpi.h" 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{ 
    char message[20]; 

    int my_rank;   // My MPI process number (Rank)
    int num_procs; // Total number MPI processes     
 
    int my_pair;   // My MPI process pair (Rank)

    MPI_Status status; 
    // Initialize MPI environment
    MPI_Init(NULL, NULL);
  
    // Get the total numberof MPI processes
    MPI_Comm_size( MPI_COMM_WORLD, &num_procs );
    // Get my rank number (Start from ZERO)
    MPI_Comm_rank( MPI_COMM_WORLD, &my_rank );

    // Odd rank node will send message "Hello" to even rank node
    if ((my_rank) % 2 == 0)
    {
        my_pair = my_rank + 1;
        sprintf(message,"Hello from %d \n", my_rank);
        MPI_Send(message, strlen(message), MPI_CHAR, my_pair, 99, MPI_COMM_WORLD); 
    } 
    else   
    {
        my_pair = my_rank - 1;
        MPI_Recv(message, 20, MPI_CHAR, my_pair, 99, MPI_COMM_WORLD, &status); 
        printf("Received from node %d: %s \n", my_pair, message); 
    } 

    // Finalize MPI environment
    MPI_Finalize();

    return EXIT_SUCCESS;
} 
