#include "Datatype.hpp"

Datatype::Datatype() : _cstring(NULL) {}

static bool isNumber(std::string cstring) {
	int size = cstring.length();
	for (int i = 0; i < size; i++) {
		if ((!isdigit(cstring[i]) && cstring[i] != '-' && cstring[i] != '+')) { 
			return (false);
		}
	}
	return (true);
} // a static function just to check if the string is a number;

Datatype::Datatype(char* str) {
	_cstring = static_cast<std::string>(str); //casting a char* to std::string;
	//dealing with the pseudo literals case:
	std::string pseudolist[6] = {
		"-inff", "+inff", "nanf", "-inf", "+inf", "nan"
	};
	for (int i = 0; i <= 6; i++) {
		_parsingValue = i;
		if (_parsingValue > 2) { _parsingValue -= 3; }
		if (_cstring == pseudolist[i]) { return ; }
	}
	//(int) and (char) cases:
	if (_cstring.length() == 1) {
		_value = _cstring[0];
		if (isdigit(_cstring[0])) { _value -= '0'; }
		return ;
	}
	else if (_cstring.length() > 1 && isNumber(_cstring)) { _value = std::stol(_cstring); return ; }

	//(float) and (double) cases:
	char *endptr;
	double convertedType = strtod(str, &endptr);	
	if (*endptr == 'f' || _cstring.find(".") != std::string::npos) {
		_value = convertedType;
		return ;
	}

	//if it reached at this point, it means that is invalid
	_parsingValue = -1;
}

Datatype::Datatype(const Datatype& other) { *this = other; }

Datatype& Datatype::operator=(const Datatype& other) {
	if (this != &other) {
		this->_cstring = other._cstring;
		this->_parsingValue = other._parsingValue;
		this->_value = other._value;
	}
	return (*this);
}

//define conversions to (float), (double), (char) and (int);

void	Datatype::convertFloat() {
	switch (this->_parsingValue) {
		case 0: std::cout << "float: -inff"	<< std::endl;
			break ;
		case 1: std::cout << "float: +inff" << std::endl;
			break ;
		case 2: std::cout << "float: nanf" << std::endl;
			break ;
		case -1: std::cout << "float: invalid" << std::endl;
			break ;
		default:
			float convertedType = static_cast<float>(_value);
			std::cout << "float: " << convertedType << "f" << std::endl;
	}
}

void	Datatype::convertDouble() {
	switch (this->_parsingValue) {
		case 0: std::cout << "double: -inf"	<< std::endl;
			break ;
		case 1: std::cout << "double: +inf" << std::endl;
			break ;
		case 2: std::cout << "double: nan" << std::endl;
			break ;
		case -1: std::cout << "double: invalid" << std::endl;
			break ;
		default:
			std::cout << "double: " << _value << std::endl;
	}
}

void	Datatype::convertChar() {
	switch (this->_parsingValue) {
		case -1: std::cout << "char: invalid" << std::endl;
			 return ;
		case 3:
			char convertedType = static_cast<char>(_value);
			if (isprint(convertedType)) { 
				std::cout << "char: " << convertedType << std::endl;
			} else {
				std::cout << "char: Non displayable" << std::endl;
			}
			return ;
	}
	std::cout << "char: impossible" << std::endl;
}

void	Datatype::convertInt() {
	switch (this->_parsingValue) {
		case -1: std::cout << "int: invalid" << std::endl;
			 return ;
		case 3:
			int convertedType = static_cast<int>(_value);
			std::cout << "int: " << convertedType << std::endl;
			return ;
	}
	std::cout << "char: impossible" << std::endl;
}

Datatype::~Datatype() {}
