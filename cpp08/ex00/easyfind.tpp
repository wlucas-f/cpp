#include "easyfind.hpp"
#include <algorithm>

template<typename T> typename T::iterator easyfind(T container, int toFind){

	typename T::iterator it = container.begin();
	it = std::find(container.begin(), container.end(), toFind);
	return it;
}
