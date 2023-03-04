//
//  main.cpp
//  Lab1
//
//  Created by Jake Gonzalez on 2/1/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include "Adder.h"
#include <iostream>
using namespace std;

int main() {
   
    //Initialize operands
    Adder operation(12, 8);
    cout << "First Operand = " <<operation.get(1) << endl;
    cout << "Second Operand = " << operation.get(2) << endl;
    cout << "Addition = " << operation.add() << endl;
    cout << "Subtraction = " <<operation.subtract() << endl;
    cout << "Multiplication = " << operation.multiply() << endl;
    cout << "Division = " << operation.divide() << endl;
    
    //Re-initialize operands
    operation.set(1, 13);
    operation.set(2, 7);
    cout << "First Operand = " <<operation.get(1) << endl;
    cout << "Second Operand = " << operation.get(2) << endl;
    cout << "Addition = " << operation.add() << endl;
    cout << "Subtraction = " <<operation.subtract() << endl;
    cout << "Multiplication = " << operation.multiply() << endl;
    cout << "Division = " << operation.divide() << endl;
   
    return 0;
}
