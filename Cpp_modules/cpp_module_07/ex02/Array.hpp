#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<class T> 
class Array {
	private:
		T* _array;
		unsigned int _size;
	public:
		Array<T>() : _array(0), _size(0) {}
		Array<T>(unsigned int n) { _array = new T[n]; _size = n; }
		Array<T>(const Array& other) : _array(0), _size(0) { *this = other; }
		Array<T>& operator=(const Array<T>& other) {
			if (this != &other) {
				delete[] this->_array;
				this->_size = other._size;
				this->_array = new T[this->_size];
				for (int i=0; i < (int&)this->_size; i++)
					this->_array[i] = other._array[i];
			}
			return *this;
		}
		~Array<T>() { delete[] this->_array; }

		T& operator[](int index) {
			if (index < 0 || index >= (int&)this->_size) { 
				throw std::exception();
			}
			return (this->_array[index]);
		}

		int size() { return (this->_size); }
};

#endif
