#include "node.h"

// implement member functions for the Node class here
Node::Node(int nodeId)
{
  id = nodeId;
  degree = 0;
}

//void Node::addNeighbor(Node newNode)
//{
//  this->adj.push_back(newNode);
//  this->degree++;
//}
