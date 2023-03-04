//
//  main.cpp
//  LinkedList
//
//  Created by Jake Gonzalez on 2/11/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"
using namespace::std;

int main() {
    LinkedList *myList = new LinkedList;
    
    myList->print_list();
    myList->insert(0, 1);
    myList->print_list();
    myList->insert(1, 5);
    myList->print_list();
    myList->insert(2, 2);
    myList->print_list();
    myList->insert(3, 3);
    myList->print_list();
    myList->insert(4, 4);
    myList->print_list();
    myList->print_list_rev();
 
    //Doubly linked lists is a list of nodes that stores data, pointer to successor, and pointer to predecessor.
    //One advantage of doubly linked list is the nodes store both pointers to successors and predecessors. This allows us to add and delete from both the head and tail, and search for elements from either the head or tail.
    
    return 0;
}
