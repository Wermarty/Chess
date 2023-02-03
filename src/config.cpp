#include "config.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>


Config::Config(const std::string& config_file) {
	
	std::ifstream config{ "config.txt", std::ios::in };

	if (!config.good()) {
		throw std::runtime_error("Couldn't open config file\n");
	}

	std::string line{};
	while (getline(config, line)) {
		std::stringstream ss{ line };
		std::string temp_type{};
		std::string temp_name{};

		ss >> temp_type >> temp_name >> temp_name;

		std::string path{"image/"};
		path += temp_name;
		if (temp_type == "board") {
			board = path;
		}
		else {
			pieces = path;
		}
	}
}
