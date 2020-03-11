# Graph
Graph Algorithms:

A class graph describes a graph (directed or undirected) which is defined by number of nodes, number of edges and  given by an adjacency list
as a vector of integers i.e. vestor< vector < int > >, as a privet element, Where each row represents the adjacencey list
of its corresponding node.

Each objcet (graph) can be initilized by one of the following constructors:
1. Number of nods -> Graph(int n); 
and then adding each edge [a,b] by the method -> add_Edge (int a , int b);
2. Given the Adj. List -> Graph(std::vector<std::vector<int>> list); (For dirgraph)

Methods are available till now:

1. Add an edge: void add_Edge (int a , int b);
2. Remove an edge: void remove_Edge(int a, int b);
3. Print the adjacent list of a node: void adjOfNode(int node);
4. Get the number of the edges: int getNumberOfEdges() const;
5. Get the degree of an edge in undirected graph: int degree(int v);
6. Calculate the Indegree of an edge in case of Digraph:  int InDegree(int v);
7. Find a conponant of a node (Reachable nodes): std::vector<int> reachable(int fromNodeX , int mark);
8. Find a Topological Sorting if exists or return an empty map otherwise: std::map<int, int> TopoSort();
9. Find an elementary cycle starting at some node V.
10. Find an Eulerian cycle if excites.
.
.

