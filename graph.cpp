//
//  graph.cpp
//  Graph
//
//  Created by imran Chamieh on 25.02.20.
//  Copyright © 2020 imran Chamieh. All rights reserved.
//


#include <iostream>
#include <vector>
#include <map>
#include "graph.hpp"



 Graph::Graph(int n): numberOfVertices(n), numberOfEdges (0), adjList(n){};
    
 Graph::Graph(std::vector<std::vector<int>> list){
        adjList = list;
        int n = 0;
        for ( auto i = list.begin(); i != list.end(); i++)
        {
            n++;
        }
        numberOfVertices = n;
        
        int degreeSum = 0;
        for ( int i =0; i<n; i++){
            degreeSum += this->degree(i);
        }

            numberOfEdges = degreeSum/2 ;

    }
    
//    Add an Edge [a,b]
    void Graph::add_Edge (int a , int b)
    {
        if (a==b)adjList[a].push_back(b);
        else
        {
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        ++numberOfEdges;
        
    }

//  Get number of the edges;
int Graph::getNumberOfEdges() const {return numberOfEdges ;}

//  Print the neighbors of a node.
    void Graph::adjOfNode(int node){
        std::cout<<node<<"->";
        for (auto & x : adjList[node]){
            std::cout<<x<< " ";
        }
    }
    
//   Remove an Edge.
    void Graph::remove_Edge(int a, int b)
    {

        if(a==b)
            for(auto i = adjList[a].begin(); i != adjList[a].end(); i++)
            {
                if (*i == b) {
                    adjList[a].erase(i);
                    i--;
                }
            }
        
        else
        {
            for(auto i = adjList[a].begin(); i != adjList[a].end(); i++){
                if (*i == b) {
                    adjList[a].erase(i);
                    i--;
                }
            }
            for(auto i = adjList[b].begin(); i != adjList[b].end(); i++)
            {
                if (*i == a) {
                    adjList[b].erase(i);
                    i--;
                   }
            }
        }
        numberOfEdges--;
    }
//    Degree of a node.
    int Graph::degree(int v)
    {
        int degree =0 ;
        for (auto i = adjList[v].begin(); i!= adjList[v].end() ; i++){
            degree += (*i == v) ? 2 : 1;
        }
            
    
        return degree;
    }
    
//    In Degree Of a Vertex.
    int Graph::InDegree(int v)
    {
        int degree = 0;
        std::vector<std::vector<int>>::iterator row;
        std::vector<int>::iterator cal;
        for (row = adjList.begin(); row < adjList.end() ; row++)
        {
            for (cal = row->begin(); cal < row->end(); cal++)
            {
                if(*cal == v) degree++;
            }
        }
        return degree;
    }
    
    
//      Componant of a node. E_G(v)
    std::vector<int> Graph::reachable(int fromNodeX , int mark)
    {
        std::vector<int> reached;
        std::vector<int> L;
        
        int* marked = new int[numberOfVertices];
        marked[fromNodeX] = mark;
        L.push_back(fromNodeX);
        reached.push_back(fromNodeX);
        while (!L.empty()) {
            int x = L.at(0);
            std::vector<int>::iterator it;
            it = L.begin();
            L.erase(it);
            for (auto i =adjList[x].begin(); i!= adjList[x].end() ; i++)
            {
                if(marked[*i] != mark)
                {
                    marked[*i] = mark;
                    L.push_back(*i);
                    reached.push_back(*i);
                }
            }
            
        }
        
        return reached;
    }
    
//    Topological sorting
//
    std::map<int, int> Graph::TopoSort()
    {
        std::map<int,int> sorting;
        std::map<int, int> sort; // Empty map in case no T.P exists.
        std::map<int, int> inDegree; // save in Degree for all vertices.
        std::vector<int> L; // all vertices with 0 inDegree
        std::vector<int>::iterator iter; // refer to the beginning of L
        
//        Comput inDegree of all vertices
        for (int i =0; i< numberOfVertices; ++i)
        {
            inDegree.emplace(i, InDegree(i));
            if(InDegree(i)==0) L.push_back(i);
        }
        
        if(L.empty())
        {
            std::cout<<"ther is no T.S.";
            return sort;
        }
        
        
       
//        Start sorting
        for(int i =0 ; i<numberOfVertices; ++i)
        {
            sorting.insert( std::make_pair(L[0], i) );
            if (i+1 == numberOfVertices) return sorting;
            iter = L.begin();
            int k = *iter;
            L.erase(iter);
//            Update inDegree for each adjacent node
            for (auto j = adjList[k].begin(); j!= adjList[k].end(); j++)
            {
                inDegree[*j]--;
                if(inDegree[*j] == 0)
                    L.push_back(*j);
            }
            
            if(L.empty())
            {
                std::cout<<"ther is no T.S.";
                return sort;
            }
            
        }
        return sorting;
        
    }


//    Findding Elementary cycle start at vertex v.
std::vector<int> Graph::explorCycleAtV( int vertex ,std::vector<int>::const_iterator current[] )
{
    std::vector<int> cycle;
//    std::vector<int>::const_iterator current[numberOfVertices];
//
//    for ( int i = 0 ; i < numberOfVertices ; i++)
//    {
//        current[i] = adjList[i].begin();
//    }
    
    int u = *current[vertex];
    current[vertex]++;
    
    cycle.push_back(vertex);
    cycle.push_back(u);
    
    while (u != vertex) {
        int w = *current[u];
        current[u]++;
        cycle.push_back(w);
        u = w;
    }
    
    return cycle;
}

std::vector<int> Graph::Euler()
{
    std::vector<int> EulerCycle;
//    EulerCycle.push_back(0);
    std::vector<int> cycle;
    std::vector<int>::const_iterator current[numberOfVertices];
//    std::vector<int>::iterator iter = EulerCycle.begin();
    
    for ( int i = 0 ; i < numberOfVertices ; i++)
    {
        current[i] = adjList[i].begin();
    }
    
    int v = 0;
    int i =0;
    do {
        while (current[v] != adjList[v].end() )
        {
            cycle = explorCycleAtV(v, current);
//            EulerCycle.pop_back();            
            EulerCycle.insert( EulerCycle.end(), cycle.begin(), cycle.end() );
        }
        i++;
        v= EulerCycle[i];
    } while (v!=0);
    
    return EulerCycle;
}
