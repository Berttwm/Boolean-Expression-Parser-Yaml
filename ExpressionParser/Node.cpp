#include "Header/Node.h"

Node::Node(std::vector<std::string> expr_list, std::string node_operator, int level) :
	expr_list(expr_list),
	node_operator(node_operator),
	level(level),
	num_args(expr_list.size())
{}