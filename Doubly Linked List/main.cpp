//
//  main.cpp
//  LinkedList
//
//  Created by Jake Gonzalez on 2/4/19.
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
    
    cout << myList->rem(0) << " was removed." <<endl;
    myList->print_list();
    
    try {
        myList->insert(25, 26);
    }
    catch (const char *msg) {
        cout << msg << endl;
    }
    
    return 0;
}
