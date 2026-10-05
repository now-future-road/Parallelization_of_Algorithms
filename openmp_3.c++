#include <vector>
#include <iostream>
int main(){
    int N = 1000;
    

    std::vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int p = 2; p * p <= N; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i <= N; i += p)
                is_prime[i] = false;
        }
    }
    int prime_count_atomic = 0;
    #pragma omp parallel for
    for(int i = 2; i<= N;++i){
        if(is_prime[i]){
            #pragma omp atomic
            prime_count_atomic++;
            
        }
    }
    std::cout <<  prime_count_atomic<< "\n";
        
    
}