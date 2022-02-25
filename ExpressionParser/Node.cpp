#include "Header/Node.h"

Node::Node(std::vector<Node*> childNodes, std::string node_operator, int level) :
	childNodes(childNodes),
	node_operator(node_operator),
	level(level),
	num_args(childNodes.size())
{
}

Node::Node(int result, std::string node_operator, int level) :
	result(result),
	node_operator(node_operator),
	level(level),
	num_args(0) // should be 0 child ==> 0 args
{
}

// Auxilary functions
// node_print not ready for use
// TODO: Fixed debug node print
void Node::node_print()
{
	std::cout << "Level: " << level << ", ";
	for (int i = 0; i < childNodes.size(); i++)
	{
		//std::cout << "Expr" << i+1 << ": " << expr_list[i] << ", ";
	}
	std::cout << "operator: " << node_operator;
}