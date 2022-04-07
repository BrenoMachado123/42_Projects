#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

class Iter {
	private:
		int _var;
	public:
		Iter() : _var(0) {}
		Iter(const Iter& other) { *this = other; }
		Iter & operator=(const Iter& other) {
			if (this != &other ) { this->_var = other._var; }
			return *this;
		}
		~Iter() {}

		int getVar() const { return (this->_var); }
};

std::ostream& operator<<(std::ostream& out, const Iter& obj) { 
	out << obj.getVar(); 
	return out;
}

template<typename T>
void	iter(T* array, int size, void (*func)(T&)) {
	for (int i = 0; i < size; i++) { (*func)(array[i]); }
	std::cout << std::endl;
}

template<typename T>
void	printArray(T& anything) {
	std::cout << anything << ".";
}

#endif
