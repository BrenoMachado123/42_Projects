#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>

class Checker
{
	private:
		int _n;
	public:
		Checker() : _n(0) {}
		Checker(int n) : _n(n) {}
		Checker(const Checker& other) { *this = other; }
		Checker & operator= (const Checker& other) {
			if (this != &other ) { this->_n = other._n; }
			return *this;
		}
		~Checker() {}
		bool operator==(Checker const& other) const { return (this->_n == other._n); }
		bool operator!=(Checker const& other) const{ return (this->_n != other._n); }
		bool operator>(Checker const& other) const { return (this->_n > other._n); }
		bool operator<(Checker const& other) const { return (this->_n < other._n); }
		bool operator>=(Checker const& other) const { return (this->_n >= other._n); }
		bool operator<=(Checker const& other) const { return (this->_n <= other._n); }
		int getN() const { return this->_n; }
};

std::ostream& operator<<(std::ostream& out, const Checker& obj) { 
		out << obj.getN(); 
		return out;
}

template<typename T>
void	swap(T& first, T& second) {
	T tmp = first;
	first = second;
	second = tmp;
}

template<typename T>
T	min(T& first, T& second) {
	if (first < second) { return (first); }
	return (second);
}

template<typename T>
T	max(T& first, T& second) {
	if (first > second) { return (first); }
	return (second);
}


#endif
