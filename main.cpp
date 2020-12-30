#include "yaml-cpp/yaml.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main()
{
bool fileLoaded = false;
YAML::Node config;

std::vector<float> target_jpos;

try
{
    config = YAML::LoadFile("/config/test.yaml");
    fileLoaded = true;
}
catch(std::exception& e)
{
    fileLoaded = false;
}

target_jpos = config["target_jpos"].as<std::vector<float> >();

if(fileLoaded)
    std::cout << "File loaded successfully \n\t target_jpos[0]: " << target_jpos[0] << "\n";
else
    std::cout << "File failed to load\n";    
    
    return 0;
}