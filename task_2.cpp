
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#define N 4
#define NUM_PROCS 2
#define ROWS_PER_PROC (N / NUM_PROCS)


int main(int argc, char** argv) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    double A[N][N];
    double B[N][N];
    double C[N][N];

    double sub_A[ROWS_PER_PROC][N];
    double sub_C[ROWS_PER_PROC][N];

    if (rank == 0) {
        double val = 1.0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = val++;
                B[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }
    }

    MPI_Scatter(A, ROWS_PER_PROC * N, MPI_DOUBLE,
                sub_A, ROWS_PER_PROC * N, MPI_DOUBLE,
                0, MPI_COMM_WORLD);

    MPI_Bcast(B, N * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    for (int i = 0; i < ROWS_PER_PROC; i++) {
        for (int j = 0; j < N; j++) {
            printf("[Rank %d] Computing element C[%d][%d]:\n", rank, i, j);
            for (int k = 0; k < N; k++) {
                printf("  sub_A[%d][%d] (%.1f) * B[%d][%d] (%.1f)\n",
                       i, k, sub_A[i][k], k, j, B[k][j]);
            }
        }
    }

    MPI_Gather(sub_C, ROWS_PER_PROC * N, MPI_DOUBLE,
               C, ROWS_PER_PROC * N, MPI_DOUBLE,
               0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("--- Result Matrix C ---\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++){
                printf("[Rank %d] C[%d][%d] terms: ", rank, i, j);
                for(int k = 0; k < N; k++){
                    printf("(%.1f * %.1f)%s",
                    A[i][k], B[k][j],
                    (k == N - 1) ? "" : " + ");
                }
                printf("\n");
            }
        }
    }

    MPI_Finalize();
    return 0;
}