#include "Header/Node.h"

Node::Node(std::vector<Node*> childNodes, std::string node_operator, int level) :
	childNodes(childNodes),
	node_operator(node_operator),
	level(level),
	num_args(childNodes.size())
{
	node_print(); // Comment out if you don't want Node Stats
}

Node::Node(int result, int level) :
	result(result),
	level(level),
	num_args(0) // Comment out if you don't want Node Stats
{
	node_print();
}

// Auxilary functions
// node_print not ready for use
// TODO: Fixed debug node print
void Node::node_print()
{
	std::cout << "[Level: " << level << ", ";
	std::cout << "result: " << this->result << ", ";
	std::cout << "num_args to eval: " << this->num_args << ", ";
	std::cout << "operator: " << node_operator << "]" << std::endl;
}