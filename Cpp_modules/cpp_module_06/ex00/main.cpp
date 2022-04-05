#include "Datatype.hpp"

int main(int argc, char **argv) {
	if (argc != 2) { return 1; /* to add an error msg */}
	Datatype type(argv[1]); // it will transform char* to std::string;
	std::cout << std::setprecision(1) << std::fixed;
	type.convertChar();
	type.convertInt();
	type.convertFloat();
	type.convertDouble();

	return (0);
}
