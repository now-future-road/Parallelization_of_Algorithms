#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string s = "Hello";
    int freq[256] = {0}; 

   
    for (char c : s) {
        freq[std::tolower(c)]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            std::cout << (char)i << ": " << freq[i] << std::endl;
        }
    }

    return 0;
}