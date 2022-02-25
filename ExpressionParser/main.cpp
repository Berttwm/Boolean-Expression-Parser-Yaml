#include <iostream>

#include "Header/ConfigParser.h"

int main()
{

	// Create ConfigParser
	Evaluator *evaluator = new Evaluator();
	ConfigParser *CP = new ConfigParser(evaluator);
	
	return 0;
}