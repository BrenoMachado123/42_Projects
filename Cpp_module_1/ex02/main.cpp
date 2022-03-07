#include <iostream>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR;
	std::string &stringREF = str;

	stringPTR = &str;
	std::cout << "string: " << str << std::endl;
	std::cout << "string pointer: " << stringPTR << std::endl;
	std::cout << "string reference: " << stringREF << std::endl;
	return (0);
}
