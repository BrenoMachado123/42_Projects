#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

typedef	std::vector<int>::iterator iter;

class Span {
	private:
		unsigned int		_N;
		std::vector<int>	_elements;
	public:
		Span();
		Span(unsigned int size);
		Span(const Span& other);
		Span& operator=(const Span& other);	
		~Span();

		void			AddNumber(int n);
		void			AddNumber(iter start, iter end);
		long int		ShortestSpan();
		long int		LongestSpan();

		class MaxCapacityException : public std::exception {
			public:
				const char* what() const throw();
		};

		class NoSpanException : public std::exception {
			public:
				const char* what() const throw();
		};	
};

#endif
