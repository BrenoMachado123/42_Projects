#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <stdint.h>

class Data {
	private:
		std::string _dataName;
	public:
		Data();
		Data(const std::string& name);
		Data(const Data& other);
		Data& operator=(const Data& other);
		~Data();
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);


#endif
