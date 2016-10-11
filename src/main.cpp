#include "Graph.h"

#include <iostream>
#include <fstream>
#include <map>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  if (argc != 2) {
    cout<<"Error in Command Line. ./main <datasetFileName>"<<endl;
    return 0;
  }
  ifstream inputStream(argv[1], ios::in);
  int numberOfVertices;
  int numberOfEdges;
  inputStream>>numberOfVertices>>numberOfEdges;
  Graph graph(numberOfVertices);
  map<int, int> vertexToIndex;
  set<int> vertices;
  int vertexIndex = 0;
  for (int i=0; i<numberOfEdges; ++i) {
    int vertex1;
    int vertex2;
    inputStream>>vertex1>>vertex2;
    if (vertices.find(vertex1)==vertices.end()) {
      vertexToIndex[vertex1] = vertexIndex++;
      vertices.insert(vertex1);
    }
    if (vertices.find(vertex2)==vertices.end()) {
      vertexToIndex[vertex2] = vertexIndex++;
      vertices.insert(vertex2);
    }
    graph.addEdge(vertexToIndex[vertex1], vertexToIndex[vertex2]);
  }
  inputStream.close();
  cout<<"Done taking the input"<<endl;

  cout<<"Starting the four sweep algorithm"<<endl;
  pair<int,int> lowerBoundVertexPair = graph.fourSweep();
  cout<<"Done with the four sweep"<<endl;

  cout<<"Starting the iFUB algorithm"<<endl;
  cout<<"Diameter:"<<graph.iFUB(lowerBoundVertexPair.second, lowerBoundVertexPair.first, 0)<<endl;
  cout<<"Done with the iFUB algorithm"<<endl;
}
