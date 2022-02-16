#include "Header/ConfigParser.h"

ConfigParser::ConfigParser()
	: config(YAML::LoadFile("config.yaml"))
{
	try {
		parseyaml();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		throw e;
	}
	
}

// Recursively called to get deepest root
void ConfigParser::parseyaml()
{
	// check valid assignments 
	checkValidKey();
}

void ConfigParser::checkValidKey()
{
	if (!this->config["exp1"]) {
		throw std::runtime_error("Error: Config file does not contain exp1 key");
	} 
	if (!this->config["exp2"]) {
		throw std::runtime_error("Error: Config file does not contain exp2 key");
	}
	if (!this->config["cond"]) {
		throw std::runtime_error("Error: Config file does not contain cond key");
	}
}