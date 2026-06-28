#pragma once

#include <cstddef>
#include <exception>
template<class T>
class Array{
	private:
		T *arr;
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array &operator=(const Array& other);
		~Array();
		size_t size() const;
		class OutOfBoundsException : public std::exception{
			public:
				const char * what() const throw();
		};
		T& operator[](int index);
		T& operator[](int index) const;
};

#include "Array.tpp"
