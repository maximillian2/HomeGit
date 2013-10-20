//
//  lemon.cpp
//  Class "Fruit"
//
//  Created by max on 10/5/13.
//  Copyright (c) 2013 max. All rights reserved.
//

#include "lemon.h"

void Lemon::getQuantity()
{
    cout << "Enter quantity of " << name << ": ";
    cin >> quantity;
}
void Lemon::showQuantity()
{
    cout << "There are " << quantity << " of " << name << endl;
}