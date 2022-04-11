#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
# include <stack>

template<class T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iter;
		MutantStack<T>() {}
		MutantStack<T>(const MutantStack<T>& other) { *this = other; }
		MutantStack<T>&	operator=(const MutantStack<T>& other) {
			if (this != &other) { *this = other; }
			return *this;
		}
		~MutantStack<T>() {}

		iter begin();
		iter end();
};

template <class T>
typename MutantStack<T>::iter	MutantStack<T>::begin() {
	return (this->c.begin());
}

template <class T>
typename MutantStack<T>::iter	MutantStack<T>::end() {
	return (this->c.end());
}


#endif
