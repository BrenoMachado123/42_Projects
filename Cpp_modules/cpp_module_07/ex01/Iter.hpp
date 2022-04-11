#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

class Iter {
	private:
		int _element;
	public:
		Iter() : _element(0) {}
		Iter(const Iter& other) { *this = other; }
		Iter & operator=(const Iter& other) {
			if (this != &other ) { this->_element = other._element; }
			return *this;
		}
		~Iter() {}

		int getElement_() const { return (this->_element); }
};

std::ostream& operator<<(std::ostream& out, const Iter& obj) { 
	out << obj.getElement_(); 
	return out;
}

template<typename T>
void	iter(T* array, int size, void (*func)(T&)) {
	for (int i = 0; i < size; i++) { (*func)(array[i]); }
	std::cout << std::endl;
}

template<typename T>
void	printElement(T& anything) {
	std::cout << anything << ".";
}

#endif
