//
//  Priority Queue.hpp
//  Priority Queue
//
//  Created by Jake Gonzalez on 4/5/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#ifndef Priority_Queue_hpp
#define Priority_Queue_hpp

class PQueue {
    class Node{
    public:
        int priority;
        char lable;
        Node *next, *prev;
        Node (char lbl, int pr) {
            this->lable = lbl;
            this->priority = pr;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };
    Node *head, *tail;
    void destr_helper(Node *node) {
        if (node) {
            this->destr_helper(node->next);
            delete node;
        }
    }
public:
    PQueue() {
        this->head = nullptr;
        this->tail = nullptr;
    }
    ~PQueue() {
        this->destr_helper(this->head);
    }
    void push(char lable, int priority) {
        Node *newNode = new Node(label, priority);
        
        if(!this->head) {
            this->head = newNode;
            this->tail = newNode;
        }
        else {
            newNode->next = this->head;
            this->head->prev = newNode;
            this->head = newNode;
            node *temp = this->head;
            while (temp->next && temp->priority < temp->next->priority){
                temp->next->prev = temp->prev;
                if (temp->prev){
                    temp->prev->next = temp->next;
                }
                else {
                    this->head = temp->next;
                }
                temp->prev = temp->next;
                temp->next = temp->next->next;
                temp->prev->next = temp;
                if(temp->next){
                    temp->next->prev = temp;
                }
            }
            //may not need
            if (!temp->next) {
                this->tail = temp;
            }
        }
    }
    char pop(){
        Node *delNode = this->tail;
        char retVal = delNode->label;
        
        this->tail = this->tail prev;
        if(this->tail) {
            this->tail->next = nullptr;
        }
        else {
            this->head = nullptr;
        }
        
        delete delNode;
        return retVal;
    }
    void set_priority(char label, int priority) {
        Node *temp = this->head;
        for (;temp && temp->label != label; temp = temp->next);
        
        if (!temp) {
            throw "Label not found.\n";
        }
        
        temp->priority = priority;
        
        while (temp->next && temp->priority < temp->next->priority){
            temp->next->prev = temp->prev;
            if (temp->prev){
                temp->prev->next = temp->next;
            }
            else {
                this->head = temp->next;
            }
            temp->prev = temp->next;
            temp->next = temp->next->next;
            temp->prev->next = temp;
            if(temp->next){
                temp->next->prev = temp;
            }
        }
        
        if (!temp->next) {
            this->tail = temp;
        }
        
    }
};

#include <stdio.h>

#endif /* Priority_Queue_hpp */
