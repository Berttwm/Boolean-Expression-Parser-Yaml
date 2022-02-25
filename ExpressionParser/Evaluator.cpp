#include "Header/Evaluator.h"

Evaluator::Evaluator() {
	// instantiate size of evaluated_nodes_vector
}
// evaluate
void Evaluator::evaluate()
{
	while (!eval_stack.empty())
	{
		Node *curr_node = eval_stack.top();
		// TODO: Finish evaluation steps
		eval_stack.pop();
	}
}

// Stack operations
void Evaluator::push_stk(Node *node)
{
	eval_stack.push(node);
}
Node *Evaluator::pop_stk()
{
	Node *result_node = eval_stack.top();
	return result_node;
}
// Results vector operations
void Evaluator::add_results(int level, int column, int results)
{
	results_vector[level][column] = results;
}
int Evaluator::remove_results(int level, int column)
{
	return results_vector[level][column];
}

// Auxilary functions
void Evaluator::stack_print() 
{
	std::cout << "printing evalutor stack stats..." << std::endl;
	// to reuse stack, we create another stack
	std::stack<Node *> temp_stack;
	std::cout << "Top: " << std::endl;
	while (!eval_stack.empty()) 
	{
		Node *elem = eval_stack.top();
		temp_stack.push(elem);
		eval_stack.pop();
		std::cout << "[";
		elem->node_print();
		std::cout << "]" << std::endl;
	}
	std::cout << "Bot: " << std::endl;
	// push elements back to original eval_stack
	while (!temp_stack.empty()) 
	{
		eval_stack.push(temp_stack.top());
		temp_stack.pop();
	}
}