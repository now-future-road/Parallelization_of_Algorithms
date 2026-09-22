#include <iostream>
#include <cmath>
bool prime(int x){
    if(x<=1) return false;
    if(x<=3) return true;
    int limit= std::sqrt(x);
    for(int i = 2; i <=limit;i++){
        if(x % i == 0){
            return false;
        }
        
        

    }

   
   
   
    
    

       


    return true;
    
}
int main(){
    int x = 25;
    
    int digits = prime(x);
    if(digits == true){
        std::cout<<"It is prime";
    }
    else if(digits == false){
        std::cout<< "It is not prime";
        
    }
    

    
    
}