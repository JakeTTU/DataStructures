//
//  LinkedList.h
//  LinkedList
//
//  Created by Jake Gonzalez on 2/4/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h



class Node {
    int datum;
    Node *next, *prev;
public:
    Node(int);
    ~Node();
    int get_datum();
    void set_datum(int);
    Node* get_next();
    void set_next(Node*);
    Node* get_prev();
    void set_prev(Node*);
    
};


class LinkedList {
    int size;
    Node *head, *tail;
public:
    LinkedList();
    //LinkedList(int);
    ~LinkedList(); //deconsturctor
    void destr_helper(Node*);
    int get(int);
    void set(int, int);
    void insert(int, int);
    int rem(int);
    void print_list();
};
#endif /* LinkedList_h */
