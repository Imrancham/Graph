//
//  graph.hpp
//  Graph
//
//  Created by imran Chamieh on 25.02.20.
//  Copyright © 2020 imran Chamieh. All rights reserved.
//

#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
//#include "graph.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>

class Graph {
    
    
public:
//    Constructors
    Graph(int n);
    Graph(std::vector<std::vector<int>> list);
    
    
//    Functions
//    Add an Edge
    void add_Edge (int a , int b);
    
//  Print the neighbors of a node.
    void adjOfNode(int node);
    
//    Remove an Edge.
    void remove_Edge(int a, int b);
    
//  Get number of the dege in the graph
    int getNumberOfEdges() const;
    
//    Degree of a node.
    int degree(int v);
    
//    In Degree Of a Vertex.
    int InDegree(int v);
    
//      Componant of a node. E_G(v)
    std::vector<int> reachable(int fromNodeX , int mark);
    
//    Topological sorting
    //
    std::map<int, int> TopoSort();
   
//    Findding Elementary cycle start at vertex v in a digraph.
    std::vector<int> explorCycleAtV( int vertex , std::vector<int>::const_iterator current[] );
    
//    Find an Eulerian Cycle in a digraph.
    std::vector<int> Euler();
    
private:
    int numberOfVertices;
    int numberOfEdges;
    std::vector<std::vector<int>> adjList;
    
};




#endif /* graph_hpp */
