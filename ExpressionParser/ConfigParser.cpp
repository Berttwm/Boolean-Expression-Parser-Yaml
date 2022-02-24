#include "Header/ConfigParser.h"

ConfigParser::ConfigParser()
	: config(YAML::LoadFile("config.yaml"))
{
	try {
		parseyaml(config);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		throw e;
	}
	std::cout << "successfully parsed yaml" << std::endl;
}

// Recursively called to get deepest root
void ConfigParser::parseyaml(const YAML::Node &node)
{
	std::cout << "[" << node << "]" << std::endl;

	// check valid assignments 
	checkValidKey(node);
	if (node["exp1"].IsMap()) {
		const YAML::Node temp = node["exp1"];
		parseyaml(temp);
	}
	if (node["exp2"].IsMap()) {
		const YAML::Node temp = node["exp2"];
		parseyaml(temp);
	}
}

void ConfigParser::checkValidKey(const YAML::Node& node)
{
	if (!node["exp1"]) {
		throw std::runtime_error("Error: Config file does not contafin exp1 key");
	} 
	if (!node["exp2"]) {
		throw std::runtime_error("Error: Config file does not contain exp2 key");
	}
	if (!node["cond"]) {
		throw std::runtime_error("Error: Config file does not contain cond key");
	}
}