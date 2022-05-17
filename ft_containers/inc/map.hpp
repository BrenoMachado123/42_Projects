#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include "binary_search_tree.hpp"
#include "binary_search_tree_itr.hpp"
#include "binary_search_tree_revitr.hpp"
#include "ft_pair.hpp"

namespace ft {
	template<class Key, class T, class Compare= std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
		class map {
			public:
				//type_defintions
				typedef Key key_type;
				typedef T	mapped_type;
				typedef ft::pair<key_type, mapped_type> value_type;
				typedef Compare  key_compare;

				class value_compare
				: public std::binary_function<value_type,value_type,bool> {
					friend class map<Key, T, Alloc>;
					protected:
						Compare _comp;
					
						value_compare(Compare c)
						: _comp(c) {}

					public:
						bool operator()(const value_type& x, const value_type& y) const
						{ return _comp(x.first, y.first); }
				};

				typedef Alloc    allocator_type;
				typedef typename std::size_t	size_type;
				typedef typename std::ptrdiff_t	difference_type;
				typedef	typename allocator_type::reference	reference;
				typedef typename allocator_type::const_reference	const_reference;
				typedef	typename allocator_type::pointer	pointer;
				typedef typename allocator_type::const_pointer	const_pointer;
				typedef ft::BSTIter<Key, T> iterator;
				typedef ft::BSTIter<Key, T>& const_iterator;
				typedef ft::BSTIter_rev<Key, T> reverse_iterator;
				typedef ft::BSTIter_rev<Key, T>& const_reverse_iterator;
				
				//construction
				explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : 
				_alloc(alloc), _kcmp(comp) {}

				map(const map& other)
				{ *this = other; }

				~map() {}

				//member functions

				ft::pair<iterator,bool> insert (const value_type& val) {
					if (_isElementRepeated(val))
						return (ft::make_pair(iterator(_tree.search(val)), false));
					_tree.insert(val);
					return (ft::make_pair(iterator(_tree.search(val)), true));
				}

				iterator insert (iterator position, const value_type& val) {
					if (position == begin() or position == end()) {
						insert(val);
						return (iterator(_tree.search(val)));
					}
					if (!_isElementRepeated(val)) {
						_tree.insert_pos(_tree.search(position._bstPtr->data), val);
						return (iterator(_tree.search(val)));
					}
					return (iterator(_tree.search(val)));
				}

				iterator begin()
				{ return (iterator(_tree.min())); }

				const_iterator begin() const
				{ return (const_iterator(_tree.min())); }

				iterator end()
				{ return (iterator(NULL)); }

				const_iterator end() const
				{ return (const_iterator(NULL)); }

				reverse_iterator rbegin()
				{ return (reverse_iterator(_tree.max())); }

				const_reverse_iterator rbegin() const
				{ return (const_reverse_iterator(_tree.max())); }

				reverse_iterator rend()
				{ return (reverse_iterator(NULL)); }

				const_reverse_iterator rend() const
				{ return (const_reverse_iterator(NULL)); }

				void clear() {
					_tree.clear();
				}

				bool empty()
				{ return _tree.isEmpty(); }

				size_type size() {
					return _tree.getSize();
				}

				size_type count (const key_type& k) const{
					value_type p = ft::make_pair(k,mapped_type());
					if (_tree.search((p)))
						return 1;
					return 0;
				}

				allocator_type get_allocator() const {
					return _alloc;
				}

				iterator find (const key_type& k)
				{ return iterator(_tree.search( ft::make_pair(k, mapped_type()))); }

				const_iterator find (const key_type& k) const
				{ return const_iterator(_tree.search( ft::make_pair(k, mapped_type()))); }

				size_type max_size() const
				{ return _alloc.max_size(); }

				void Printtest() {
					_tree.inorder();
				}

			private:
				bool _isElementRepeated(const value_type& key)
				{ return _tree.search(key) != NULL; }

			protected:
				ft::BST<value_type> _tree;
				allocator_type _alloc;
				key_compare _kcmp;
		};



}

#endif
