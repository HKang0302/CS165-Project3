#ifndef NODE_H
#define NODE_H

#include <vector>
#include <map>

class Node {
	public:
		// DO NOT MODIFY MEMBERS BELOW THIS LINE 
		bool operator==(const Node& other) const {return id == other.id;} 	// used for comparing two nodes, already implemented	
		int id; 															// uniquely identifies a node (no two nodes have the same id). 
				   															// id must be set in the constructor and thereafter not modified
		Node(){}															// don't use this constructor, implement another one that accepts node id as an argument 
		// DO NOT MODIFY MEMBERS ABOVE THIS LINE 
		
	// you should declare a constructor/any other members you need
	// implement any newly declared member functions in node.cpp
    Node(int nodeId);
    int degree;
    //std::vector<Node> adj;
    //void addNeighbor(Node newNode); // nID refers to neighbor ID
};

#endif
