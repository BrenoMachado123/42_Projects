#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& src, int target) {
	typename T::iterator ocurrence;
	ocurrence = std::find(src.begin(), src.end(), target);
	if (ocurrence == src.end()) { throw target; }
	return (ocurrence);
}

#endif
