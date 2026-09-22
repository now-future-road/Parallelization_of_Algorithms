#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath> 

int main() {
   
    for(int i = 1; i  < 400; ++i){


        
        int n = i;
        int original_n = n; 
        std::vector<int> digits;
       

        while (n > 0) {

            digits.push_back(n % 10);
            n /= 10;
        }

        std::reverse(digits.begin(), digits.end());
        int num_digits = digits.size();
        int sum = 0;


        std::list<int> mylist;

        for (int d = 0; d < digits.size(); ++d) {
            int current_digit = digits[d]; // Get actual digit value
            int power_num = std::pow(current_digit, num_digits);
            sum += power_num;
            
            mylist.push_back(power_num);
        }

        if (sum == original_n) {
            std::cout << original_n << "  Armstrong number!\n";
        }

        for (int val; val < mylist.size(); val++) {
            std::cout << val << " ";
        }

}


return 0;



}