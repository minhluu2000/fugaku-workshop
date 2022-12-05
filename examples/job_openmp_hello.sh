#!/bin/bash
#PJM -g ra020021  # Group name

#PJM -L "rscgrp=small"              # Resource group small (up to 384 nodes Max.[384; 138x288; 46x18x48])
# #PJM -L "rscgrp=excl_HPCS_2212-1" # EU-ASEAN HPC School: 12/5 0:00 to 12/9 24:00 

#PJM -L "node=1"                    # Number of nodes

#PJM -L "elapse=5:00"  # Running time
#PJM -L "eco_state=2"  # Eco mode setting

# #PJM -x PJM_LLIO_GFSCACHE=/vol0004:/vol0006  # Volume names used by the job
#PJM -s # Output statistical information                        

export PLE_MPI_STD_EMPTYFILE=off
export OMP_NUM_THREADS=48

./openmp_hello
