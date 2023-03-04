//
//  Adder.h
//  Lab1
//
//  Created by Jake Gonzalez on 2/1/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#ifndef Adder_h
#define Adder_h
#include <string>

class Adder{
    int num1, num2, value;
public:
    Adder();
    Adder(int, int);
    void set (int, int);
    int add();
    int subtract();
    int multiply();
    int divide();
    int get(int);
};

#endif /* Adder_h */
