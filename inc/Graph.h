#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <set>
#include <queue>
#include <utility>

using namespace std;

class Graph {
  int numberOfVertices;
  int numberOfEdges;
  vector< vector<int> > adjList;

  vector<int> getDistanceFromU(int u);
  int computeEccentricity(int u);
  vector< set<int> > computeF(int u);
  int computeMaxEccentricity(set<int> vertices);
  int getVertexWithMaximumDegree();
  int maxDistantVertex(int u);
  int midVertex(int u, int v);

  public:
  Graph(int numberOfVertices);
  int iFUB(int u, int l, int k);
  pair<int, int> fourSweep();
};

#endif
