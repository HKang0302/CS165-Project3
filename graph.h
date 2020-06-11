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
    std::vector<Node> getNodes();
    bool isNeighbor(Node u, Node v);
    int BFS(int nID, int& dist);
    std::vector<int> getDegrees();
    int getDegree(Node node);
    int getMaxDegree(std::vector<int> degrees);
    int countTriangles();
    int getDenom();
    std::map<int, int> vertex_to_degree_map();

  private:
    int nNode=0, nEdge = 0;
    std::vector<Node> nodes;
    std::vector<Node>* edges; // edges between u and v
    
};

#endif
