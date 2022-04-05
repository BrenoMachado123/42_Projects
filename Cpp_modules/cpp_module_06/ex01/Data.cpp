#include "Data.hpp"

Data::Data() : _dataName("ClapTrap") {}

Data::Data(const std::string& name) : _dataName(name) {}

Data::Data(const Data& other) { *this = other; }

Data& Data::operator=(const Data& other) {
	if (this != &other) {
		this->_dataName = other._dataName;
	}
	return (*this);
}

uintptr_t serialize(Data *ptr) {
	uintptr_t uip = reinterpret_cast<uintptr_t>(ptr);
	return (uip);
}

Data* deserialize (uintptr_t raw) {
	Data *ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}

Data::~Data() {}
