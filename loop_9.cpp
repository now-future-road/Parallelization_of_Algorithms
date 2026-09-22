#include <iostream>
#include <string>
bool get_digit(int n){
    std::string s = std::to_string(n);
    int length = s.length();

    for(int i =0; i< length;i++){
        if(s[i]!=s[length-i-1]){
            return false;
        }

        if(s[i]==s[length-i-1]){
            
            
            return true;
        }

        }
  

};
    
int main(){
    int n = 1000;
    std::cout << n<< "is palindrom<"<< (get_digit(n)? "yes" : "no");
    return 0;
}

//I tried using list->digits from numbers->check digits[i] ==digits[i-len]