#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    char original_str[] = "Parallelization";
    char my_letter;

    MPI_Scatter(original_str, 1, MPI_CHAR, &my_letter, 1, MPI_CHAR, 0, MPI_COMM_WORLD);

   char *gathered_str = NULL;
    if (rank == 0) {
        gathered_str = (char *)malloc(size * sizeof(char));
    }

    MPI_Gather(&my_letter, 1, MPI_CHAR, gathered_str, 1, MPI_CHAR, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        for (int i = 0; i < size ; i++) {
            printf("Process %d got: '%c'\n", i, gathered_str[(size-1)-i]);
        }
        free(gathered_str);
    }

    MPI_Finalize();
    return 0;
}