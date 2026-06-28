#pragma once

#include <exception>

template<typename T> void easyfind(T container, int toFind);
class NotFoundException : public std::exception{
	public:
		const char *what() const throw();
};
