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

//template<typename T>

//// Define a graph class/
//class Graph {
//
//private:
//    int numberOfVertices;
//    int numberOfEdges;
//    std::vector<std::vector<int>> adjList;
//
//public:
////    Constructors
//    Graph(int n): numberOfVertices(n), numberOfEdges (0), adjList(n){};
//
//    Graph(std::vector<std::vector<int>> list){
//        adjList = list;
//        int n = 0;
//        for ( auto i = list.begin(); i != list.end(); i++)
//        {
//            n++;
//        }
//        numberOfVertices = n;
//
//        int degreeSum = 0;
//        for ( int i =0; i<n; i++){
//            degreeSum += this->degree(i);
//        }
//
//            numberOfEdges = degreeSum/2 ;
//
//    }
//
////    Add an Edge [a,b]
//    void add_Edge (int a , int b)
//    {
//        if (a==b)adjList[a].push_back(b);
//        else
//        {
//            adjList[a].push_back(b);
//            adjList[b].push_back(a);
//        }
//        ++numberOfEdges;
//
//    }
//
////
//
//    int getNumberOfEdges() const {return numberOfEdges;}
//
////Print the neighbors of a node.
//    void adjOfNode(int node){
//        std::cout<<node<<"->";
//        for (auto & x : adjList[node]){
//            std::cout<<x<< " ";
//        }
//    }
//
////   Remove an Edge.
//    void remove_Edge(int a, int b)
//    {
//
//        if(a==b)
//            for(auto i = adjList[a].begin(); i != adjList[a].end(); i++)
//            {
//                if (*i == b) {
//                    adjList[a].erase(i);
//                    i--;
//                }
//            }
//
//        else
//        {
//            for(auto i = adjList[a].begin(); i != adjList[a].end(); i++){
//                if (*i == b) {
//                    adjList[a].erase(i);
//                    i--;
//                }
//            }
//            for(auto i = adjList[b].begin(); i != adjList[b].end(); i++)
//            {
//                if (*i == a) {
//                    adjList[b].erase(i);
//                    i--;
//                   }
//            }
//        }
//        numberOfEdges--;
//    }
////    Degree of a node.
//    int degree(int v)
//    {
//        int degree =0 ;
//        for (auto i = adjList[v].begin(); i!= adjList[v].end() ; i++){
//            degree += (*i == v) ? 2 : 1;
//        }
//
//
//        return degree;
//    }
//
////    In Degree Of a Vertex.
//    int InDegree(int v)
//    {
//        int degree = 0;
//        std::vector<std::vector<int>>::iterator row;
//        std::vector<int>::iterator cal;
//        for (row = adjList.begin(); row < adjList.end() ; row++)
//        {
//            for (cal = row->begin(); cal < row->end(); cal++)
//            {
//                if(*cal == v) degree++;
//            }
//        }
//        return degree;
//    }
//
//
////      Componant of a node. E_G(v)
//    std::vector<int> reachable(int fromNodeX , int mark)
//    {
//        std::vector<int> reached;
//        std::vector<int> L;
//
//        int* marked = new int[numberOfVertices];
//        marked[fromNodeX] = mark;
//        L.push_back(fromNodeX);
//        reached.push_back(fromNodeX);
//        while (!L.empty()) {
//            int x = L.at(0);
//            std::vector<int>::iterator it;
//            it = L.begin();
//            L.erase(it);
//            for (auto i =adjList[x].begin(); i!= adjList[x].end() ; i++)
//            {
//                if(marked[*i] != mark)
//                {
//                    marked[*i] = mark;
//                    L.push_back(*i);
//                    reached.push_back(*i);
//                }
//            }
//
//        }
//
//        return reached;
//    }
//
////    Topological sorting
////
//    std::map<int, int> TopoSort()
//    {
//        std::map<int,int> sorting;
//        std::map<int, int> sort;
//        std::map<int, int> inDegree;
//        std::vector<int> L;
//        for (auto i =0; i< numberOfVertices; ++i)
//        {
//            inDegree.emplace(i, InDegree(i));
//            if(InDegree(i)==0) L.push_back(i);
//        }
//        std::vector<int>::iterator iter;
//        iter = L.begin();
//        for(int i =0 ; i<numberOfVertices; i++)
//        {
//            sorting.emplace(L[0], i);
//            if (i+1 == numberOfVertices) return sorting;
//            int k = *iter;
//            L.erase(iter);
//
//
//            for (auto j = adjList[k].begin(); j!= adjList[k].end(); j++)
//            {
//                inDegree[*j]--;
//                if(inDegree[*j] == 0)
//                    L.push_back(*j);
//            }
//            if(L.empty())
//            {
//                std::cout<<"ther is no T.S.";
//                return sort;
//            }
//
//        }
//        return sorting;
//
//    }
//
//};


int main(int argc, const char * argv[]) {
    // insert code here...
//  G , G2, G3 different graphs;
    
    int x = 4;
    Graph G1(x);
    G1.add_Edge(1, 2);
    G1.add_Edge(2, 3);
    G1.add_Edge(3, 1);
    G1.add_Edge(0, 3);
    G1.add_Edge(3, 3);
//    G1.add_Edge(3, 4);
    
    std::vector<std::vector<int>> list = {{1,2,0},{0}, {0,2},{}};
    Graph G(list);
    
    std::vector<std::vector<int>> list2 = {{1}, {2,3}, {}, {2}};
    Graph G2(list2);
    
    std::vector<std::vector<int>> list3 = {{1,2}, {3,4}, {5,6}, {7,8}, {9,10}, {11,12}, {13,14}, {}, {}, {}, {}, {} ,{}, {}, {}};
    Graph G3(list3);
    
    std::vector<std::vector<int>> list4 = {{1}, {2}, {3}};
    Graph G4(list4);
    

    
    
    std::cout<<G1.getNumberOfEdges()<<'\n';
    G1.adjOfNode(3);
     std::cout<<'\n';
    
    std::cout<<"degree of "<< 3 <<" is: "<< G1.degree(3)<<std::endl;
    
    G1.adjOfNode(0);
    std::cout<<'\n';
    
//    G.remove_Edge(3, 0);
    G.adjOfNode(3);
    std::cout<<"degree of "<< 3 <<"is: "<< G1.degree(3)<<std::endl;
    std::cout<<'\n';
    G1.adjOfNode(0);
    
    std::cout<<'\n';
    std::cout<<G.getNumberOfEdges()<<'\n';
    std::cout<<"Nodes are Reachable from x ->";
    std::vector<int> reachable = G.reachable(2, 9);
    for(auto i = reachable.begin(); i!= reachable.end(); i++)
    {
        std::cout<<*i;
    }
    std::cout<<std::endl;
//    ///////////////
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
