#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <stdexcept>
#include <typeinfo>

//only the type definitions for now.
namespace ft {
	template<class Key, class T, class Compare= std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
		class map {
			public:
				//type_defintions
				typedef Key key_type;
				typedef T	mapped_type;
				typedef ft::pair<const Key, T> value_type;
				typedef Compare  key_compare;
				typedef Alloc    allocator_type;
				typedef typename std::size_t	size_type;
				typedef typename std::ptrdiff_t	difference_type;
				typedef	typename allocator_type::reference	reference;
				typedef typename allocator_type::const_reference	const_reference;
				typedef	typename allocator_type::pointer	pointer;
				typedef typename allocator_type::const_pointer	const_pointer;

		};



}

#endif
