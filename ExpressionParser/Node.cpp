#include "Header/Node.h"

Node::Node(std::vector<Node*> childNodes, std::string nodeOperator, int level) :
	childNodes(childNodes),
	nodeOperator(nodeOperator),
	level(level),
	num_child(childNodes.size())
{
	node_print(); // Comment out if you don't want Node Stats
}

Node::Node(int result, int level) :
	result(result),
	level(level),
	num_child(0) // Comment out if you don't want Node Stats
{
	node_print();
}

// Getters:
int Node::getResult()
{
	return this->result;
}

int Node::getNumChild()
{
	return this->num_child;
}

std::vector<Node*> Node::getChildNodesList()
{
	return this->childNodes;
}

std::string Node::getNodeOperator()
{
	return this->nodeOperator;
}

// Auxilary functions
bool Node::isResultReady()
{ // Node is a leaf when result is ready && there are 0 childNode
	return((this->result != -1));
}

void Node::node_print()
{
	std::cout << "[Level: " << level << ", ";
	std::cout << "result: " << this->result << ", ";
	std::cout << "num_args to eval: " << this->num_child << ", ";
	std::cout << "operator: " << nodeOperator << "]" << std::endl;
}