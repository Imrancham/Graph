# Graph
Graph Algorithms:

A class graph describes a graph (directed or undirected) which is defined by number of nodes, number of edges and  given by an adjacency list
as a vector of integers i.e. vestor< vector < int > >, Where each row represents the adjacencey list
of its corresponding node.

Each objcet (graph) can be initilized by one of the following constructors:
1. Number of nods -> Graph(int n); 
and then adding each edge [a,b] by the method -> add_Edge (int a , int b);
2. Given the Adj. List -> Graph(std::vector<std::vector<int>> list); (For dirgraph)

Functions:

1. Add an edge: void add_Edge (int a , int b);
2. Remove an edge: void remove_Edge(int a, int b);
3. Print the adjacent list of a node: void adjOfNode(int node);
4. Get the number of the edges: int getNumberOfEdges() const;

1.1 degree. & InDegree...................................Done
1.2 Componant of a graph................................ Done
1.3 Finding a Topological Sorting Digraph............... Done
1.4 Cycle of unused Edge................................ Done
1.5 Finding Eulerian Cycle.............................. Done

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

.

