//
//  main.cpp
//  Graph
//
//This file is to class  graph and algorimths consist of:
// Defining a graph in adjecincy list.
// Graph algo:
// 1.1 degree. & InDegree done
// 1.2 Componant of a graph. Done
// 1.3 Finding a Topological Sorting Digraph. Done
// 1.4 Cycle of unused Edge
// 1.5 Finding Eulerian Cycle.
//
// 2.1 Simple sequintial Coloring Algorithm
// 2.2 Check perfect elimination scheme.
// 2.3 Approximation Algo for Determining a Vertex Cove.
// 2.4 2-approx Algo for The p-center Problem.
//
// 3.1 Approx Algo For Min-Kernel.
//
// 4.1 finding a S-rooted Spanning tree.
// 4.2 Finding a Min-Weight S-rooted Spanning tree.
// 4.3 Finding a Min Max Ind Set.
// 4.4 Approx Algo for MinDegSPT.
//
// 5.1 DepthFirst Search.
// 5.2 DFS Exploring of a single vertex.
// 5.3 Computation of strongly connected component.
// 5.4 Lexikographische Breadth First Search.
//
// 7.1 Finding Perfect Matching in a Bipertite Graph.
// 7.2 Shrinking an Odd Cycle.
// 7.3 Finding a P.M in a general graph.
// 7.4 Computing a Min Weight P.M. in Bip. Graph.
// 7.5 Srinking a odd cycle, to update the matching alternating tree and the weights.
// 7.6 Change the Dual variable in athe prefect matching algo for general graph
// 7.8 Expan a supernodeand update the matching, alternating tree and weights.
// 7.9 Blossom Algo for Computing a Min-Weight P.M .

//  Created by imran Chamieh on 20.02.20.
//  Copyright © 2020 imran Chamieh. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "graph.hpp"


int main(int argc, const char * argv[]) {
   
// Test cases G , G2, G3, G4 are different graphs;
    
    
    std::vector<std::vector<int>> list = {{1,2,0},{0}, {0,2},{}};
    std::vector<std::vector<int>> list2 = {{1}, {2,3}, {}, {2}};
    std::vector<std::vector<int>> list3 = {{1,2}, {3,4}, {5,6}, {7,8}, {9,10}, {11,12}, {13,14}, {}, {}, {}, {}, {} ,{}, {}, {}};
    std::vector<std::vector<int>> list4 = {{1}, {2}, {3}};
    Graph G(list);
    Graph G2(list2);
    Graph G3(list3);
    Graph G4(list4);
    
    int numOfNodes = 4;
    Graph G1(numOfNodes);
//     Defining the edges.
    G1.add_Edge(1, 2);
    G1.add_Edge(2, 3);
    G1.add_Edge(3, 1);
    G1.add_Edge(0, 3);
    G1.add_Edge(3, 3);

    
    std::cout<<"Number of Edges in G1 is: "<<G1.getNumberOfEdges()<<std::endl;
    std::cout<<"print the nodes which are adjacent to (3) in G1"<<std::endl;
    G1.adjOfNode(3);
     std::cout<<std::endl;
    
    std::cout<<"In G1 degree of (3) is: "<< G1.degree(3)<<std::endl;
    
    std::cout<<"print the nodes which are adjacent to (0) in G1"<<std::endl;
    G1.adjOfNode(0);
    std::cout<<std::endl;
    
//    G.remove_Edge(3, 0);
    std::cout<<"print the nodes which are adjacent to (3) in G "<<std::endl;
    G.adjOfNode(3);
    std::cout<<"In G degree of  3 is: "<< G.degree(3)<<std::endl;
    std::cout<<std::endl;
    std::cout<<"print the nodes which are adjacent to (0) in G "<<std::endl;
    G1.adjOfNode(0);
    
    std::cout<<std::endl;
    std::cout<<"Number of Edges in G is: "<<G.getNumberOfEdges()<<std::endl;
    
    std::cout<<"In G Nodes which are Reachable from x ->";
    std::vector<int> reachable = G.reachable(2, 9);
    
    for(auto i = reachable.begin(); i!= reachable.end(); i++)
    {
        std::cout<<*i;
    }
    std::cout<<std::endl;
//    ///////////////
//     toptogical sotring 
    std::map<int,int> sort1 = G1.TopoSort();
    std::cout<<"Toplogical sorting of G1"<<std::endl;
    
    for(auto iter = sort1.begin(); iter!= sort1.end(); iter++)
    {
        std::cout<<iter->first << " "<<iter->second<<'\n';
    }
//    //    ///////////////
    std::map<int,int> sort2 = G2.TopoSort();
    std::cout<<"Toplogical sorting of G2"<<std::endl;
    
    for(auto iter = sort2.begin(); iter!= sort2.end(); iter++)
    {
        std::cout<<iter->first << " "<<iter->second<<'\n';
    }
    //    ///////////////
    std::map<int,int> sort3 = G3.TopoSort();
    std::cout<<"Toplogical sorting of G3"<<std::endl;
    for(auto iter = sort3.begin(); iter!= sort3.end(); iter++)
       {
           std::cout<<iter->first << " "<<iter->second<<'\n';
       }

  std::cout<<std::endl;
    return 0;
}
