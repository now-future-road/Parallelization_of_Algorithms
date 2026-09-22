#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<int> > A(3, std::vector<int>(4));
    int a_data[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            A[i][j] = a_data[i][j];
        }
    }

    std::vector<std::vector<int> > B(4, std::vector<int>(3));
    int b_data[4][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            B[i][j] = b_data[i][j];
        }
    }

    int rows_A = 3;
    int cols_A = 4;
    int cols_B = 3;

    std::vector<std::vector<int> > C(rows_A, std::vector<int>(cols_B, 0));

    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < cols_B; ++j) {
            for (int k = 0; k < cols_A; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    std::cout << "Resulting matrix C (3x3):" << std::endl;
    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < cols_B; ++j) {
            std::cout << C[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}