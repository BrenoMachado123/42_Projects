#ifndef random_access_iterator_HPP
# define random_access_iterator_HPP

#include <iostream>
#include "iterator_traits.hpp"

namespace ft {
	template<class T>
	class random_access_iterator {
		public:
			typedef ft::iterator_traits<T>						traits_type;

			typedef typename traits_type::value_type			value_type;
			typedef typename traits_type::difference_type		difference_type;
			typedef typename traits_type::pointer				pointer;
			typedef typename traits_type::reference				reference;
			typedef typename traits_type::iterator_category		iterator_category;

			random_access_iterator() : _ptr(pointer()) {}
			random_access_iterator(pointer ptr) : _ptr(ptr) {}
			random_access_iterator(const random_access_iterator& other) { *this = other; }
			random_access_iterator& operator=(const random_access_iterator& other) {
				if (this != &other)
					this->_ptr = other._ptr;
				return (*this);
			}
			~random_access_iterator() {}

			random_access_iterator operator++() {
				_ptr++; 
				return (*this);
			}
			random_access_iterator operator++(int) { 
				random_access_iterator tmp(*this); 
				++(*this);
				return (tmp);
			}

			random_access_iterator operator--() {
				_ptr--; 
				return (*this);
			}
			random_access_iterator operator--(int) { 
				random_access_iterator tmp(*this); 
				--(*this);
				return (tmp);
			}

			pointer operator->() { return (_ptr); }
			reference	operator[](size_t index) { return *(_ptr[index]); }
			reference operator*() { return *_ptr; }
			reference	operator[](size_t index) const { return *(_ptr[index]); }
			bool operator==(const random_access_iterator& other) { return (this->_ptr == other._ptr); }
			bool operator!=(const random_access_iterator& other) { return (this->_ptr != other._ptr); }
					
		private:
			pointer _ptr;
	};
}

#endif
