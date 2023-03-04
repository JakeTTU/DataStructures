//
//  main.cpp
//  Graph
//
//  Created by Jake Gonzalez on 3/20/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <iostream>
#include "Graph.h"
using namespace std;

int main() {
    Graph *graph = new Graph ();
    
    graph->add_vert('A');
    graph->add_vert('B');
    graph->add_vert('C');
    graph->add_vert('D');
    
    graph->add_edge('A', 'B', 8);
    graph->add_edge('A', 'C', 22);
    graph->add_edge('B', 'C', 7);
    graph->add_edge('B', 'D', 15);
    graph->add_edge('B', 'A', 8);
    graph->add_edge('C', 'D', 18);
    graph->add_edge('C', 'B', 7);
    graph->add_edge('C', 'A', 22);
    graph->add_edge('D', 'B', 15);
    graph->add_edge('D', 'C', 18);
    
    graph->display();
    cout << endl;
    
    char src = 'A';
    cout << "Source Vertex:" << src << endl << endl;
    
    graph->unvisit();
    graph->dijkstra(src, src, 0);
    
    return 0;
}
