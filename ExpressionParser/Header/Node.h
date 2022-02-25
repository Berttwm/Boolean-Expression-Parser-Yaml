#pragma once
#include <iostream>
#include <string>
#include <vector>

class Node {
public:
	Node(std::vector<Node*> childNodes, std::string nodeOperator, int level); // For creating nodes with child
	Node(int result, int level); // For creating leaf nodes with no child
	// Getters:
	int getResult();
	size_t getNumChild();
	std::vector<Node*> getChildNodesList();
	std::string getNodeOperator();

	// Auxilary functions:
	bool isResultReady(); // checks if Node has results
	void node_print();
private:
	int result = -1; // -1 imply result not ready, only set upon empty childNodes OR evaluated childNodes
	size_t num_child; // inferred during parsing
	std::vector<Node*> childNodes; // NULL for no child
	std::string nodeOperator;

	int level; // for debugging, remove once done
};