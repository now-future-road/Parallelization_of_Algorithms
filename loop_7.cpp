#include <iostream>
#include <algorithm>

int getprime(int num,int prime){
    int count = 0;
    while(num> 0 && num % prime == 0){
        count++;
        num /=prime;
    }
    return count;

}

int lcmfind(int num1, int num2){
    int num11;
    if ( num1>num2 and num1% num2 ==0){
        num11 = num1;


    }
    int num22;
    if((num2>num1 and num2%num1==0)){
        num22 =num2;
    }
    int count2_num1 = getprime(num1, 2);
    int count2_num2 = getprime(num2, 2);
    int max2 = std::max(count2_num2, count2_num1);

    int count3_num1 = getprime(num1, 3);
    int count3_num2 = getprime(num2, 3);
    int max3 = std::max(count3_num2, count3_num1);

     int count4_num1 = getprime(num1, 4);
    int count4_num2 = getprime(num2, 4);
    int max4 = std::max(count4_num2, count4_num1);

     int count5_num1 = getprime(num1, 5);
    int count5_num2 = getprime(num2, 5);
    int max5 = std::max(count5_num2, count5_num1);

    int lcm = 1;
    for(int i = 0; i< max2; i++){
        lcm*=2;
    }

    for(int i = 0; i< max3; i++){
        lcm*=3;
    }
    for(int i = 0; i< max4; i++){
        lcm*=4;
    }
    for(int i = 0; i< max5; i++){
        lcm*=5;
    }
    
    

    return lcm;



}
int main(){
    int a = 10;
    int b = 5;
    
    std::cout <<lcmfind(a,b);
    return 0;
}
