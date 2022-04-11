#include "Span.hpp"

Span::Span() : _N(0), _elements(0) {}
Span::Span(unsigned int size) : _N(size), _elements(0) {}
Span::Span(const Span& other) { *this = other; }
Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_N = other._N;
		this->_elements = other._elements;
	}
	return (*this);	
}
Span::~Span() {}

void	Span::AddNumber(int n) {
	if (_elements.size() == this->_N) {
		throw MaxCapacityException();
	}
	_elements.push_back(n);
}

void	Span::AddNumber(iter start, iter end) {
	if ((_elements.size() + std::distance(start, end)) > this->_N)
		throw MaxCapacityException();
	for (long int i=0; i < std::distance(start, end); i++)
		this->AddNumber(i);
}

long int Span::ShortestSpan() {
	if (_elements.size() <= 1) { throw NoSpanException(); }
	long int min = *std::min_element(_elements.begin(), _elements.end());
	long int max = min;
	bool 	 firstMax = false;
	for (size_t i=0; i < _elements.size(); i++) {
		if (static_cast<long int>(_elements[i]) > min && !firstMax) {
			max = static_cast<long int>(_elements[i]);
			firstMax = true;
		} else if (firstMax && static_cast<long int>(_elements[i]) < max) {
			max = static_cast<long int>(_elements[i]);
		}
	}
	return (max - min);
}

long int Span::LongestSpan() {
	if (_elements.size() <= 1) { throw NoSpanException(); }
	long int max = *std::max_element(_elements.begin(), _elements.end());
	long int min = *std::min_element(_elements.begin(), _elements.end());
	return (max - min);
}

const char* Span::MaxCapacityException::what() const throw() {
	return "error: maximum size reached";	
}

const char* Span::NoSpanException::what() const throw() {
	return "error: not able to span";
}
