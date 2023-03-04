//
//  main.cpp
//  Binary Search Tree
//
//  Created by Jake Gonzalez on 2/25/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    BST *lab5 = new BST();
    
    lab5->insert(16);
    lab5->insert(11);
    lab5->insert(21);
    lab5->insert(23);
    lab5->insert(10);
    lab5->insert(13);
    
    if (lab5->search(21)) {
        cout << "21 found at: ";
        cout << lab5->search(21) << endl;
    }
    else cout << "int not found" << endl;
    
    cout << "Parent of 21: ";
    cout << lab5->get_parent(lab5->search(21)) << endl;
    
    cout << "Right child of 21: ";
    try {
        cout << lab5->get_right_child(lab5->search(21)) << endl;
    }
    catch (const char *str) {
        cout << str << endl;
    }
    cout << "Left child of 21: ";
    try {
        cout << lab5->get_left_child(lab5->search(21)) << endl;
    }
    catch (const char *str) {
        cout << str << endl;
    }
    
    if (lab5->search(10)) {
        cout << "10 found at: ";
        cout << lab5->search(10) << endl;
    }
    else cout << "int not found" << endl;
    
    cout << "Parent of 10: ";
    cout << lab5->get_parent(lab5->search(10)) << endl;
    
    cout << "Right child of 10: ";
    try {
        cout << lab5->get_right_child(lab5->search(10)) << endl;
    }
    catch (const char *str) {
        cout << str << endl;
    }
    cout << "Left child of 10: ";
    try {
        cout << lab5->get_left_child(lab5->search(10)) << endl;
    }
    catch (const char *str) {
        cout << str << endl;
    }
    
    return 0;
}

