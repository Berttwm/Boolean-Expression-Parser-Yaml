#pragma once
#include <iostream>
#include <string>
#include <vector>

class Node {
public:
	Node(std::vector<Node*> childNodes, std::string node_operator, int level); // For creating nodes with child
	Node(int result, int level); // For creating leaf nodes with no child
	// Auxilary functions
	void node_print();
private:
	int result = -1; // -1 imply result not ready, only set upon empty childNodes OR evaluated childNodes
	std::string node_operator;
	std::vector<Node*> childNodes; // NULL for no child

	int level; // for debugging, remove once done
	int num_args; // inferred during parsing
};