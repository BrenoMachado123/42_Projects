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
					friend class map<Key, T, Compare , Alloc>;
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
				typedef ft::BSTIter<value_type> iterator;
				typedef ft::BSTIter_const<value_type> const_iterator;
				typedef ft::BSTIter_rev<value_type> reverse_iterator;
				typedef ft::BSTIter_const_rev<value_type> const_reverse_iterator;
				
				//construction
				explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : 
				_tree(), _alloc(alloc), _kcmp(comp) {}

				template <class InputIterator>
					map (InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
       				const allocator_type& alloc = allocator_type()) : _alloc(alloc), _kcmp(comp)  {
						while (first != last)
							insert(*first++);
					}

				map(const map& other)
				{ *this = other; }

				~map() {}

				//member functions

				ft::pair<iterator,bool> insert (const value_type& val) {
					iterator itr = iterator(_tree.insert(val));
					bool ret = !(_tree.isNodeRepeated());
					return (ft::make_pair(itr,  ret));
				}

				iterator insert (iterator position, const value_type& val) {
					if (position == begin() or position == end()) {
						_tree.insert(val);
					}
					else if (!_isElementRepeated(val)) {
						_tree.insert_pos(_tree.search(position._bstPtr->data), val);
					}
					return (iterator(_tree.search(val)));
				}

				template <class InputIterator>
					void insert (InputIterator first, InputIterator last) {
						while(first != last)
							_tree.insert(*first++);
					}

				void erase (iterator position) {
					if (empty())
						return ;
					if (position == _tree.getEnd()) {
						this->~map();
						std::cerr << "free() : invalid pointer" << std::endl;
						std::abort();
					}
					_tree.deleteNode(*position);
				}
				
				size_type erase (const key_type& k) {
					if (!count(k))
						return 0;
					erase(find(k));
					return 1;
				}

				void erase (iterator first, iterator last) {
					while (first != last)
						erase(first++);
				}

				key_compare key_comp() const
				{ return (_kcmp); }

				value_compare value_comp() const
				{ return (_kcmp); }

				iterator begin()
				{ return (iterator(_tree.min())); }

				const_iterator begin() const
				{ return (const_iterator(_tree.min())); }

				iterator end()
				{ return (iterator(_tree.getEnd())); }

				const_iterator end() const
				{ return (const_iterator(_tree.getEnd())); }

				reverse_iterator rbegin()
				{ return (reverse_iterator(_tree.max())); }

				const_reverse_iterator rbegin() const
				{ return (const_reverse_iterator(_tree.max())); }

				reverse_iterator rend()
				{ return (reverse_iterator(_tree.getEnd())); }

				const_reverse_iterator rend() const
				{ return (const_reverse_iterator(_tree.getEnd())); }

				void clear()
				{ _tree.clear(); }

				bool empty()
				{ return _tree.isEmpty(); }

				size_type size() const
				{ return _tree.getSize(); }

				size_type count (const key_type& k) const{
					value_type p = ft::make_pair(k,mapped_type());
					if (_tree.search((p)))
						return 1;
					return 0;
				}

				iterator lower_bound (const key_type& k) {
					iterator start = begin();
					while (start != end() and key_comp()((*start).first, k))
						start++;
					return (start);
				}

				const_iterator lower_bound (const key_type& k) const {
					const_iterator start = begin();
					while (start != end() and key_comp()((*start).first, k))
						start++;
					return (start);
				}

				iterator upper_bound (const key_type& k) {
					iterator start = begin();
					while (start != end() and key_comp()((*start).first, k))
						start++;
					if (start != end())
						start++;
					return (start);
				}

				const_iterator upper_bound (const key_type& k) const {
					const_iterator start = begin();
					while (start != end() and key_comp()((*start).first, k))
						start++;
					if (start != end())
						start++;
					return (start);
				}

				ft::pair<iterator,iterator>	equal_range (const key_type& k)
				{ return ft::make_pair( lower_bound(k), upper_bound(k)); }

				ft::pair<const_iterator,const_iterator>	equal_range (const key_type& k) const
				{ return ft::make_pair( lower_bound(k), upper_bound(k)); }

				allocator_type get_allocator() const
				{ return _alloc; }

				iterator find (const key_type& k)
				{ return iterator(_tree.search( ft::make_pair(k, mapped_type()))); }

				const_iterator find (const key_type& k) const
				{ return const_iterator(_tree.search( ft::make_pair(k, mapped_type()))); }

				size_type max_size() const
				{ return _tree.maxSize(); }


				map& operator=(const map& other) {
					if (this != &other) {
						_tree = other._tree;
						_kcmp = other._kcmp;
					}
					return *this;
				}

				mapped_type& operator[] (const key_type& k) {
					if (!count(k)) {
						value_type p = ft::make_pair(k, mapped_type());
						insert(p);
					}
					return find(k)->second;
				}

				void swap (map& x) {
					map tmp = *this;
					*this = x;
					x = tmp;
				}

			private:
				bool _isElementRepeated(const value_type& key)
				{ return _tree.search(key) != _tree.getEnd(); }

			protected:
				ft::BST<value_type> _tree;
				allocator_type _alloc;
				key_compare _kcmp;
		};

		template <class Key, class T, class Compare, class Alloc>
  			bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
				  	if (lhs.size() == rhs.size())
						return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
					return (false);
			  }
		
		template <class Key, class T, class Compare, class Alloc>
  			bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
			{ return (!(lhs == rhs)); }

		template <class Key, class T, class Compare, class Alloc>
  			bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
			{ return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())); }

		template <class Key, class T, class Compare, class Alloc>
  			bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
			{ return (!(rhs > lhs)); }

		template <class Key, class T, class Compare, class Alloc>
  			bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
			{ return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end())); }

		template <class Key, class T, class Compare, class Alloc>
  			bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
			{ return (!(rhs < lhs)); }

		template <class Key, class T, class Compare, class Alloc>
  			void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
			{ x.swap(y); }
}

#endif
