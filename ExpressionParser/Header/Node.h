#pragma once
#include <iostream>
#include <string>
#include <vector>

class Node {
public:
	Node(std::vector<std::string> expr_list, std::string node_operator, int level);
	// Auxilary functions
	void node_print();
private:
	std::vector<std::string> expr_list;
	std::string node_operator;
	int level; // inferred during parsing
	int num_args; // inferred during parsing
};