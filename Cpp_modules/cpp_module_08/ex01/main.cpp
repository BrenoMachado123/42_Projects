#include "Span.hpp"

int main() {
	{
		Span v1(5);

		v1.AddNumber(1);
		v1.AddNumber(2);
		v1.AddNumber(3);
		v1.AddNumber(4);
		v1.AddNumber(5);
		try {
			v1.AddNumber(6); 
		} catch(std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << v1.ShortestSpan() << std::endl;
		std::cout << v1.LongestSpan() << std::endl;
	}
	{
		Span v1(10000);
		std::vector<int> v2(10000);
		v1.AddNumber(v2.begin(), v2.end());
		try {
			std::cout << v1.ShortestSpan() << std::endl;
			std::cout << v1.LongestSpan() << std::endl;
		} catch(std::exception& e) {
			std::cout << e.what() << std::endl;
		}

	}
	return (0);
}
