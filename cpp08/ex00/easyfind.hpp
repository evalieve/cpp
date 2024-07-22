#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <vector>
# include <iostream>
# include <list>
# include "Color.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::range_error(RED "Easyfind exception: Element not found!" NC);
    }
    return it;
}

#endif