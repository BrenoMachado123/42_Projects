#ifndef FT_PAIR_HPP
# define FT_PAIR_HPP

#include "./binary_search_tree.hpp"

//https://gcc.gnu.org/onlinedocs/libstdc++/libstdc++-html-USERS-4.3/a02030.html
namespace ft {
	template<class T1, class T2>
		struct pair {
			typedef T1	first_type;
			typedef T2	second_type;

			pair() : first(first_type()), second(second_type()) {}

			pair(const first_type& _first, const second_type& _second) : first(_first), second(_second) {}
				
			template<class U1, class U2>
				pair(const pair<U1, U2>& other)
				: first(other.first), second(other.second) {}

			pair& operator=(const pair& other) {
				if (this != &other) {
					first = other.first;
					second = other.second;
				}
				return *this;
			}

			void swap(pair& other) {
				pair tmp = *this;
				*this = other;
				other = tmp;
			}

			first_type first;
			second_type second;

		};

	template<class T1, class T2>
		bool operator==(const pair<T1,T2>& x, const pair<T1, T2>& y)
		{ return (x.first == y.first && x.second == y.second); }

	template<class T1, class T2>
		bool operator!=(const pair<T1,T2>& x, const pair<T1, T2>& y)
		{ return !(x == y); }
	
	template<class T1, class T2>
		bool operator<(const pair<T1,T2>& x, const pair<T1, T2>& y)
		{ return (y.first < x.first or (!(y.first < x.first) and x.second < y.second )); }

	template<class T1, class T2>
		bool operator>(const pair<T1,T2>& x, const pair<T1, T2>& y)
		{ return (y < x); }

	template<class T1, class T2>
		bool operator<=(const pair<T1,T2>& x, const pair<T1, T2>& y)
		{ return !(y < x); }

	template<class T1, class T2>
		bool operator>=(const pair<T1,T2>& x, const pair<T1, T2>& y)
		{ return !(x < y); }
	
	template<class T1, class T2>
		pair<T1, T2> make_pair(T1 x, T2 y)
		{ return (pair<T1, T2>(x,y)); }
	
	template<class T1, class T2>
		void swap(pair<T1,T2>& x, pair<T1,T2>& y)
		{ x.swap(y); }
}

#endif
