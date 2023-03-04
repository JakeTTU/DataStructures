//
//  main.cpp
//  Lab4
//
//  Created by Jake Gonzalez on 2/16/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <iostream>
#include "Lab4.h"
using namespace::std;

int main() {
    Stack *lab4 = new Stack();

    cout << "{";
    for (int i = 0; i < 9; i++) {
        cout << lab4->push(i);
        cout << ",";
    }
    cout << "}" << endl;
    
    cout << "Dequeue value: ";
    cout << lab4->dequeue() << endl;
    
    cout << "Pop: ";
    cout << lab4->pop() << endl;
    
    cout<< "Enqueue :";
    cout << lab4->enqueue(8) << endl;
    
    cout << "Datum at head: ";
    cout << lab4->peek() << endl;
    
    cout << "Popping: ";
    while (!lab4->is_empty()) {
        cout << lab4->pop();
        cout << ", ";
    }
    cout << endl;

    if (lab4->is_empty()== 1) cout << "Stack is empty" << endl;
    else cout << "Stack is not empty" << endl;
    
    return 0;
}

// A stack is a singly linked list that implements last in first out (LIFO)
// A queue is similar to a stack, however it implements first in first out (FIFO)
