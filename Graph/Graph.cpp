//
//  Graph.cpp
//  Graph
//
//  Created by Jake Gonzalez on 3/20/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <stdio.h>
#include "Graph.h"
#include <iostream>

using namespace std;

void Graph::destr_helper(Vertex* vert){
    if (vert) {
        this->destr_helper(vert->next);
        delete vert;
    }
}

Graph::~Graph() {
    this->destr_helper(this->vertList);
}


bool Graph::add_vert(char label) {
    for (Vertex *tempVert = this->vertList; tempVert; tempVert = tempVert->next) {
        if (tempVert->label == label) {
            return false;
        }
    }
    
    Vertex *newNode = new Vertex(label);
    newNode->next = this->vertList;
    this->vertList = newNode;
    return true;
}

bool Graph::rem_vert(char label) {
    Vertex *delVert = nullptr, *prevVert = nullptr;
    for (Vertex *tempVert = this->vertList; tempVert; tempVert = tempVert->next) {
        if (tempVert->label != label) {
            for (Edge *tempEdge = tempVert->edgeList; tempEdge; tempEdge = tempEdge->next) {
                if (tempEdge->to->label == label) {
                    return false;
                }
            }
            if (tempVert->next && tempVert->next->label == label) {
                prevVert = tempVert;
            }
        }
        else {
            delVert = tempVert;
        }
    }
    
    if (delVert) {
        if(prevVert) {
            prevVert->next = delVert->next;
        }
        else {
            this->vertList = delVert->next;
        }
        delete delVert;
        return true;
    }
    else {
        return false;
    }
}

bool Graph::add_edge(char from, char to, int weight) {
    Vertex *tempVert, *fromVert = nullptr, *toVert = nullptr;
    
    for (tempVert = this->vertList; tempVert; tempVert = tempVert->next) {
        if (tempVert->label == from) {
            fromVert = tempVert;
        }
        if (tempVert->label == to) {
            toVert = tempVert;
        }
    }
    
    if (!fromVert || !toVert) {
        return false;
    }
    
    Edge *newEdge = new Edge(toVert, weight);
    newEdge->next = fromVert->edgeList;
    fromVert->edgeList = newEdge;
    return true;
}

bool Graph::rem_edge(char from, char to) {
    Vertex *vert;
    Edge *edge, *prev = nullptr;
    
    for (vert = this->vertList; vert; vert->next) {
        if (vert->label == from) {
            break;
        }
    }
    
    if (!vert) {
        return false;
    }
    
    for (edge = vert->edgeList; edge; edge = edge->next) {
        if (edge->next && edge->to->label == to) {
            prev = edge;
        }
        if (edge->to->label == to) {
            break;
        }
    }
    
    if (edge) {
        if (!prev) {
            vert->edgeList = edge->next;
        }
        else {
            prev->next = edge->next;
        }
        delete edge;
        return true;
    }
    else {
        return false;
    }
}

void Graph::DFT(char source){
    Vertex *temp = this->vertList;
    for (; temp && temp->label != source; temp = temp->next) {
    }
    
    if (temp){
        stack_push(temp);
    }
    else{
        return;
    }
    
    while (stack) {
        //pop the stack
        temp = stack;
        stack = stack->next;
        temp->next = this->visited;
        
        this->visited = temp;
        Edge *eTemp = temp->edgeList;
        for(;eTemp; eTemp = eTemp->next) {
            if (!eTemp->to->visited) {
                stack_push(eTemp->to);
            }
        }
        if (!this->stack && this->vertList) {
            stack_push(this->vertList);
        }
    }
    
    this->visit(this->visited);
    this->vertList = this->visited;
    this->visited = 0;
    for (temp = this->vertList; temp; temp = temp->next) {
        temp->visited = false;
    }
}

void Graph::stack_push(Vertex *pushNode){
    Vertex *prev = 0, *temp = this->vertList;
    pushNode->visited = true;
    for (; temp && temp != pushNode; temp = temp->next) {
        prev = temp;
    }
    
    if(prev) {
        prev->next = temp->next;
    }
    else {
        this->vertList = this->vertList->next;
    }
    temp->next = stack;
    stack = temp;
}

void Graph::visit(Vertex *vert) {
    if (vert) {
        this->visit(vert->next);
        cout << vert->label << endl;
    }
}

void Graph::display(){
    for(Vertex *vert = this->vertList; vert; vert = vert->next) {
        cout << vert->label << " -> ";
        if (vert->edgeList) {
            cout << vert->edgeList->to->label;
            for (Edge *edge = vert->edgeList->next; edge; edge = edge->next) {
                cout << ", " << edge->to->label;
            }
        }
        cout << endl;
    }
}

void Graph::display_edges(char find){
    for(Vertex *vert = this->vertList; vert; vert = vert->next){
        if (vert->label == find) {
            cout << vert->edgeList->to->label;
            for (Edge *edge = vert->edgeList->next; edge; edge = edge->next) {
                cout << ", " << edge->to->label;
            }
        }
    }
    cout << endl;
}

char Graph::shortest_path(char scr, int dist){
    int new_distance = 0, v2_distance = 0;
    int v1_distance = dist;
    for (Vertex *vert = this->vertList; vert; vert = vert->next) {
        if (vert->label == scr) {
            new_distance = v1_distance + v2_distance;
            for (Edge *edge = vert->edgeList; edge; edge = edge->next) {
                new_distance = v1_distance + edge->weight;
                if (new_distance < edge->weight) {
                    new_distance = edge->weight;
                }
                cout << edge->to->label;
                cout << " ";
                cout << edge->weight << endl;
            }
            cout << new_distance << endl;
            for (Edge *edge = vert->edgeList; edge; edge = edge->next) {
                if (edge->weight == new_distance) {
                    cout << "Nearest node is ";
                    cout << edge->to->label;
                    cout << " at a distance of ";
                    cout << new_distance << endl;
                    return edge->to->label;
                }
            }
        }
    }
return NULL;
}
tem

