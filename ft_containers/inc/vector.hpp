#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <stdexcept>
#include <iostream>
#include <typeinfo>
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "ft_algorithm.hpp"


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

		 		template <class InputIterator>
					vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
							typename enable_if<!is_integral<InputIterator>::value>::type* = 0):
						_alloc(alloc), _size(last - first), _capacity(last - first), _buff(NULL) {
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
					if (!_capacity && !_size) 
						_reAlloc(1);
					else if (_size >= _capacity)
						_reAlloc(_capacity * 2);
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
					if (n < _size)
						_reAlloc(n);
					else if ( n > _size)
						_reSize(n, val);
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
					_fillErased(pos, size());
  					_size--;
					return (position);
				}
			
				iterator erase(iterator first, iterator last) {
					size_type range = _getRange(first, last);
					size_type pos = _getRange(begin(), first);
					size_type remains = _getRange(last, end());

					for (size_type i = pos; i < range; i++)
						_alloc.destroy(_buff + i);
					size_type next = 0;
            		for (size_type i = pos; i < remains; i++) {
						value_type val = *(_buff + remains + next);
						_fillErased(pos, size(), val);
						next++;
 					}
					_size -= range;
					return (first);
				}

				void swap (vector& x) {
					vector tmp = *this;
					*this = x;
					x = tmp;
				}

				//insert single element
				
				/*Plan -> Reallocate when supasses the capacity
				 * insert the new element in their position
				 * rellocate the elements after the new position*/
				iterator insert (iterator position, const value_type& val) {
					size_type pos = _getRange(begin(), position);
					if (_size + 1 > _capacity) {
						_reAlloc(_size + 1);
						//toDo()
					}
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

				bool empty()
				{ return (!_size ? true : false); }


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
				//function that will reallocate the vector size in resize;
				void	_reSize(size_type n, value_type val = value_type()) {
					value_type element = 0;		
					if (val)
						element = val;
					for (size_type i = _size; i < n; i++) {
						_alloc.construct(_buff + i, element);
					}
					_size = n;
					if (n > _capacity)
						_reAlloc(n * 2);
				}
				//function that will fill the blank spaces left by erase function;
				void	_fillErased(size_type start, size_type end, value_type fill = value_type()) {
					if (fill) {
						_alloc.destroy(_buff + start);
						_alloc.construct(_buff + start, fill);
						return ;
					}
					for (size_type i = start; i < end; i++) {
						size_type next = i + 1;	
						_alloc.destroy(_buff + i);
						_alloc.construct(_buff + i,  *(_buff + next));
					}
				}
				
				//get a range between two iterators
				difference_type _getRange(iterator first, iterator last)
				{ return (last - first); }

			protected:
				allocator_type  _alloc;
				size_type		_size;
				size_type		_capacity;
				pointer			_buff;
	};
}

template <class T, class Alloc>
	void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y)
	{ x.swap(y); }

template <class T, class Alloc>
	bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end()), rhs.begin());
		return (false);
	}

template <class T, class Alloc>
	bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{ return (!(lhs == rhs)); }

template <class T, class Alloc>
	bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

template <class T, class Alloc>
	bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{ return (!(lhs < rhs)); }
	
template <class T, class Alloc>
	bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{ return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end())); }

template <class T, class Alloc>
	bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
	{ return (!(lhs < rhs)); }


#endif
