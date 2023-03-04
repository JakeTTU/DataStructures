//
//  LinkedList.cpp
//  LinkedList
//
//  Created by Jake Gonzalez on 2/4/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"
#include <iostream>


Node::Node(int datum) {
    this->datum = datum;
    this->next = NULL;
}

Node::~Node() {
    
}

int Node::get_datum() {
    return this->datum;
}

void Node::set_datum(int datum) {
    this->datum = datum;
}

Node* Node::get_next() {
    return this->next;
}

void Node::set_next(Node *next) {
    this->next = next;
}

void Node::set_prev(Node *prev){
    this->prev = prev;
}

Node* Node::get_prev() {
    return this->prev;
}

LinkedList::LinkedList() {
    this->size = 0;
    this->head = NULL;
}

LinkedList::~LinkedList() {
    this->destr_helper(this->head);
}

void LinkedList::destr_helper(Node *node) {
    if (node->get_next() != NULL) {
        this->destr_helper(node->get_next());
    }
    delete node;
}

int LinkedList::get(int index) {
    if (index >= this->size) {
        throw "Index out of bounds";
    }
    
    Node *temp = this->head;
    for (int i = 0; i < index; i++) {
        temp = temp->get_next();
    }
    
    return temp->get_datum();
}

void LinkedList::set(int index, int value) {
    if (index >= this->size) {
        throw "Index out of bounds";
    }
    
    Node *temp = this->head;
    for (int i = 0; i < index; i++) {
        temp = temp->get_next();
    }
    
    temp->set_datum(value);
}

void LinkedList::insert(int index, int value) {
    if (index > this->size) {
        throw "Index out of bound";
    }
    
    Node *newNode = new Node(value);
    Node *temp = this->head;
    
    if (index == 0) {
        newNode->set_next(this->head);
        this->head = newNode;
    }
    else {
        for (int i = 1; i < index - 1; i++) {
            temp = temp->get_next();
        }
        
        newNode->set_next(temp->get_next());
        newNode->set_prev(temp);
        
        if(newNode->get_next()){
            newNode->get_next()->set_prev(newNode);
        }
        temp->set_next(newNode);
    }
    this->size++;
}

int LinkedList::rem(int index) {
    if (index >= this->size) {
        throw "Index out of bound";
    }
    
    int retVal;
    Node *temp = this->head;
    //Node *retNode;
    if (index == 0) {
        this->head = temp->get_next();
        if (this->head) {
            this->head->set_prev (NULL);
        }
        //retNode = temp;
    }
    else {
        for (int i = 0; i < index; i++) {
            temp = temp->get_next();
        }
        
        //retNode = temp->get_next();
        //temp->set_next(retNode->get_next());
        temp->get_prev()->set_next(temp->get_next());
        if (temp->get_next()){
            temp->get_next()->set_prev(temp->get_prev());
        }
    }
    retVal = temp->get_datum();
    delete temp;
    this->size--;
    return retVal;
}

void LinkedList::print_list() {
    std::cout << "{";
    if (this->size > 0) {
        std::cout << " " << this->head->get_datum();
        for (Node *temp = this->head->get_next(); temp; temp = temp->get_next()) {
            std::cout << ", " << temp->get_datum();
        }
    }
    std::cout << " }" << std::endl;
}
