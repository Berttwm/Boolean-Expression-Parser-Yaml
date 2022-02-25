#include "Header/ConfigParser.h"

ConfigParser::ConfigParser()
	: config(YAML::LoadFile("config.yaml"))
{
	try 
	{
		baseNode = parseyaml(config, 0);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}
	std::cout << std::string("successfully parsed yaml and created Tree") + std::string(" ready for next task") << std::endl;
}

Node *ConfigParser::getTreeBaseNode() // Retrieve Tree's baseNode
{
	return this->baseNode;
}

// Recursively called to get deepest root -- PostOrder Traversal (start from deepest left root)
Node *ConfigParser::parseyaml(const YAML::Node &node, int level)
{
	//std::cout << "[" << node << "]" << std::endl;

	// check valid assignments 
	checkValidKey(node);
	
	// Prepare child nodes
	std::string nodeOperator = node["cond"].as<std::string>();
	
	std::vector<Node*> childNodes;
	// Begin recursive calls
	// TODO: Accept variable arguments/expressions
	if (node["exp1"].IsMap()) 
	{
		const YAML::Node temp = node["exp1"];
		childNodes.push_back(parseyaml(temp, level + 1)); // TO CONFIRM: check if direct call works
	}
	else 
	{ 	// Handles case when result is available (i.e., no childNodes expression)
		std::string result_str = node["exp1"].as<std::string>();
		int result = stoi(result_str);
		childNodes.push_back(new Node(result, level + 1));
	}
	if (node["exp2"].IsMap()) 
	{
		const YAML::Node temp = node["exp2"];
		childNodes.push_back(parseyaml(temp, level + 1));
	}
	else
	{   // Handles case when result is available (i.e., no childNodes expression)
		std::string result_str = node["exp2"].as<std::string>();
		int result = stoi(result_str);
		childNodes.push_back(new Node(result, level + 1));
	}
	return new Node(childNodes, nodeOperator, level);
}

void ConfigParser::checkValidKey(const YAML::Node& node)
{
	if (!node["exp1"]) {
		throw std::runtime_error("Error in Parsing: Config file does not contafin exp1 key");
	} 
	if (!node["exp2"]) {
		throw std::runtime_error("Error in Parsing: Config file does not contain exp2 key");
	}
	if (!node["cond"]) {
		throw std::runtime_error("Error in Parsing: Config file does not contain cond key");
	}
}