#include <iostream>
#include <omp.h>
#include <vector> 

int main() {
    const size_t N = 10000000;
    std::vector<double>A  (N,1.0);
    std::vector<double>B (N,2.0);
    std::vector<double>C (N,0.0);
    double start_time = omp_get_wtime();
    #pragma omp parallel for
    
    for(int i = 0 ; i< N;i++){
        C[i] = A[i]+B[i];
            
        }
    
    
    double end_time = omp_get_wtime();
    double time_fin = end_time-start_time;
    
    std::cout<<"total time"<<time_fin<<"\n";
    std::cout << "I = 1:  " <<C[0] <<"\n";
    std::cout << "N-1:  " << C[N-1]<<"\n";

    return 0;
}
