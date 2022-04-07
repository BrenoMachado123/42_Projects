#include "Iter.hpp"

int main( void ) {
	std::string array[5] = {
		"a", "b", "1", "2", "k"
	};
	::iter(array, 5, ::printArray);

	int arrayInt[5] = {
		1, 2, 3, 4, 5
	};
	::iter(arrayInt, 5, ::printArray) ;

	Iter list[5];
	::iter(list, 5, ::printArray);
	
	return 0;
}
