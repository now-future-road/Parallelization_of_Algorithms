#include <iostream>
#include <cmath>
#include <list>
#include<vector>

int isprime(int x){
    int limit = std::sqrt(x);
    for(int i = 2; i <=limit ;i++){
        if(x% i == 0){
            return false;
        }
    }
    return true;

}
std::list<int> duplicate(int x){
    std::vector<int> count(10,0);
    std::list<int> digit;
    while(x>0){
        int d = x%10;
        count[d]++;
        x/=10;
    }
    for(int d = 0; d<10;d++){
        if(count[d]>1){
            digit.push_back(d);
        }
    }
    return digit;
    

}

int main(){

    int x = 1333;
    if(isprime(x) == true){
        std::cout<<x<<"prime number";
    }

    
    
    std::list<int> i = duplicate(x);
    for(int j :i){
        std::cout<< j;
    }
    return 0;

}