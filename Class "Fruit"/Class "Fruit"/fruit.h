//
//  fruit.h
//  Class "Fruit"
//
//  Created by max on 10/2/13.
//  Copyright (c) 2013 max. All rights reserved.
//

#ifndef __Class__Fruit___fruit__
#define __Class__Fruit___fruit__

#include <iostream>
using namespace std;

class Fruit
{
protected:
    string name;
    string color;
public:
    Fruit();
//    Fruit(string name, string color);
    void showName();
    void showColor();
};

#endif /* defined(__Class__Fruit___fruit__) */
