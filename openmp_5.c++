#include <iostream>
#include <omp.h>

long long fib_seq(int n) {
    if (n <= 1) return n;
    return fib_seq(n - 1) + fib_seq(n - 2);
}

long long fib_parallel(int n) {
    if (n <= 1) return n;

    if (n <= 20) return fib_seq(n);

    long long x, y;

    #pragma omp task shared(x)
    x = fib_parallel(n - 1);

    #pragma omp task shared(y)
    y = fib_parallel(n - 2);

    #pragma omp taskwait

    return x + y;
}

int main() {
    int n = 5;
    long long result = 0;

    double start = omp_get_wtime();

    #pragma omp parallel
    {
        #pragma omp single
        {
            result = fib_parallel(n);
        }
    }

    double end = omp_get_wtime();
    std::cout << "Fibonacci(" << n << ") = " << result << "\n";
    std::cout << "Time: " << (end - start)  << " s\n";

    return 0;
}