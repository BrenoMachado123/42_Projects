#include "Datatype.hpp"

Datatype::Datatype() : cstring(NULL) {}

Datatype::Datatype(char* cstring) {
	_cstring = static_cast<std::string>cstring; //casting a char* to std::string
	//toDo();
}

Datatype(const Datatype& other) { *this = other; }

Datatype& Datatype::operator=(const Datatype& other) {
	if (this != &other) {
		this->_cstring = other._cstring;
	}
	return (*this);
}

//define conversions to (float), (double), (char) and (int);

Datatype::~Datatype() {}
