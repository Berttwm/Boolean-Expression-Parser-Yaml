#pragma once
#include <stack>
#include <vector>
#include <unordered_set>

#include "Node.h"

class Evaluator {
	/* Fixed configurators */
	const std::unordered_set<std::string> available_operators_str{"OR", "AND"};
public:
	Evaluator(Node* baseNode);

	// Use DFS to process
	void processTree();
	// Evaluate ready Nodes
	void evaluate();

	// Auxilary functions
	void stack_print();


private:
	Node* baseNode;
	std::stack<Node*> stack;
	// assuming int is the result of output

};