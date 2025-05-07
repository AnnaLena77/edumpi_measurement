#include <mpi.h>
#include "edumpi_measurement.h"

int MPI_Init(int* argc, char*** argv)
{
    int result;

    result = PMPI_Init(argc, argv);
    
    test_function();
    return result;
}


int MPI_Finalize(void){
    int result = PMPI_Finalize();

    return result;
}
