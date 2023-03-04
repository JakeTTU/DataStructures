//
//  Header.h
//  Stack
//
//  Created by Jake Gonzalez on 2/13/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#ifndef Header_h
#define Header_h

class Node {
public:
    int datum;
    Node *next;
    Node(int);

};

class Stack {
    Node *head;
public:
    Stack();
    ~Stack();
    void destr_helper(Node*);
    void push(int); //adds an int to the top of the stack
    int pop(); //removes the int at the top of the stack, and returns it
    int peek(); //returns the int at the top of the stack, but does not remove it
    bool is_empty();
};
#endif /* Header_h */
