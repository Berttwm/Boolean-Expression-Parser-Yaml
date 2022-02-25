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
	try 
	{
		return evaluate(currNode->getNodeOperator(), result_list);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	
}
int Evaluator::evaluate(std::string nodeOperator, std::vector<int> result_list)
{
	// TODO: Abstract Operation to Operator class
	if (available_operators_str.find(nodeOperator) != available_operators_str.end()) {
		// correct operator used
		if (nodeOperator.compare("OR") == 0)
		{
			std::cout << "Evaluating " << result_list[0] << " AND " << result_list[1] << std::endl;
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
		throw std::runtime_error(std::string("Error in evaluation: Not acceptable node_operator of type: ") + nodeOperator);
	}
	return -1; // wrong condition
}