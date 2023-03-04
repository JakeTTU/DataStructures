//
//  main.cpp
//  Graph
//
//  Created by Jake Gonzalez on 3/20/19.
//  Copyright © 2019 Jake Gonzalez. All rights reserved.
//

#include <iostream>
#include "Graph.h"

int main() {
    Graph *graph = new Graph ();
    graph->add_vert('0');
    graph->add_vert('1');
    graph->add_vert('2');
    graph->add_vert('3');
    
    graph->add_edge('1', '2');
    graph->add_edge('0', '1');
    graph->add_edge('0', '2');
    graph->add_edge('2', '0');
    graph->add_edge('2', '3');
    graph->add_edge('3', '3');
    
    graph->display();
    graph->DFT('2');
    graph->printVisited();
    
    return 0;
}
