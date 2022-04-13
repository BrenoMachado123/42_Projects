#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <stdexcept>
#include <iostream>
#include <typeinfo>
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft {
	template<class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			//type_defintions
			typedef T	value_type;
			typedef Allocator	allocator_type;
			typedef typename std::size_t	size_type;
			typedef typename std::ptrdiff_t	difference_type;
			typedef	typename allocator_type::reference	reference;
			typedef typename allocator_type::const_reference	const_reference;
	 		typedef	typename allocator_type::pointer	pointer;
			typedef typename allocator_type::const_pointer	const_pointer;
			typedef typename ft::random_access_iterator<pointer>	iterator;
			typedef typename ft::random_access_iterator<const_pointer>	const_iterator;
			typedef typename ft::reverse_iterator<pointer>	reverse_iterator;
			typedef typename ft::reverse_iterator<const_pointer>	const_reverse_iterator;


			//construction
			explicit vector (const allocator_type& alloc = allocator_type()) :
			_alloc(alloc), _size(0), _capacity(0), _buff(NULL) {}

			explicit vector( size_type count, const value_type& value = value_type(),
			const Allocator& alloc = Allocator()) :
			_alloc(alloc), _size(count), _capacity(count), _buff(NULL)  {
				if (count > max_size()) {
					throw std::length_error("cannot create std::vector larger than max_size()");
				}
				_buff = _alloc.allocate(count);
				for (size_type i = 0; i < _size; i++) { 
					_alloc.construct(_buff + i, value);
				}
			}

		 /*template <class InputIterator>
         	vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type()) {
			}*/ // implenting iterators to use this constructor

			vector (const vector& x) :
			_alloc(x._alloc), _size(0),_capacity(0), _buff(NULL) {
				*this = x;
			}

			~vector() {
				clear();
				if (_capacity > 0)
					_alloc.deallocate(_buff, _capacity);
			}

			// member functions

			void	push_back(const value_type& val) {
				if (!_capacity && !_size) { 
					_reAlloc(1);
				} else if (_size >= _capacity) {
					_reAlloc(_capacity * 2);
				}
				_buff[_size++] = val;	
			}

			void	pop_back() {
				_alloc.destroy(_buff + _size - 1);
				if (_size > 0) { _size--; }	
			}

			void	clear() {
				for (size_type i=0; i < _size; i++)
					_alloc.destroy(_buff + i);
				_size = 0;
			}

			void	reserve(size_type n) {
				if (n > _capacity) { _reAlloc(n); }
			}

			void resize (size_type n, value_type val = value_type()) {
				if (n < _size) {
					_reAlloc(n);
				} else if ( n > _size) {
					_reSize(n, val);
				}
			}

			reference at (size_type n) {
				if (n < 0 || n >= _size)
					throw std::out_of_range("vector");
				return (_buff[n]);
			}

			const_reference at (size_type n) const {
				if (n < 0 || n >= _size)
					throw std::out_of_range("vector");
				return (_buff[n]);
			}

			//operators

			const_reference operator[](size_type index) const {
				return reference (_buff[index]);
			}

			reference operator[](size_type index) {
				return reference (_buff[index]);
			}

			allocator_type get_allocator() const {
				allocator_type copy_alloc;
				copy_alloc = _alloc;
				return (copy_alloc);
			}

			vector& operator=(const vector& other) {
				if (this != &other) {
					this->~vector();
					_size = other.size();
					_capacity = other.capacity();	
					_buff = _alloc.allocate(_size);
					for (size_type i = 0; i < _size; i++) {
						_alloc.construct(_buff + i, other.at(i));
					}
				}
				return *this;
			}

			//iterators
			iterator	begin() { return iterator(_buff); }
			iterator end() { return iterator(_buff + _size); }
			const_iterator begin() const { return const_iterator(_buff); }
			const_iterator end() const { return const_iterator(_buff + _size); }
			reference front() { return reference(*_buff); }
			const_reference front() const { return const_reference(*_buff); }
			reverse_iterator rbegin() { return reverse_iterator(_buff + _size - 1); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(_buff + _size - 1); }
			reverse_iterator rend() { return reverse_iterator(_buff - 1); }
			const_reverse_iterator rend() const { return const_reverse_iterator(_buff - 1); }

			//return  members functions
			size_type max_size() const { return _alloc.max_size(); }
			size_type size() const { return _size; }
			size_type capacity() const { return _capacity; }
			bool empty() { return (!_size ? true : false); }


		private:
			//function that will reallocate the vector size in general; 
			void	_reAlloc(size_type newCapacity) {
				pointer newPtr;
				newPtr = _alloc.allocate(newCapacity);
				if (newCapacity < _size)
					_size = newCapacity;
				for (size_type i = 0; i < _size; i++) {
					_alloc.construct(newPtr + i, _buff[i]);
					_alloc.destroy(_buff + i);
				}
				_alloc.deallocate(_buff, _capacity);
				_buff = newPtr;
				_capacity = newCapacity;
			}
			//function that will reallocate the vector size in resize
			void	_reSize(size_type n, value_type val = value_type()) {
				value_type element = 0;		
				if (val) { element = val; }
				for (size_type i = _size; i < n; i++) {
					_alloc.construct(_buff + i, element);
				}
				_size = n;
				if (n > _capacity) { _reAlloc(n * 2); }
			}
		private:
			allocator_type _alloc;
			size_type		_size;
			size_type		_capacity;
			pointer			_buff;
	};
}

#endif
