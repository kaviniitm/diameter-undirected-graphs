# diameter-undirected-graphs

## Synopsis

This C++ project finds the diameter given an undirected unweighted graph.

## Code Example
```
Graph graph(8); //Creates a graph object of 8 vertices (vertices are numbered from 0 to 7)
graph.addEdge(0, 1); //Adds an undirected edge from vertex 0 to vertex 1
graph.addEdge(0, 7);
graph.addEdge(1, 2);
graph.addEdge(1, 7);
graph.addEdge(2, 3);
graph.addEdge(2, 5);
graph.addEdge(3, 4);
graph.addEdge(3, 5);
graph.addEdge(4, 5);
graph.addEdge(5, 6);
graph.addEdge(6, 7);
pair<int,int> lowerBoundVertexPair = graph.fourSweep(); // Initial lower bound and inital vertex
graph.iFUB(lowerBoundVertexPair.second, lowerBoundVertexPair.first, 0); // Returns the diameter of the graph
```
## Motivation

The Naive algorithm for finding the diameter of an undirected unweighted graph takes **O(nm)** time where n is the number of vertices in the given graph and m is the number of edges in the given graph. The Naive algorithm finds out the eccentricity of all vertices and diameter is the maximum of all eccentricities.

This algorithm finds out the diameter of the graph by initially starting with an upped bound and lower bound for it. And in each step this bound is brought closer to find out the exact diameter. Starting from one vertex, at each step the lower bound is updated by computing the eccentricities of vertices at a distance i from u and the upper bound is decreased by 2.
Even though the worst case Time Complexity is O(nm), in practice the algorithm runs in **O(m)** time.

## Installation

Clone the project into a directory.<br />
Run make<br />

## Tests

Run ./bin/main "DataSetFile" <br />

The input form of the dataset is, <br />
"numberOfVertices" "numberOfEdges" <br />
"Vertex1" "Vertex2" //Denotes that there is an undirected edge between Vertex1 and Vertex2 <br />
"Vertex3" "Vertex4" <br />
.
.


Outputs the value of the diameter.

## Contributors

Implemented the algorithm from the paper, <br />
On computing the diameter of real-world undirected graphs <br />
(Pilu Crescenzi, Roberto Grossi, Michel Habib, Leonardo Lanzi, Andrea Marino)<br />
http://www.sciencedirect.com/science/article/pii/S0304397512008687
