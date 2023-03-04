//
//  Queue.h
//  Queue
//
//  Created by Jake Gonzalez on 2/15/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
class Node {
public:
    int datum;
    Node *next, *prev;
    Node(int);
}

class Queue {
    Node *head, *tail;
public:
    Queue();
    ~Queue();
    void destr_helper(Node*);
    void push(int);
    int pop();
    int peek();
    bool is_empty();
}

#endif /* Queue_h */
