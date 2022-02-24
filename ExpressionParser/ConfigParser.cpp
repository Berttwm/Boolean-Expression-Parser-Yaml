#include "Header/ConfigParser.h"

ConfigParser::ConfigParser()
	: config(YAML::LoadFile("config.yaml"))
{
	try 
	{
		parseyaml(config, 0);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		throw e;
	}
	std::cout << "successfully parsed yaml, evaluator stack successfully initialized" << std::endl;

	// evaluator.stack_print(); // use to print stack information

}

// Recursively called to get deepest root
void ConfigParser::parseyaml(const YAML::Node &node, int level)
{
	std::cout << "[" << node << "]" << std::endl;

	// check valid assignments 
	checkValidKey(node);
	
	// Prepare new node
	std::string expr1 = "Expect1";
	std::string expr2 = "Expect2";
	std::vector<std::string> expr_list;
	if (!node["exp1"].IsMap()) expr1 = node["exp1"].as<std::string>();
	if (!node["exp2"].IsMap()) expr2 = node["exp2"].as<std::string>();
	expr_list.push_back(expr1); expr_list.push_back(expr2);
	std::string node_operator = node["cond"].as<std::string>();
	evaluator.push_stk(new Node(expr_list, node_operator, level));
	// Begin recursive calls
	if (node["exp1"].IsMap()) 
	{
		const YAML::Node temp = node["exp1"];
		parseyaml(temp, level + 1);
	}
	if (node["exp2"].IsMap()) 
	{
		const YAML::Node temp = node["exp2"];
		parseyaml(temp, level + 1);
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