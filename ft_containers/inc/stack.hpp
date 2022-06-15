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

                explicit stack (const container_type& ctnr = container_type()):  _ctnr(ctnr) {}

                bool empty() const
                { return _ctnr.empty(); }

                value_type& top()
                { return _ctnr.back(); }

                const value_type& top() const
                { return _ctnr.back(); }

                void push (const value_type& val)
                { _ctnr.push_back(val); }

                void pop()
                { _ctnr.pop_back(); }

                size_type size() const
                { return _ctnr.size(); }

                template <class U, class Other>
                    friend bool operator==(const stack<U, Other> &x, const stack<U, Other> &y)
                    { return x._ctnr == y._ctnr; }
                template <class U, class Other>
                    friend bool operator!=(stack<U, Other> const &x, stack<U, Other> const &y)
                    { return x._ctnr != y._ctnr; }
                template <class U, class Other>
                    friend bool operator<(stack<U, Other> const &x, stack<U, Other> const &y)
                    { return x._ctnr < y._ctnr; }
                template <class U, class Other>
                    friend bool operator<=(stack<U, Other> const &x, stack<U, Other> const &y)
                    { return x._ctnr <= y._ctnr; }
                template <class U, class Other>
                    friend bool operator>(stack<U, Other> const &x, stack<U, Other> const &y)
                    { return x._ctnr > y._ctnr; }
                template <class U, class Other>
                    friend bool operator>=(stack<U, Other> const &x, stack<U, Other> const &y)
                    { return x._ctnr >= y._ctnr; }

            protected:
                container_type _ctnr;
        };

        template <class T, class Container>
            bool operator== (const stack<T,Container>& x, const stack<T,Container>& y) {
	            return (x._ctnr == y._ctnr);
            }

        template <class T, class Container>
            bool operator!= (const stack<T,Container>& x, const stack<T,Container>& y){
                return (x._ctnr != y._ctnr);
            }

        template <class T, class Container>
            bool operator<  (const stack<T,Container>& x, const stack<T,Container>& y){
                return (x._ctnr < y._ctnr);
            }

        template <class T, class Container>
            bool operator<= (const stack<T,Container>& x, const stack<T,Container>& y){
                return (x._ctnr <= y._ctnr);
            }

        template <class T, class Container>
            bool operator>  (const stack<T,Container>& x, const stack<T,Container>& y){
                return (x._ctnr > y._ctnr);
            }

        template <class T, class Container>
            bool operator>= (const stack<T,Container>& x, const stack<T,Container>& y){
                return (x._ctnr >= y._ctnr);
            }
}

#endif