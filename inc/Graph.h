#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <set>
#include <queue>

using namespace std;

class Graph {
  int numberOfVertices;
  int numberOfEdges;
  vector< vector<int> > adjList;

  int computeEccentricity(int u);
  vector< set<int> > computeF(int u);
  int computeMaxEccentricity(set<int> vertices);

  public:
  Graph(int numberOfVertices);
  int iFUB(int u, int l, int k);
};

#endif
