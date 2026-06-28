#include "easyfind.hpp"
#include <algorithm>
#include <istream>
#include <iterator>
#include <iostream>

template<typename T> void easyfind(T container, int toFind){
	int it = std::find(container.begin(), container.end(), toFind);
	if(it == container.end())
		throw NotFoundException();
	std::cout << toFind << " was found in the position " << it << " of the container\n";
}

const char *NotFoundException::what() const throw(){
	return "Element not found";
}
