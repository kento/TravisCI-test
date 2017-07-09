#include <stdlib.h>
#include <stdio.h>
#include "mpi.h"

int MPI_Init(int* argc, char** argv[])
{
  printf("Before %s\n", __func__);
  PMPI_Init(argc, argv);
  printf("After %s\n", __func__);
  return MPI_SUCCESS;
}

int MPI_Finalize() {
  printf("Before %s\n", __func__);
  PMPI_Finalize();
  printf("After %s\n", __func__);
  return MPI_SUCCESS;
}
