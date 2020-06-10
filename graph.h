#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include <vector>
#include "node.h"
#include <list>
#include <algorithm>

class Graph 
{
	public:
		// DO NOT MODIFY MEMBERS BELOW THIS LINE
    int get_num_nodes(); 						// get number of nodes
    int get_num_edges(); 						// get number of edges
    std::vector<Node> get_neighbors(Node u); 	// return neighbors of u 
    std::map<int, Node> get_id_to_node_map(); 	// allows lookup of nodes from ids
		// DO NOT MODIFY MEMBERS ABOVE THIS LINE
		
		// declare any constructors, members, and member functions you may want to use
    Graph() {};
    Graph(int num_nodes, std::vector<int> u, std::vector<int> v);
    Node getNode(int id);
    bool isNeighbor(Node u, Node v);
    int BFS(int nID, int& dMax);
    std::list<int> getDegeneracy(std::list<int>* N);
    std::vector<int> getDegrees();
    int getMaxDegree(std::vector<int> degrees);

  private:
    int nNode=0, nEdge = 0;
    std::vector<Node> nodes;
    std::vector<Node>* edges; // edges between u and v
    
};

#endif
