//
//  main.cpp
//  Array List
//
//  Created by Jake Gonzalez on 1/30/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include "ArrayList.h"
#include <iostream>
using namespace std;

int main() {
    ArrayList myList;
    
    //print initial array
    cout << myList.print_list();
    
    //insert at an invaled index
    try {
    myList.insert(3, 1);
    }
    catch (const char *str) {
        cout << str << endl;
    }
    
    //insert at a valid index
    myList.insert(0, 1);
    cout << myList.print_list();
    
    //insert at the tail
    myList.insert(1, 2);
    cout << myList.print_list();
    
    //insett at the head
    myList.insert(0, 0);
    cout << myList.print_list();
    
    myList.insert(3, 3);
    cout << myList.print_list();
    
    //remove from the body
    cout << myList.rem(1) << endl;
    cout << myList.print_list();
    
    return 0;
}
