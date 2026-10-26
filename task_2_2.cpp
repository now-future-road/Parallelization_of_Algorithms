#include <mpi.h>
#include <stdio.h>

#define N 2
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
        A[0][0] = 1.0; A[0][1] = 3.0;
        A[1][0] = 4.0; A[1][1] = 8.0;

        B[0][0] = 5.0; B[0][1] = 4.0;
        B[1][0] = 3.0; B[1][1] = 0.0;

        for (int i = 0; i < ROWS_PER_PROC; i++) {
            for (int j = 0; j < N; j++) {
                sub_A[i][j] = A[i][j];
            }
        }

        for (int target_rank = 1; target_rank < size; target_rank++) {
            int start_row = target_rank * ROWS_PER_PROC;
            MPI_Send(&A[start_row][0], ROWS_PER_PROC * N, MPI_DOUBLE,
                     target_rank, 0, MPI_COMM_WORLD);
        }
    } else {
        MPI_Recv(sub_A, ROWS_PER_PROC * N, MPI_DOUBLE,
                 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    MPI_Bcast(B, N * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    for (int i = 0; i < ROWS_PER_PROC; i++) {
        for (int j = 0; j < N; j++) {
            sub_C[i][j] = 0.0;
            for (int k = 0; k < N; k++) {
                sub_C[i][j] += sub_A[i][k] * B[k][j];
            }
        }
    }

    if (rank == 0) {
        for (int i = 0; i < ROWS_PER_PROC; i++) {
            for (int j = 0; j < N; j++) {
                C[i][j] = sub_C[i][j];
            }
        }

        for (int src_rank = 1; src_rank < size; src_rank++) {
            int start_row = src_rank * ROWS_PER_PROC;
            MPI_Recv(&C[start_row][0], ROWS_PER_PROC * N, MPI_DOUBLE,
                     src_rank, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }

        printf("--- Result Matrix C ---\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%.0f\n", C[i][j]);
            }
        }
    } else {
        MPI_Send(sub_C, ROWS_PER_PROC * N, MPI_DOUBLE,
                 0, 1, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}