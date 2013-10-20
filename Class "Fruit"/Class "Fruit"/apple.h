//
//  apple.h
//  Class "Fruit"
//
//  Created by max on 10/2/13.
//  Copyright (c) 2013 max. All rights reserved.
//

#ifndef __Class__Fruit___apple__
#define __Class__Fruit___apple__

#include <iostream>
#include "fruit.h"
class Apple : public Fruit
{
private:
    string specie;
public:
    void getSpecie();
    void showSpecie();
};

#endif /* defined(__Class__Fruit___apple__) */
