#include <iostream>
#include <list>
#include <cmath>
int digit(int x){
    
    int count = 0;
    std::list<int> mylist;
   while(x>0){
        int d = x%10;
        mylist.push_front(d);
        count++;
        x /=10;

    }
    int total_sum = 0;
    for(int i: mylist){
        total_sum += std::pow(i,count);
      

    }
    return total_sum;



}
int main(){
    int x = 153;
    if(digit(x)== x){
        std::cout<<"Armstrong number " << x;
    }
    else{
        std::cout<<"Nothing";
    }
    
    
    return 0;
}