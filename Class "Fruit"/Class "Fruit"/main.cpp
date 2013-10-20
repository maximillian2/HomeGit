//
//  main.cpp
//  Class "Fruit"
//
//  Created by max on 10/2/13.
//  Copyright (c) 2013 max. All rights reserved.
//

#include <iostream>
#include "fruit.h"
#include "apple.h"
#include "lemon.h"
using namespace std;

int main(void)
{
    
//    Fruit fruit;
//    cout << "0 level of inheritance" << endl;
//    fruit.showName();
//    fruit.showColor();
//    
//    Apple apple;
//    cout << "1 level of inheritance" << endl;
//    apple.showName();
//    apple.showColor();
//    
//    cout << "Self methods of class \"Apple\"" << endl;
//    apple.getSpecie();
//    apple.showSpecie();
//    
//    Lemon lemon;
//    cout << "2 level of inheritance" << endl;
//    lemon.showName();
//    lemon.showColor();
//    
//    cout << "1 level of inheritance" << endl;
//    lemon.getSpecie();
//    lemon.showSpecie();
//    
//    cout << "Self methods of class \"Lemon\"" << endl;
//    lemon.getQuantity();
//    lemon.showQuantity();
    
    
    Fruit fruit;
    
    cout << endl;
    
    Apple apple;
    apple.getSpecie();
    
    cout << endl;
    
    Lemon lemon;
    lemon.getSpecie();
    lemon.getQuantity();
    
    cout << endl;
    
    cout << "STRUCTURE:" << endl;
    
    cout << endl;
    cout << "=---------------=" << endl;
    cout << "0 LEVEL of inheritance (class Fruit)" << endl;
    fruit.showName();
    fruit.showColor();
    cout << "=---------------=" << endl;
    cout << endl;
    
    cout << endl;
    cout << "=---------------=" << endl;
    cout <<"1 LEVEL of inheritance (class Fruit)" << endl;
    apple.showName();
    apple.showColor();
    
    cout << "Self mothods (class Apple)" << endl;
    apple.showSpecie();
    cout << "=---------------=" << endl;
    cout << endl;
    
    cout << endl;
    cout << "=---------------=" << endl;
    cout << "2 LEVEL of inheritance (class Fruit)" << endl;
    lemon.showName();
    lemon.showColor();

    cout << "1 LEVEL of inheritance (class Apple)" << endl;
    lemon.showSpecie();
    
    cout << "Self methods (class Lemon)" << endl;
    lemon.showQuantity();
    cout << "=---------------=" << endl;
    cout << endl;
    return 0;
}

