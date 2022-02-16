#pragma once
#define YAML_CPP_STATIC_DEFINE 
//#define YAML_CPP_DLL

#include <fstream>
#include <yaml-cpp/yaml.h>
#include <iostream>

class ConfigParser
{

public:
	ConfigParser();

private:	
	void parseyaml();
	void checkValidKey();
	YAML::Node config;

};

