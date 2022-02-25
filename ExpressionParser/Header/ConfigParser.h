#pragma once
#define YAML_CPP_STATIC_DEFINE 
//#define YAML_CPP_DLL

#include <fstream>
#include <yaml-cpp/yaml.h>
#include <iostream>

#include "Evaluator.h"
#include "Node.h"


class ConfigParser
{

public:
	ConfigParser(Evaluator *evaluator);

private:	
	void parseyaml(const YAML::Node& node, int level); 
	void checkValidKey(const YAML::Node& node);
	YAML::Node config;
	Evaluator *evaluator;
};

