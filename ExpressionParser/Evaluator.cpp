#include "Header/Evaluator.h"

Evaluator::Evaluator() 
{
}
// DFS approach to tree search
int Evaluator::processTree(Node* currNode)
{
	if (currNode->getResult() != -1) // if leaf node, simply return result
		return currNode->getResult();

	std::vector<int> result_list;
	for (size_t i = 0; i < currNode->getNumChild(); i++)
	{
		result_list.push_back(processTree(currNode->getChildNodesList()[i]));
	}
	return evaluate(currNode->getNodeOperator(), result_list);
}
int Evaluator::evaluate(std::string nodeOperator, std::vector<int> result_list)
{
	// TODO: Abstract Operation to Operator class
	if (available_operators_str.find(nodeOperator) != available_operators_str.end()) {
		// correct operator used
		if (nodeOperator.compare("OR") == 0)
		{
			std::cout << "Evaluating " << result_list[0] << " OR " << result_list[1] << std::endl;
			return result_list[0] | result_list[1]; // TODO: Change the hard-code
		}
		if (nodeOperator.compare("AND") == 0) 
		{
			std::cout << "Evaluating " << result_list[0] << " AND " << result_list[1] << std::endl;
			return result_list[0] & result_list[1]; // TODO: Change the hard-code
		}
	}
	else 
	{
		throw std::runtime_error("Error in evaluation: node_operator type of: " + nodeOperator + " is not acceptable");
	}
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