#include "Header/Node.h"

Node::Node(std::vector<std::string> expr_list, std::string node_operator, int level) :
	expr_list(expr_list),
	node_operator(node_operator),
	level(level),
	num_args(expr_list.size())
{}

// Auxilary functions
void Node::node_print()
{
	std::cout << "Level: " << level << ", ";
	for (int i = 0; i < expr_list.size(); i++) {
		std::cout << "Expr" << i+1 << ": " << expr_list[i] << ", ";
	}
	std::cout << "operator: " << node_operator;
}