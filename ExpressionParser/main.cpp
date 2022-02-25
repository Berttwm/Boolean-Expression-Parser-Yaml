#include <iostream>

#include "Header/ConfigParser.h"
#include "Header/Evaluator.h"

int main()
{
	// Create ConfigParser
	ConfigParser *CP = new ConfigParser();
	// Extract Tree base node from ConfigParser
	Node *baseNode = CP->getTreeBaseNode();
	// Create Evaluator - with Tree base node
	Evaluator* evaluator = new Evaluator(baseNode);
	return 0;
}