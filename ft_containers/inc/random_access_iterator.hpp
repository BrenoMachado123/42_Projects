#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"


//https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator.h.html#std::reverse_iterator::current
namespace ft {

	template<class Iter>
	class random_access_iterator {
		public:
			typedef ft::iterator_traits<Iter>						traits_type;

			typedef Iter										iterator_type;
			typedef typename traits_type::value_type			value_type;
			typedef typename traits_type::difference_type		difference_type;
			typedef typename traits_type::pointer				pointer;
			typedef typename traits_type::reference				reference;	
			typedef typename traits_type::iterator_category		iterator_category;

			random_access_iterator() : _ptr(iterator_type()) {}
			random_access_iterator(iterator_type ptr) : _ptr(ptr) {}

			template<class 	T>
				random_access_iterator(const random_access_iterator<T>& other)
					: _ptr(other.base()) {}

			random_access_iterator(const random_access_iterator& other)
			{ *this = other; }

			random_access_iterator& operator=(const random_access_iterator& other) {
				if (this != &other)
					this->_ptr = other._ptr;
				return (*this);
			}
			~random_access_iterator() {}

			iterator_type base() const
			{ return _ptr; };

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

			pointer operator->()
			{ return (_ptr); }

			reference	operator[](size_t index)
			{ return *(_ptr[index]); }
	
			reference operator*() const
			{ return *_ptr;}

			reference	operator[](size_t index) const
			{ return *(_ptr[index]); }
		
			bool operator==(const random_access_iterator& other)
			{ return (this->_ptr == other._ptr); }
			
			bool operator!=(const random_access_iterator& other)
			{ return (this->_ptr != other._ptr); }
			
			random_access_iterator operator-(difference_type n) 
			{ return random_access_iterator(_ptr - n); }
			
			random_access_iterator operator+(difference_type n) 
			{ return random_access_iterator(_ptr + n); }
			
			random_access_iterator& operator-=(difference_type n)
			{ _ptr -= n; return *this; }
			
			random_access_iterator& operator+=(difference_type n)
			{ _ptr += n; return *this; }

			difference_type operator-(const random_access_iterator & other) const 
			{ return (_ptr - other._ptr); }

			difference_type operator+(const random_access_iterator & other) const 
			{ return (_ptr + other._ptr); }

			difference_type operator-=(const random_access_iterator & other) const 
			{ *this = *this - other; return *this; }

			difference_type operator+=(const random_access_iterator & other) const 
			{ *this = *this - other; return *this; }
	
		private:
			iterator_type _ptr;
	};
}

#endif
