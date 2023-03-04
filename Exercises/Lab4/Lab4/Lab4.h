//
//  Lab4.h
//  Lab4
//
//  Created by Jake Gonzalez on 2/16/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#ifndef Lab4_h
#define Lab4_h

class Node {
public:
    int datum;
    Node *next, *prev;
    Node (int);
};

class Stack {
    Node *head, *tail;
public:
    Stack ();
    ~Stack ();
    void destr_helper(Node*);
    int push (int);
    int pop ();
    int peek ();
    bool is_empty ();
    int enqueue(int);
    int dequeue();
};

#endif /* Lab4_h */
