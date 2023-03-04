//
//  Heap.cpp
//  Heap
//
//  Created by Jake Gonzalez on 2/27/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <stdio.h>
#include "Heap.h"

Node::Node(int datum) {
    this->datum = datum;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

Heap::Heap() {
    this->tail = NULL;
    this->root = NULL;
}

Heap::~Heap() {
    this->destr_helper(this->root);
}

void Heap::destr_helper(Node *node) {
    if (node) {
        this->destr_helper(node->left);
        this->destr_helper(node->right);
        delete node;
    }
}

void Heap::upheap() {
    Node *temp = this->tail;
    int swapNum;
    while (temp->parent && temp->datum < temp->parent->datum) {
        swapNum = temp->datum;
        temp->datum = temp->parent->datum;
        temp->parent->datum = swapNum;
    }
}

void Heap::downheap() {
    Node *temp = this->root;
    Node *checkNode = this->smaller_child(this->root);
    int swapNum;
    while (checkNode) {
        if (checkNode->datum < temp->datum){
            swapNum = temp->datum;
            temp->datum = checkNode->datum;
            checkNode->datum = swapNum;
        }
        temp = checkNode;
        checkNode = this->smaller_child(temp);
    }
}

//returns the smaller of the childern or null
Node* Heap::smaller_child(Node *node) {
    if (node) {
        if (node->left && !node->right) {
            node = node->left;
        }
        else if (node->right && !node->left) {
            node = node->right;
        }
        else if (node->right && node->left) {
            if (node->right->datum < node->left->datum) {
                node = node->right;
            }
            else {
                node = node->left;
            }
        }
        else {
            return NULL;
        }
    }
    return node;
}

bool Heap::is_empty(){
    return !this->root;
}

int Heap::peek(){
    if (this->is_empty()) {
        throw "Heap is empty";
    }
    else {
        return this->root->datum;
    }
}

void Heap::push(int datum) {
    Node *newNode = new Node(datum);
    Node *temp = this->tail;
    this->tail = newNode;
    if (this->is_empty()) {
        this->root = newNode;
        
    }
    else {
        /* insert at the next pos */
        //go up until in root or left node
        while (temp->parent && temp->parent->right == temp) {
            temp = temp->parent;
        }
        //if not in root go up one and right one
        if (temp->parent) {
            temp = temp->parent;
            if (temp->right) {
                temp = temp->right;
            }
            else {
                temp->right = newNode;
                newNode->parent = temp;
                this->upheap();
                return;
            }
        }
        //go left as far as possible
        while(temp->left) {
            temp = temp->left;
        }
        temp->left = newNode;
        newNode->parent = temp;
        /* upheap */
        this->upheap();
    }
}

int Heap::pop(){
    if (is_empty()) {
        throw "Heap is empty";
    }
    
    int retNum = this->root->datum;
    /* swap the root with the tail */
    this->root->datum = this->tail->datum;
    //move tail to previous postion
    Node *delNode = this->tail;
    while (this->tail->parent && this->tail->parent->left == this->tail) {
        this->tail = this->tail->parent;
    }
    if(this->tail->parent) {
        this->tail = this->tail->parent->left;
    }
    while (this->tail->right) {
        this->tail = this->tail->right;
    }
    if (delNode == delNode->parent->left) {
        delNode->parent->left = NULL;
    }
    else {
        delNode->parent->right = NULL;
    }
    
    /* downheap */
    this->downheap();
    delete delNode;
    return retNum;
}
