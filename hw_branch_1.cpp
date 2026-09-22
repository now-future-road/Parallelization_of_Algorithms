#include <iostream>
using namespace std;
int main(){
    int year = 2000, month = 12, day = 23;

    bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int feb = isLeapYear ? 29: 28;
  
    switch(month - 1)

    {
        case 11: day+=30;
        case 10: day+=31;
        case 9: day+=30;
        case 8: day += 31;
        case 7: day += 30;
        case 6: day += 31;
        case 5: day += 30;
        case 4: day += 31;
        case 3: day+=30;
        case 2: day +=feb;
        case 1: day +=31; 
        case 0: break;
    }


    std::cout<< day<<endl;
    return 0;
}



    


