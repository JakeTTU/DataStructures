//
//  BST.h
//  Binary Search Tree
//
//  Created by Jake Gonzalez on 2/28/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#ifndef BST_h
#define BST_h

class Node {
public:
    int datum;
    Node *left, *right, *parent;
    Node(int);
};

class BST {
    Node *root;
    void dest_helper(Node *);
public:
    BST();
    ~BST();
    int get_parent(Node *);
    int get_right_child(Node *);
    int get_left_child(Node *);
    void insert(int);
    void rem(int);
    Node* search(int);
};


#endif /* BST_h */
