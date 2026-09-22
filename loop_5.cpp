#include <iostream>

int main(){

    for(int i = 0; i < 5; ++i){
        if (i == 0){
            
            continue;
            
        };
        if (i == 1){
            
            continue;
        }
        
        if (i > 1){
            std::cout<<"i is   " << i <<": ";

            for(int j = 1; j < i ; j++){
                int f = j + (j+1);
                std::cout<<f<<" ";


            }
            std::cout << "\n";



        }
    }
    return 0;




}