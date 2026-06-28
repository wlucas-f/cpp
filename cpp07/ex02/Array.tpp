#include "Array.hpp"
#include <cstddef>
#include <cstring>
#include <stdexcept>

template<class T>
Array<T>::Array():_size(0){
	arr = new T[0];
}

template<class T>
Array<T>::Array(unsigned int n): arr(NULL), _size(n){
	arr = new T[n];
}

template<class T>
Array<T>::Array(const Array& other):_size(other._size){
	this->arr = new T[other._size];
	for(unsigned int i = 0; i < other._size; i++)
		arr[i] = other.arr[i];
}

template<class T>
Array<T> &Array<T>::operator=(const Array& other){
	if(this == &other)
		return *this;
	T *temp = new T[other._size];
	delete this->arr;
	this->arr = temp;
	for(unsigned int i = 0; i < other._size; i++)
		arr[i] = other.arr[i];
	return(*this);
}

template<class T>
size_t Array<T>::size() const{
	return _size;
}

template<class T>
T& Array<T>::operator[](int index){
	if(index < 0 || static_cast<size_t>(index) >= size())
		throw OutOfBoundsException();
	return arr[index];
}

template<class T>
T& Array<T>::operator[](int index) const{
	if(index < 0 || static_cast<size_t>(index) >= size())
		throw OutOfBoundsException();
	return arr[index];
}

template<class T>
const char * Array<T>::OutOfBoundsException::what() const throw(){
	return "Out of bounds.";
}

template<class T>
Array<T>::~Array(){
	if(arr)
		delete[] arr;
}
