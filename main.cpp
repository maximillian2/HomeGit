//
//  main.cpp
//  C++
//
//  Created by max on 7/7/13.
//  Copyright (c) 2013 max. All rights reserved.
//

// -------------------------------------------------------- //
// info: http://acm.timus.ru/problem.aspx?space=1&num=1083  //
// -------------------------------------------------------- //

#include <iostream>
#include <cstdlib>
#include <cmath>
//#include "../factorials.cpp"
using namespace std;

int factorial(int digit, int symbols){
    
    if (digit > 0) return digit * factorial(digit - symbols, symbols);
    else if (digit == 0) return 1;
    else if (digit < 0) return -1;

    return 0;
}

int main(void){
    
    int number = 0, i = 0;
    char input[24] = {0};
    
    cin.getline(input, 24);
    
    number = atoi(input);
    
    // looking for '!'
     for(int j = 1; j < 20; j++)
        if (input[j] == '!') i++;
    
    // printing out all the info
    cout << "i = " << i << endl;
    cout << "number = " << number << endl;
    cout << "Factorial: " << abs(factorial(number, i)) << endl;
    
    return 0;
}

