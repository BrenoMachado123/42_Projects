#ifndef DATATYPE_HPP
# define DATATYPE_HPP

#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <cstdlib>
#include <string>

class Datatype {
	private:
		std::string _cstring;
		double		_value;
		int			_parsingValue;
	public:
		Datatype();
		Datatype(char* str);
		Datatype(const Datatype& other);
		Datatype& operator=(const Datatype& other);
		~Datatype();

		void	convertChar();
		void	convertInt();
		void	convertDouble();
		void	convertFloat();
};

#endif
