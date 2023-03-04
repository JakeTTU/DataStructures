//
//  Stack.cpp
//  Stack
//
//  Created by Jake Gonzalez on 2/13/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <stdio.h>
#include "Stack.h"

Node::Node(int datum) {
    this->datum = datum;
    this->next = 0;
}

Stack::Stack() {
    this->head = 0;
}

Stack::~Stack() {
    this->destr_helper(this->head);
}

void Stack::destr_helper(Node *node) {
    if (node) {// (node != NULL)
        destr_helper(node->next);
        delete node;
    }
}

void Stack::push(int datum) {
    Node *newNode = new Node(datum);
    
    newNode->next = this->head;
    this->head = newNode;
}

int Stack::pop(){
    if (!this->head) { //this->head == NULL
        throw "Stack is empty";
    }
    
    int retVal = this->head->datum;
    Node *oldHead = this->head;
    this->head = this->head->next;
    delete oldHead;
    return retVal;
}

int Stack::peek() {
    if (!this->head) { // this->head == NULL
        throw "Stack is empty";
    }
    return this->head->datum;
}

bool Stack::is_empty() {
    return !this->head; //if we a head (this->head == NULL) false will be returned
}

