//
//  apple.cpp
//  Class "Fruit"
//
//  Created by max on 10/2/13.
//  Copyright (c) 2013 max. All rights reserved.
//

#include "apple.h"
void Apple::getSpecie()
{
    cout << "Enter your specie here: ";
    cin >> specie;
}
void Apple::showSpecie()
{
    cout << "Specie: " << specie << endl;
}