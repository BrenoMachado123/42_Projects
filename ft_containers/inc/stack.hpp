#ifndef STACK_HPP
# define STACK_HPP

#include <iostream>
#include "vector.hpp"

namespace ft {
    template<class T, class Container = ft::vector<T> >
        class stack {
            public:
                typedef Container container_type;
                typedef typename container_type::value_type value_type;
                typedef typename container_type::size_type size_type;

                explicit stack (const container_type& ctnr = container_type()) :
                c(ctnr) {}

                bool empty() const
                { return c.empty(); }

                value_type& top()
                { return c.back(); }

                const value_type& top() const
                { return c.back(); }

                void push (const value_type& val)
                { c.push_back(val); }

                void pop()
                { c.pop_back(); }

                size_type size() const
                { return c.size(); }

                template <class U, class V>
                    friend bool operator==(const stack<U, V> &x, const stack<U, V> &y);
                template <class U, class V>
                    friend bool operator!=(stack<U, V> const &x, stack<U, V> const &y);
                template <class U, class V>
                    friend bool operator<(stack<U, V> const &x, stack<U, V> const &y);
                template <class U, class V>
                    friend bool operator<=(stack<U, V> const &x, stack<U, V> const &y);
                template <class U, class V>
                    friend bool operator>(stack<U, V> const &x, stack<U, V> const &y);
                template <class U, class V>
                    friend bool operator>=(stack<U, V> const &x, stack<U, V> const &y);

            protected:
                container_type c;
        };

        template <class T, class Container>
            bool operator== (const stack<T,Container>& x, const stack<T,Container>& y) {
	            return (x.c == y.c);
            }

        template <class T, class Container>
            bool operator!= (const stack<T,Container>& x, const stack<T,Container>& y){
                return (x.c != y.c);
            }

        template <class T, class Container>
            bool operator<  (const stack<T,Container>& x, const stack<T,Container>& y){
                return (x.c < y.c);
            }

        template <class T, class Container>
            bool operator<= (const stack<T,Container>& x, const stack<T,Container>& y){
                return (x.c <= y.c);
            }

        template <class T, class Container>
            bool operator>  (const stack<T,Container>& x, const stack<T,Container>& y){
                return (x.c > y.c);
            }

        template <class T, class Container>
            bool operator>= (const stack<T,Container>& x, const stack<T,Container>& y){
                return (x.c >= y.c);
            }
}

#endif