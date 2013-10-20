//
//  fruit.cpp
//  Class "Fruit"
//
//  Created by max on 10/2/13.
//  Copyright (c) 2013 max. All rights reserved.
//

#include "fruit.h"

Fruit::Fruit()
{
    cout << "Enter name of a fruit: "; cin >> name;
    cout << "Color of the fruit: "; cin >> color;
}
void Fruit::showName()
{
    cout << "Name: " << name << endl;
}
void Fruit::showColor()
{
    cout << "Color: " << color << endl;
}
