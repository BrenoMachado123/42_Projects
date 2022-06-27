#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <stdexcept>
#include <iostream>
#include <typeinfo>
#include <stdlib.h>
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "ft_algorithm.hpp"
#include <string>


//https://gcc.gnu.org/onlinedocs/gcc-4.6.3/libstdc++/api/a01115_source.html
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
				typedef typename ft::reverse_iterator<iterator>	reverse_iterator;
				typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;


				//construction
				explicit vector (const allocator_type& alloc = allocator_type()) :
				_alloc(alloc), _size(0), _capacity(0), _buff(pointer()) {}

				explicit vector( size_type count, const value_type& value = value_type(),
				const Allocator& alloc = Allocator()) :
				_alloc(alloc), _size(count), _capacity(count), _buff(pointer())  {
					if (!count)
						return ;
					if (count > max_size())
						throw std::length_error("cannot create std::vector larger than max_size()");
					_buff = _alloc.allocate(count);
					for (size_type i = 0; i < _size; i++) 
						_alloc.construct(_buff + i, value);
				}

				template <class InputIterator>
					vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
							typename enable_if<!is_integral<InputIterator>::value>::type* = 0):
						_alloc(alloc), _size(last - first), _capacity(last - first), _buff(pointer()) {
					if (_size > 0) {
						_buff = _alloc.allocate(_size);
						size_type i = 0;
						while (first != last) {
							_alloc.construct(_buff + i, *first);
							i++; first++;
						}
					}	
				}

				vector (const vector& x) :
				_alloc(x._alloc), _size(0),_capacity(0), _buff(NULL)
				{ *this = x; }

				~vector() {
					clear();
					if (_capacity > 0)
						_alloc.deallocate(_buff, _capacity);
					_capacity = 0;
				}

				// member functions

				void	push_back(const value_type& val) {
					if (!_capacity && !_size) 
						_reAlloc(1);
					else if (_size >= _capacity)
						_reAlloc(_capacity * 2);
					_alloc.construct(_buff + _size, val);
					_size++;
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
					if (n > _capacity)
						_reAlloc(n);
				}

				void resize (size_type n, value_type val = value_type()) {
					if (n < _size)
						_reAlloc(n, false);
					else if ( n > _size)
						_reSize(n, val);
					_size = n;
				}

				reference at (size_type n) {
					if (n < 0 || n >= _size)
						throw std::out_of_range("vector::at : _index_out_of_range");
					return (_buff[n]);
				}

				const_reference at (size_type n) const {
					if (n < 0 || n >= _size)
						throw std::out_of_range("vector::at : _index_out_of_range");
					return (_buff[n]);
				}

				template <class InputIterator>
					void assign(InputIterator first, InputIterator last,
						typename enable_if<!is_integral<InputIterator>::value>::type* = 0) {
						clear();
						_reAlloc(last - first);
						while (first != last)
						{ push_back(*first); first++; } 
				}

				void assign (size_type n, const value_type& val) {
					clear();
					_reAlloc(n);
					while (_size < n)
						push_back(val);
				}

				iterator erase(iterator position) {
					size_type pos = _getRange(begin(), position);
					_Erase(pos, size());
					_size--;
					return (position);
				}
			
				iterator erase(iterator first, iterator last) {
					size_type range = _getRange(first, last);
					size_type pos = _getRange(begin(), first);
					size_type remains = _getRange(last, end());

					for (size_type i = pos; i < range; i++)
						_alloc.destroy(_buff + i);
					for (size_type i = pos; remains > 0; i++) {
						_setValue(_buff + i, *(_buff + range + i));
						remains--;
					}
					_size -= range;
					return (first);
				}

				void swap (vector& x) {
					vector tmp = *this;
					*this = x;
					x = tmp;
				}

				iterator insert (iterator position, const value_type& val = value_type() ) {
					size_type pos = _getRange(begin(), position);
					if (_size + 1 >= _capacity)
						reserve(_size * 2);
					_moveElements(pos, 1);
					_setValue(_buff + pos, val);
					return (iterator(_buff + pos));
				}

				void insert (iterator position, size_type n, const value_type& val = value_type()) {
					size_type pos = _getRange(begin(), position);
					if ((_size + n) >= _capacity)
						reserve(_size * 2);
					_moveElements(pos, n);
					for (size_type i = 0; i < n; i++)
						_setValue((_buff + pos + i) , val);
				}

				template <class InputIterator>
					void insert (iterator position, InputIterator first, InputIterator last, 
					typename enable_if<!is_integral<InputIterator>::value>::type* = 0) {
						size_type pos = _getRange(begin(), position);
						size_type range = last - first;
						if (range >= _capacity)
							reserve(range + _size);
						_moveElements(pos, range);
						for (size_type i = 0; i < range; first++, i++)
							_setValue((_buff + pos + i) , *first);
					}
			

				//operators

				const_reference operator[](size_type index) const
				{ return reference (_buff[index]); }

				reference operator[](size_type index)
				{ return reference (_buff[index]); }

				allocator_type get_allocator() const {
					allocator_type copy_alloc;
					copy_alloc = _alloc;
					return (copy_alloc);
				}

				vector& operator=(const vector& other) {
					if (this != &other) {
						if (_capacity < other._size) {
							clear();
							_alloc.deallocate(_buff, _capacity);	
							_buff = _alloc.allocate(other._size);
						}
						else 
							clear();
						for (size_type i = 0; i < other._size; i++)
							_alloc.construct(_buff + i, other.at(i));
						_size = other.size();
						_capacity = other.capacity();
					}
					return *this;
				}

				//iterators
				iterator begin()
				{ return iterator(_buff); }

				iterator end()
				{ return iterator(_buff + _size); }

				const_iterator begin() const
				{return const_iterator(_buff); }

				const_iterator end() const
				{ return const_iterator(_buff + _size); }

				reference front()
				{ return reference(*begin()); }

				const_reference front() const
				{ return const_reference(*begin()); }

				reference back()
				{ return reference(*(end() - 1)); }
				
				const_reference back() const
				{ return const_reference(*(end() - 1)); }

				reverse_iterator rbegin()
				{ return reverse_iterator(end()); }

				const_reverse_iterator rbegin() const
				{ return const_reverse_iterator(end()); }

				reverse_iterator rend()
				{ return reverse_iterator(begin()); }

				const_reverse_iterator rend() const
				{ return const_reverse_iterator(begin()); }

				//return  members functions
				size_type max_size() const
				{ return _alloc.max_size(); }

				size_type size() const
				{ return _size; }

				size_type capacity() const
				{ return _capacity; }

				bool empty() const
				{ return (_size == 0); }


			private:
				//reallocate the vector capacity; 
				void	_reAlloc(size_type newCapacity, bool cap_change = true) {
					pointer newPtr;
					if (newCapacity > max_size())
						throw std::length_error("vector::reserve");
					newPtr = _alloc.allocate(newCapacity);
					if (newCapacity < _size)
						_size = newCapacity;
					for (size_type i = 0; i < _size; i++) {
						_alloc.construct(newPtr + i, _buff[i]);
						_alloc.destroy(_buff + i);
					}
					_alloc.deallocate(_buff, _capacity);
					_buff = newPtr;
					if (cap_change == true)
						_capacity = newCapacity;
				}

				//set a new value to a element in vector;
				void	_setValue(pointer element, value_type val) {
					_alloc.destroy(element);
					_alloc.construct(element, val);
				}

				//reallocate the vector size;;
				void	_reSize(size_type n, value_type val = value_type()) {
					if (n > capacity())
						_reAlloc(n);
					size_type range = n - size();	
					insert(end(), range, val);
				}

				//fill the blank spaces left by erase function with the next value;
				//void	_Erase(size_type start, size_type end, value_type& fill)
				void	_Erase(size_type start, size_type end) {
					for (size_type i = start; i < end; i++) {
						size_type next = i + 1;
						_alloc.destroy(_buff + i);
						_alloc.construct(_buff + i,  *(_buff + next));
					}
				}

				//move the elements of the vector;
				void	_moveElements(size_type start, size_type n) {
					vector copyVector = *this;
					iterator itr = copyVector.begin() + start;
					for (size_type i = 0; i < n ;i++)
						_sizeAlloc();
					for (size_type i = start + n; i < size(); itr++, i++)
						_setValue(_buff + i, *itr);
				}

				void	_sizeAlloc() {
					if (!_capacity && !_size) 
						_reAlloc(1);
					else if (_size >= _capacity)
						_reAlloc(_capacity * 2);
					_size++;
				}
				
				//get a range between two iterators;
				difference_type _getRange(iterator first, iterator last)
				{ return (last - first); }

			protected:
				allocator_type  _alloc;
				size_type		_size;
				size_type		_capacity;
				pointer			_buff;
		};

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{ x.swap(y); }

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (!(lhs == rhs)); }

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (!(rhs < lhs)); }

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end())); }

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (!(rhs > lhs)); }
}

#endif
