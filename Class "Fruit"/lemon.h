//
//  lemon.h
//  Class "Fruit"
//
//  Created by max on 10/5/13.
//  Copyright (c) 2013 max. All rights reserved.
//

#ifndef __Class__Fruit___lemon__
#define __Class__Fruit___lemon__

#include <iostream>
#include "apple.h"

class Lemon : public Apple
{
private:
    string specie;
    int quantity;
public:
    void getQuantity();
    void showQuantity();
};

#endif /* defined(__Class__Fruit___lemon__) */
