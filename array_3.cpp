#include <iostream>
#include <string>
double convert(std::string x){
    double integer_part = 0.0;
    int i = 0;
    while(i < x.size() && x[i] >='0' && x[i]<='9'){
        integer_part = integer_part*10.0 + (x[i]-'0');
        i++;
    }
    double total = integer_part;
    return total;
}
int main(){
    std::string x ="321";
    std::cout<< convert(x)<< std::endl;
}