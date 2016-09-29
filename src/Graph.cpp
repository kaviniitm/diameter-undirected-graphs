#include "Graph.h"

Graph::Graph(int numberOfVertices) {
  this->numberOfVertices = numberOfVertices;
  adjList.reserve(numberOfVertices);
}

int Graph::computeEccentricity(int u) {
  vector<int> distanceFromU(numberOfVertices);
  vector<bool> visited(numberOfVertices, false);
  queue<int> BFSQueue;

  visited[u] = true;
  distanceFromU[u] = 0;
  BFSQueue.push(u);

  int eccentricity = 0;
  while (!BFSQueue.empty()) {
    int top = BFSQueue.front();
    BFSQueue.pop();

    for (vector<int>::iterator it=adjList[top].begin(); it!=adjList[top].end(); ++it) {
      if (!visited[*it]) {
        visited[*it] = true;
        distanceFromU[*it] = distanceFromU[top] + 1;
        if (distanceFromU[*it] > eccentricity) {
          eccentricity = distanceFromU[*it];
        }
        BFSQueue.push(*it);
      }
    }
  }
  return eccentricity;
}

vector< set<int> > Graph::computeF(int u) {
  vector<int> distanceFromU(numberOfVertices);
  vector<bool> visited(numberOfVertices, false);
  queue<int> BFSQueue;

  visited[u] = true;
  distanceFromU[u] = 0;
  BFSQueue.push(u);

  int eccentricity = 0;
  while (!BFSQueue.empty()) {
    int top = BFSQueue.front();
    BFSQueue.pop();

    for (vector<int>::iterator it=adjList[top].begin(); it!=adjList[top].end(); ++it) {
      if (!visited[*it]) {
        visited[*it] = true;
        distanceFromU[*it] = distanceFromU[top] + 1;
        if (distanceFromU[*it] > eccentricity) {
          eccentricity = distanceFromU[*it];
        }
        BFSQueue.push(*it);
      }
    }
  }

  vector< set<int> > F(eccentricity+1);
  for (int i=0; i<numberOfVertices; ++i) {
    F[distanceFromU[i]].insert(i);
  }
  return F;
}

int Graph::computeMaxEccentricity(set<int> vertices) {
  int maxEccentricity = 0;
  for (set<int>::iterator it=vertices.begin(); it!=vertices.end(); ++it) {
    int eccentricity = computeEccentricity(*it);
    if (eccentricity > maxEccentricity) {
      maxEccentricity = eccentricity;
    }
  }
  return maxEccentricity;
}

int Graph::iFUB(int u, int l, int k) {
  int eccentricityU = computeEccentricity(u);
  int i = eccentricityU;
  int lb = max(eccentricityU, l);
  int ub = 2*eccentricityU;

  vector< set<int> > F = computeF(u);
  while (ub-lb>k) {
    int newLowerBound = max(lb, computeMaxEccentricity(F[i]));
    if (newLowerBound > 2*(i-1)) {
      return newLowerBound;
    } else {
      lb = newLowerBound;
      ub = 2*(i-1);
    }
    i--;
  }
}
