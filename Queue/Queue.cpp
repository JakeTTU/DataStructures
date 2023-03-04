//
//  Queue.cpp
//  Queue
//
//  Created by Jake Gonzalez on 2/15/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <stdio.h>
#include "Queue.h"

Node::Node(int datum) {
    this->datum = datum;
    this->next = 0;
    this->prev = 0;
}

Queue::Queue() {
    this->head = 0;
    this->tail = 0;
}

Queue::~Queue() {
    this->destr_helper(this->head);
}

void Queue::destr_helper(Node *node) {
    if (node) {// (node != NULL)
        destr_helper(node->next);
        delete node;
    }
}

void Queue::push(int datum) {
    Node *newNode = new Node(datum);
    
    if (this->head) {
        this->head->prev = newNode;
    }
    newNode->next = this->head;
    this->head = newNode;
    if (!this->tail) {
        this->tail = newNode;
    }
}

int Queue::pop(){
    if (!this->head) { //this->head == NULL
        throw "Stack is empty";
    }
    
    int retVal = this->tail->datum;
    Node *oldTail = this->tail;
    this->tail = this->tail->prev;
    if (this->tail) {
        this->tail->next = 0;
    }
    else {
        this->head = 0;
    }
    delete oldTail;
    return retVal;
}

int Queue::peek() {
    if (!this->head) { // this->head == NULL
        throw "Stack is empty";
    }
    return this->tail->datum;
}

bool Queue::is_empty() {
    return !this->head; //if we a head (this->head == NULL) false will be returned
}

