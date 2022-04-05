#include "Data.hpp"

int main() {
	Data		data("DataBob");

	std::cout << "Initial Data type: " << &data << std::endl; // Data memory address;
	uintptr_t raw = serialize(&data);
	std::cout << "Serialized Data type: "<< raw << std::endl; // cast Data to unisigned int uintptr_t type;
	Data* ptr = deserialize(raw);
	std::cout << "Deserialized Data type: " << ptr << std::endl; // recast uintptr_t type to Data;

	return (0);
}
