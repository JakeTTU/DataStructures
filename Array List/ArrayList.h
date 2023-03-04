//
//  ArrayList.h
//  Array List
//
//  Created by Jake Gonzalez on 1/30/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#ifndef ArrayList_h
#define ArrayList_h
#include <string>

class ArrayList {
    int size, numel, *arr;
public:
    ArrayList();
    ArrayList(int);
    ~ArrayList(); //deconsturctor
    int get(int);
    void set(int, int);
    void insert(int, int);
    int rem(int);
    std::string print_list();
    
    
};

#endif /* ArrayList_h */
