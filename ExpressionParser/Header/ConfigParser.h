#pragma once
#define YAML_CPP_STATIC_DEFINE 
//#define YAML_CPP_DLL

#include <fstream>
#include <yaml-cpp/yaml.h>
#include <iostream>

#include "Node.h"


class ConfigParser
{

public:
	ConfigParser();

	// Get Tree Base Node
	Node *getTreeBaseNode();

private:	
	Node *parseyaml(const YAML::Node& node, int level); // parses YAML while preparing Tree base node
	void checkValidKey(const YAML::Node& node);
	YAML::Node config;
	Node *baseNode; // baseNode of Tree responsible for eventual result
};

