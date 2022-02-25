#include <iostream>
#include <opencv2/core/core.hpp>

#include "Header/ConfigParser.h"
#include "Header/Evaluator.h"

int main()
{
	// Create ConfigParser
	ConfigParser *CP = new ConfigParser();
	// Extract Tree base node from ConfigParser
	Node *baseNode = CP->getTreeBaseNode();
	// Create Evaluator - with Tree base node
	Evaluator* evaluator = new Evaluator();
	std::cout << "overall evaluation is: " << evaluator->processTree(baseNode) << std::endl;
	return 0;
}