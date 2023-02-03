#ifndef BOARD_H
#define BOARD_H

#include <string>


struct Config {

	Config(const std::string& config_file);

	std::string board{};
	std::string pieces{};
};


#endif