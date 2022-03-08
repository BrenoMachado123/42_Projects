#include "Karen.hpp"

Karen::Karen() {
	karen_cmds[0] =	&Karen::_debug, 
	karen_cmds[1] =	&Karen::_info, 
	karen_cmds[2] =	&Karen::_warning, 
	karen_cmds[3] =	&Karen::_error;
	std::cout << "A wild Karen created!" << std::endl;
}

Karen::~Karen() {std::cout<<"Karen shutdown"<<std::endl;}

void Karen::_debug() {
	std::cout << "I love having extra bacon for my "
	"7XL-double-cheese-triple-pickle-special-ketchup "
	"burguer. I really do!" << std::endl;
}

void	Karen::_info() {
	std::cout << "I cannot believe adding extra bacon "
	"cost more money. You don't put enough bacon in my burger! if you did "
	"I wouldn't be asking for more!" << std::endl;
}

void	Karen::_warning() {
	std::cout << "I think I deserve to have some extra bacon for free. "
	"I've been coming here for years whereas you started working "
	"here since last mouth." << std::endl;
}

void	Karen::_error() {
	std::cout << "This is unaccptable! I want speak to the manager now."
	<< std::endl;
}

void	Karen::complain(std::string level) {
	int i = 0;
	std::string comp_levels[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};
	while (i < 4 && comp_levels[i] != level) { i++; }
	try {(this->*karen_cmds[i])();} catch(...){return ;}
}