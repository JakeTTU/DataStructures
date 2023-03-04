//
//  main.cpp
//  Binary Search Tree
//
//  Created by Jake Gonzalez on 2/28/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    BST *lab6 = new BST();
    
    lab6->insert(15);
    lab6->insert(10);
    lab6->insert(20);
    lab6->insert(8);
    lab6->insert(12);
    lab6->insert(18);
    lab6->insert(25);
    lab6->insert(16);
    lab6->insert(19);
    lab6->insert(30);
    
    int num = 25;
    int num2 = 30;
    int num3 = 20;

    if (lab6->search(num)) {
        cout << num;
        cout << " found at: ";
        cout << lab6->search(num) << endl;
    }
    else cout << "int not found" << endl;
    
    cout << "Parent: ";
    cout << lab6->get_parent(lab6->search(num)) << endl;
    
    cout << "Right child: ";
    try {
        cout << lab6->get_right_child(lab6->search(num)) << endl;
    }
    catch (const char *str) {
        cout << str << endl;
    }
    cout << "Left child: ";
    try {
        cout << lab6->get_left_child(lab6->search(num)) << endl;
    }
    catch (const char *str) {
        cout << str << endl;
    }

    cout << endl;
    cout << "Removing ";
    cout << num << endl;
    lab6->rem(num);
    cout << endl;
    
    
    if (lab6->search(num2)) {
        cout << num2;
        cout << " found at: ";
        cout << lab6->search(num2) << endl;
    }
    else cout << "int not found" << endl;
    
    cout << "Parent: ";
    cout << lab6->get_parent(lab6->search(num2)) << endl;
    
    cout << "Right child: ";
    try {
        cout << lab6->get_right_child(lab6->search(num2)) << endl;
    }
    catch (const char *str) {
        cout << str << endl;
    }
    cout << "Left child: ";
    try {
        cout << lab6->get_left_child(lab6->search(num2)) << endl;
    }
    catch (const char *str) {
        cout << str << endl;
    }
    cout << endl;
    
    
  
    if (lab6->search(num3)) {
        cout << num3;
        cout << " found at: ";
        cout << lab6->search(num3) << endl;
    }
    else cout << "int not found" << endl;
    
    cout << "Parent: ";
    cout << lab6->get_parent(lab6->search(num3)) << endl;
    
    cout << "Right child: ";
    try {
        cout << lab6->get_right_child(lab6->search(num3)) << endl;
    }
    catch (const char *str) {
        cout << str << endl;
    }
    cout << "Left child: ";
    try {
        cout << lab6->get_left_child(lab6->search(num3)) << endl;
    }
    catch (const char *str) {
        cout << str << endl;
    }
    
    return 0;
}

