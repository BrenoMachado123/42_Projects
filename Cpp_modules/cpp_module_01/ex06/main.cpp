#include "Karen.hpp"

int main(int argc, char **argv) {
	Karen bot;

	if (argc != 2) { return (1); }
	std::string filter(argv[1]);
	bot.complain(filter);
	return (0);
}