#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(){}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other):std::stack<T>(other){
	(void) other;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &other){
	(void) other;
	return *this;
}

template<typename T>
typename std::deque<T>::iterator MutantStack<T>::begin(){
	return this->c.begin();
}

template<typename T>
typename std::deque<T>::iterator MutantStack<T>::end(){
	return this->c.end();
}

template<typename T>
MutantStack<T>::~MutantStack(){}
