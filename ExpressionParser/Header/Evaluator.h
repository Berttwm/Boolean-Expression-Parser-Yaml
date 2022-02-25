#pragma once
#include <stack>
#include <vector>

#include "Node.h"

class Evaluator {
public:
	Evaluator(Node* baseNode);

	void evaluate();

	// Stack operations
	void push_stk(Node *node);
	Node *pop_stk();

	// Auxilary functions
	void stack_print();


private:
	Node* baseNode;
	std::stack<Node*> eval_stack;
	// assuming int is the result of output

};