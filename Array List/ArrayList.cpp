//
//  ArrayList.cpp
//  Array List
//
//  Created by Jake Gonzalez on 1/30/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <stdio.h>
#include "ArrayList.h"
using namespace std;

ArrayList::ArrayList() {
    this->arr = new int[10];
    this->size = 10;
    this->numel = 0;
}

ArrayList::ArrayList(int size){
    this->arr = new int[size];
    this->size = size;
    this->numel = 0;
}

ArrayList::~ArrayList(){
    delete this->arr;
}

int ArrayList::get(int index){
    if (index >= this->numel) {
        throw "Index out of bounds error";
    }
    
    return this->arr[index];
}

void ArrayList::set(int index, int value){
    if (index >= this->numel) {
        throw "Index out of bounds error";
    }
    
    this->arr[index] = value;
}

void ArrayList::insert(int index, int value) {
    if (index > this->numel + 1){
        throw "Index out of bounds error";
    }
    
    if (this->numel == this->size) {
        int *newArr = new int[this->size *2];
        for (int i = 0; i < this->size; i++){
            newArr[i] = this->arr[i];
        }
        delete this->arr;
        this->arr = newArr;
        this->size *= 2;
    }
    this->numel++;
    for (int i = numel; i > index; i--){
        this->arr[i] = this->arr[i - 1];
    }
    this->arr[index] = value;
}

int ArrayList::rem(int index){
    if (index >= this->numel) {
        throw "Index out of bounds error";
    }
    
    int retVal = this->arr[index];
    
    this->numel--;
    for(int i = index; i <= this->numel; i++){
        this->arr[i] = this->arr[i+1];
    }
    
    return retVal;
}

string ArrayList::print_list(){
    string retStr = "{";
    if (this->numel > 0){
        retStr += " " + std::to_string(this->arr[0]);
        for (int i = 1; i < this->numel; i++){
            retStr += ", " + std::to_string(this->arr[i]);
            
        }
    }
    retStr += " }\n";
    return retStr;
}
