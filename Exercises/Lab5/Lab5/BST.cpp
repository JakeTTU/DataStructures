//
//  BST.cpp
//  Binary Search Tree
//
//  Created by Jake Gonzalez on 2/25/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <stdio.h>
#include "BST.h"

Node::Node(int datum) {
    this->datum = datum;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

BST::BST() {
    this->root = NULL;
}

BST::~BST() {
    this->dest_helper(this->root); 
}

void BST::dest_helper(Node *node){
    if (node) { //(node != NULL)
        this->dest_helper(node->left);
        this->dest_helper(node->right);
        delete node;
    }
    
}

void BST::insert(int datum) {
    Node *newNode = new Node(datum);
    if (!this->root) {
        this->root = newNode;
    }
    else {
        Node *temp = this->root;
        
        while (true) {
            if (datum < temp->datum) {
                if (temp->left) { //(temp->left != NULL)
                    temp = temp->left;
                }
                else {
                    temp->left = newNode;
                    newNode->parent = temp;
                    break;
                }
            }
            else if (datum > temp->datum){
                if (temp->right) { //(temp->right != NULL)
                    temp = temp->right;
                }
                else {
                    temp->right = newNode;
                    newNode->parent = temp;
                    break;
                    
                }
            }
            else {
                throw "Duplicates not allowed";
            }
        }
    }
}

Node* BST::search(int datum) {
    Node *temp = this->root;
    while (temp && temp->datum != datum) { //(temp != NULL && temp->datum != datum)
        if (datum < temp->datum) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }
    return temp;
}

void BST::rem(int datum) {
    Node *searchNode = this->search(datum);
    
    if (!searchNode) {
        throw "Number not found";
    }
    Node *parent = searchNode->parent;
    
    if(!searchNode->left && !searchNode->right){
        if(!parent) {
            this->root = NULL;
        }
        
        else if (parent->datum < searchNode->datum) {
            parent->right = NULL;
        }
        
        else {
            parent->left = NULL;
        }
    }
    
    else if (!searchNode->left && searchNode->right) {
        if(!parent) {
            this->root = searchNode->right;
        }
        else if (parent->datum < searchNode->datum) {
            parent->right = searchNode->right;
        }
        
        else {
            parent->left = searchNode->right;
        }
        searchNode->right->parent = searchNode->parent;
    }
    
    else if (searchNode->left && !searchNode->right) {
        if(!parent) {
            this->root = searchNode->left;
        }
        else if (parent->datum < searchNode->datum) {
            parent->right = searchNode->left;
        }
        
        else {
            parent->left = searchNode->left;
        }
        searchNode->left->parent = searchNode->parent;
    }
    
    else {
        Node *temp = searchNode->left;
        
        while (temp->right) {
            temp = temp->right;
        }
        searchNode->datum = temp->datum;
        
        temp->parent->right = temp->left;
        searchNode = temp;
        if (temp->left) {
            temp->left->parent = temp->parent;
        }
    }
    delete searchNode;
}


int BST::get_parent(Node* node){
    int datum = node->parent->datum;
    return datum;
}

int BST::get_right_child(Node* node){
    int datum;
    if (node->right) {
        datum = node->right->datum;
    }
    else throw "No right child found";
    return datum;
}

int BST::get_left_child(Node *node){
    int datum;
    if (node->left) {
        datum = node->left->datum;
    }
    else throw "No left child found";
    return datum;
}
