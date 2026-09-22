#include <iostream>
#include <cmath>


double defsine(double x, int terms = 10){

    double sum = 0.0;
    
    for(int i = 1; i<=terms;i++){
        sum+=x;

        x *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
    }
    return sum;



}

int main(){
    double x = 3;
    for(int i =0; i< 3;i++){
        double out = defsine(i);
        std::cout<<out<<std::endl;
    }




    return 0;



}