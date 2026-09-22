#include <iostream>
#include <string>


double convert(std::string x){
    double integer_part = 0.0;
    int i = 0;
    while( i < x.size() && x[i]>='0' && x[i]<='9'){
        integer_part = integer_part * 10.0 + (x[i]- '0');
        i++;

    } 
    double fraction_part = 0.0;
    double divisor = 10.0;
    if(x[i] == '.' &&  i<x.size()){
        i++;

        while(i<x.size() && x[i]>='0' && x[i]<='9'){
            fraction_part +=(x[i] - '0')/divisor;
            divisor *=10.0;
            i++;

       
        }
    }
    double total = integer_part+fraction_part;
    return total;
    
}
int main(){
    std::string x = "321.14";
    std::cout<<convert(x);

    return 0;
}