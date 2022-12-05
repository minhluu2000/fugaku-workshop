//==================================
// Single MPI process version of Hello World...
//
// Compile (Login Node or Pre/Post Environment)
// $ fccpx -Nclang -Kfast -o hello hello.c 
//
// Run (Compute Node)
// $ ./hello
//==================================

#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    printf("Hello World... \n");

    return EXIT_SUCCESS;
}
