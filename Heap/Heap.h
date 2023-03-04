//
//  Heao.h
//  Heap
//
//  Created by Jake Gonzalez on 2/27/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#ifndef Heap_h
#define Heap_h

class Node {
public:
    int datum;
    Node *left, *right, *parent;
    Node(int);
};

class Heap {
    Node *tail, *root;
    void destr_helper(Node*);
    void upheap();
    void downheap();
    Node *smaller_child(Node*);
public:
    Heap();
    ~Heap();
    bool is_empty();
    int peek();
    void push(int);
    int pop();
};

#endif /* Heap_h */
