#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <omp.h>

int main() {
    const long long N = 100000000; 
    long long global_inside_count = 0;

    double start_time = omp_get_wtime();

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        long long darts_per_thread = N / num_threads;
        long long start_idx = thread_id * darts_per_thread;
        long long end_idx = (thread_id == num_threads - 1) ? N : start_idx + darts_per_thread;

        unsigned int seed = 12345 + thread_id * 1000;
        long long local_inside_count = 0;

        for (long long i = start_idx; i < end_idx; ++i) {
            double x = static_cast<double>(rand_r(&seed)) / RAND_MAX;
            double y = static_cast<double>(rand_r(&seed)) / RAND_MAX;

            if (x * x + y * y <= 1.0) {
                local_inside_count++;
            }
        }

        #pragma omp barrier

        #pragma omp single
        {
            std::cout << "All threads " << num_threads <<"\n";
        }

        #pragma omp atomic
        global_inside_count += local_inside_count;
    }

    double end_time = omp_get_wtime();

    double pi_approx = 4.0 * static_cast<double>(global_inside_count) / static_cast<double>(N);

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Darts inside circle: " << global_inside_count << " / " << N << "\n";
    std::cout << "Estimated Pi:        " << pi_approx << "\n";
    std::cout << "Execution Time:      " << (end_time - start_time) * 1000.0 << " ms\n";

    return 0;
}