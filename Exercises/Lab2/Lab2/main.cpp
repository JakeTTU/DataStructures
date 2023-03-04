//
//  main.cpp
//  Lab2
//
//  Created by Jake Gonzalez on 2/6/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"
using namespace::std;

int main() {
    LinkedList *labList = new LinkedList;
    
    labList->insert(0, 1);
    labList->insert(1, 5);
    labList->insert(2, 2);
    labList->insert(3, 3);
    labList->insert(4, 4);
    labList->print_list();
    labList->print_list_rev();
    
    cout << labList->rem(0) << " was removed." << endl;
    labList->print_list();
    return 0;
}
