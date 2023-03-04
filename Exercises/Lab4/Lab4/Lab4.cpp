//
//  Lab4.cpp
//  Lab4
//
//  Created by Jake Gonzalez on 2/16/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <stdio.h>
#include "Lab4.h"
#include <iostream>

Node::Node(int datum) { //Node constructor
    this->datum = datum;
    this->next = NULL;
    this->prev = NULL;
}

Stack::Stack() { //Stack constructor
    this->head = NULL;
    this->tail = NULL;
}

Stack::~Stack(){ //Stack destructor
    this->destr_helper(this->head); //call destr_helper function
}

void Stack::destr_helper(Node *node) { //destr_helper function
    if (node) {                        //(node != NULL)
        destr_helper(node->next);      //iterates through until next is NULL
        delete node;                   //node is deleted
    }
}

int Stack::push(int datum) { //push function
    Node *newNode = new Node(datum); //new node instance is created with datum
    
    if (this->head) {                //if (this->head != NULL)
        this->head->prev = newNode;  //previous head points to newNode
    }
    newNode->next = this->head;      //head points to newNode
    this->head = newNode;            //new head from newNode
    if (!this->tail) {               //if (this->tail == NULL)
        this->tail = newNode;
    }
    return newNode->datum;
}

int Stack::pop() { //pop funcion
    if (!this->head) { //(this->head == NULL)
        throw "Stack is empty";
    }
    int retVal = this->head->datum; //retVal is declared as datum of head
    Node *oldHead;                  //new Node instance
    oldHead = this->head;           //oldHead declared as this->head
    this->head = this->head->next;  //this->head declared as this->head->next
    return retVal;                  //popped datum is returned
}

int Stack::enqueue(int datum) {
    Node *newNode = new Node(datum);
    if (this->tail) {
        this->tail->next = newNode;
    }
    newNode->prev = this->tail;
    this->tail = newNode;
    if (!this->head) {
        this->head = newNode;
    }
    return datum;
}


int Stack::dequeue() {
    if (!this->head) { // this->head == NULL
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

int Stack::peek() {
    if (!this->head) { // this->head == NULL
        throw "Stack is empty";
    }
    return this->head->datum;
}

bool Stack::is_empty() {
    return !this->head; //if we a head (this->head == NULL) false will be returned
}

