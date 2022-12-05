//==================================
// Single MPI process version of Hello World...
//
// Compile (Login Node or Pre/Post Environment)
// $ fccpx -Nclang -Kfast -Kopenmp -o openmp_hello openmp_hello.c 
//
// Run (Compute Node)
// $ export OMP_NUM_THREADS=XX
// $ ./openmp_hello
//==================================

#include <omp.h>
 
#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char* argv[])
{
    int my_thread;   // My OpenMP thread
    int num_threads; // Total number of OpenMP threads

    // Beginning of OpenMP Parallel Region
    #pragma omp parallel
    {
         my_thread   = omp_get_thread_num();
         num_threads = omp_get_num_threads();

         printf("Hello World... from thread %d of %d \n", my_thread, num_threads);
    }
    // End of OpenMP parallel region

    return EXIT_SUCCESS;
}
