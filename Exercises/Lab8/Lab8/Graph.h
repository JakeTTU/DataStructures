//
//  Header.h
//  Graph
//
//  Created by Jake Gonzalez on 3/20/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#ifndef Header_h
#define Header_h

class Graph{
    class Edge;
    
    class Vertex {
    public:
        char label;
        Vertex *next;
        Edge *edgeList;
	    bool visited;
        void destr_helper(Edge *edge) {
            if (edge) {
                this->destr_helper(edge->next);
                delete edge;
            }
        }
        Vertex(char label) {
            this->label = label;
            this->next = 0;
            this->edgeList = 0;
	        this->visited = false;
        }
        ~Vertex() {
            this->destr_helper(this->edgeList);
        }
    };
    
    class Edge{
    public:
        Vertex *to;
        Edge *next;
        int weight;
        Edge(Vertex *to) {
            this->to = to;
            this->next = 0;
            this->weight = 0;
        };
    };

    Vertex *vertList, *visited, *stack;
    void destr_helper(Vertex*);
    
public:
    Graph(){
        this->vertList = 0;
        this->visited = 0;
        this->stack = 0;
    };
    ~Graph();
    bool add_vert(char);
    bool rem_vert(char);
    bool add_edge(char, char);
    bool rem_edge(char, char);
    void DFT(char);
    void stack_push(Vertex*);
    void visit(Vertex*);
    void display();
    void printVisited();
};

#endif /* Header_h */
