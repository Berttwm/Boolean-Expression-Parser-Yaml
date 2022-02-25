#include "Header/Evaluator.h"

Evaluator::Evaluator(Node *baseNode) 
	: baseNode(baseNode)
{
	// instantiate size of evaluated_nodes_vector
}
// DFS approach to tree search
void Evaluator::processTree()
{
	std::cout << "Begin evaluating Tree" << std::endl;
	while (!stack.empty())
	{
		Node *curr_node = stack.top();
		// TODO: Finish evaluation steps
		stack.pop();
	}
}
void Evaluator::evaluate()
{

}


// Auxilary functions
void Evaluator::stack_print() 
{
	std::cout << "printing evalutor stack stats..." << std::endl;
	// to reuse stack, we create another stack
	std::stack<Node *> temp_stack;
	std::cout << "Top: " << std::endl;
	while (!stack.empty())
	{
		Node *elem = stack.top();
		temp_stack.push(elem);
		stack.pop();
		elem->node_print();

	}
	std::cout << "Bot: " << std::endl;
	// push elements back to original eval_stack
	while (!temp_stack.empty()) 
	{
		stack.push(temp_stack.top());
		temp_stack.pop();
	}
}