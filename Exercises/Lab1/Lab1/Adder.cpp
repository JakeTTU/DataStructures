//
//  Adder.cpp
//  Lab1
//
//  Created by Jake Gonzalez on 2/1/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <stdio.h>
#include "Adder.h"
using namespace std;

//Default constructor
Adder::Adder() {
    this->num1 = 2;
    this->num2 = 2;
}

//Initializes local variables
Adder::Adder(int a, int b){
    this->num1 = a;
    this->num2 = b;
}

//Returns the value of either the first or second operand
int Adder::get(int a){
    if (a == 1){
        return this->num1;
    }
    else if (a == 2){
        return this->num2;
    }
    else return 0;
}

//Re-initializes individual operands
void Adder::set(int a, int b){
    if (a == 1){
        this->num1 = b;
    }
    else if (a == 2){
        this->num2 = b;
    }
}

//Add function adds the two operands
int Adder::add(){
    return num1 + num2;
}

//Subtract function subtracts the two operands
int Adder::subtract(){
    return num1 - num2;
}

//Multiply funciton multiplies the two operands
int Adder::multiply(){
    return num1 * num2;
}

//Divide function divides the two operands
int Adder::divide(){
    return num1 / num2;
}
