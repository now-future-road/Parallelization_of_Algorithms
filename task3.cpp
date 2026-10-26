#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Comm parent_comm;
    MPI_Comm_get_parent(&parent_comm);

    if (parent_comm != MPI_COMM_NULL) {
        int parent_rank = 0; 
        printf("I am %d process from %d processes! My parent is %d.\n",
               rank, size, parent_rank);
        fflush(stdout);
    } else {
        int n = 0;

        if (rank == 0) {
            if (scanf("%d", &n) != 1) {
                n = 0;
            }
        }

        MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

        printf("I am %d process from %d processes! My parent is none.\n",
               rank, size);
        fflush(stdout);

        if (n > 0) {
            MPI_Comm child_comm;
            int* array_of_errcodes = (int*)malloc(n * sizeof(int));

            MPI_Comm_spawn(argv[0],
                           MPI_ARGV_NULL,
                           n,
                           MPI_INFO_NULL,
                           0,
                           MPI_COMM_WORLD,
                           &child_comm,
                           array_of_errcodes);

            free(array_of_errcodes);
        }
    }

    MPI_Finalize();
    return 0;
}