#include "Header/Evaluator.h"

Evaluator::Evaluator() {
	// instantiate size of evaluated_nodes_vector
	
}

// Stack operations
void Evaluator::push_stk(Node node)
{
	eval_stack.push(node);
}
Node Evaluator::pop_stk(Node node)
{
	Node result_node = eval_stack.top();
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