//
//  LinkedList.cpp
//  Lab2
//
//  Created by Jake Gonzalez on 2/6/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"
#include <iostream>


Node::Node(int datum) {
    this->datum = datum;
    this->next = NULL;
}

Node::~Node(){
    
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

void Node::set_prev(Node *prev) {
    this->prev = prev;
}

Node* Node::get_prev() {
    return this->prev;
}

LinkedList::LinkedList() {
    this->size = 0;
    this->head = NULL;
    
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
        
        if(newNode->get_next()) {
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
    if (index == 0) {
        this->head = temp->get_next();
        if (this->head) {
            this->head->set_prev (NULL);
        }
    }
    else {
        for (int i = 1; i < index; i++) {
            temp = temp->get_next();
        }
        temp->get_prev()->set_next(temp->get_next());
        if (temp->get_next()) {
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
        
    }
    std::cout << " }" << std::endl;
}

void LinkedList::print_list_rev() {
    Node *last;
    last = this->head;
    std::cout << "{";
    if (this->size > 0) {
        while(this->head->get_next() != NULL) {
            last = this->head->get_next();
            this->head = this->head->get_next();
        }
        //std::cout << " " << this->head->get_datum();
        for (Node *temp = last; temp; temp = temp->get_prev()) {
            std::cout << "," << temp->get_datum();
        }
    }
    std::cout << "}" << std::endl;
}
