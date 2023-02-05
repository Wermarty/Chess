#ifndef BOARD_H
#define BOARD_H

#include <string>


struct Config {

	Config(const std::string& config_file);
	void print() const;


	std::string board{};
	std::string pieces{};
	std::string help{};
	bool need_help{ false };
};


#endif