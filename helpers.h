#ifndef HELPERS_H
#define HELPERS_H

#include "node.h"
#include "graph.h"
#include <vector>
#include <map>
#include <algorithm>
#include <array>

// returns -1 if visited all nodes
// otherwise, returns the id that hasn't been visited yet
int visitedAll(Graph graph, bool* visited);

int countTriangles(Graph graph);

void printD(std::list<int>* D, int maxDegree);
void printN(std::vector<Node> adj);

//template <typename T >
void printVector(std::vector<int> v);
template <typename T >
void printList(std::list<T> l);

#endif
