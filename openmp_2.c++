#include <iostream>
#include <omp.h>
#include <cmath>
#include <iomanip>
int main() {
    double pi = 3.14159265359;
    double sum = 0.0;
    const long long N = 100000000;
    const double step = 1.0/static_cast<double>(N);
    double start_time = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum) 
      
    for( long long  i = 0; i < N;++i){
        
        double x = (i + 0.5) * step; 
        sum += 4.0 / (1.0 + x * x);
    }
    double  approx = sum * step;
    double end_time = omp_get_wtime();
    
    double total_time = end_time - start_time;
    std::cout << std::fixed <<std::setprecision(15);
    std::cout << "Pi: "<< pi<<"\n";
    std::cout <<"Total time: " << total_time<<"\n";
    std::cout <<"Approx: "<< approx <<"\n";
    

    return 0;
}