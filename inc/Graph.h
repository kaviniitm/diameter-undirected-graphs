#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
  private int numberOfVertices;
  private int numberOfEdges;
  private vector<vector<int>> adjList;

  public Graph(int numberOfVertices);
  private vector<set<int>> computeF(int u);
  public int iFUB(int u, int l, int k);
}

#endif
