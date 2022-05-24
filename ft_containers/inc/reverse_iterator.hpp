#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"

//https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator.h.html#std::reverse_iterator::current

namespace ft {
	template<class Iterator>
	class reverse_iterator {
		public:
			typedef ft::iterator_traits<Iterator>						traits_type;
			
			typedef Iterator									iterator_type;
			typedef typename traits_type::value_type			value_type;
			typedef typename traits_type::difference_type		difference_type;
			typedef typename traits_type::pointer				pointer;
			typedef typename traits_type::reference				reference;
			typedef typename traits_type::iterator_category		iterator_category;

			reverse_iterator() : _ptr() {}
			explicit reverse_iterator(iterator_type ptr) : _ptr(ptr) {}
			reverse_iterator(const reverse_iterator& other) { *this = other; }
			reverse_iterator& operator=(const reverse_iterator& other) {
				if (this != &other)
					this->_ptr = other._ptr;
				return (*this);
			}
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter> & other) : 
				_ptr(other.base()) {};
	
			~reverse_iterator() {};

			iterator_type base() const
			{ return (_ptr); }

			reverse_iterator operator++() {
				--_ptr; 
				return (*this);
			}
			reverse_iterator operator++(int) {
				reverse_iterator tmp = *this; 
				--_ptr;
				return (tmp);
			}

			reverse_iterator operator--() {
				++_ptr; 
				return (*this);
			}
			reverse_iterator operator--(int) { 
				reverse_iterator tmp = *this;
				++_ptr;
				return (tmp);
			}

			reverse_iterator operator+(difference_type n)
			{ return reverse_iterator(_ptr - n); }

			reverse_iterator operator-(difference_type n)
			{ return reverse_iterator(_ptr + n); }

			reverse_iterator operator+=(difference_type n)
			{ _ptr -= n; return *this; }

			reverse_iterator operator-=(difference_type n)
			{ _ptr += n; return *this; }

			pointer operator->()
			{ return (_ptr); }

			reference	operator[](size_t n)
			{ return base()[-n-1]; }
	
			reference operator*() const {
				iterator_type tmp = _ptr;
				return *--tmp;
			}

			reference	operator[](size_t n) const { return base()[-n-1]; }
			bool operator==(const reverse_iterator& other)
			{ return (this->_ptr == other._ptr); }

			bool operator!=(const reverse_iterator& other)
			{ return (this->_ptr != other._ptr); }
					
		private:
			iterator_type _ptr;
	};
}

#endif

