#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(){
	std::vector<int> v;

	for(int i = 0; i < 10; i++)
		v.push_back(i);

	std::vector<int>::iterator it = easyfind(v, 7);
	if(it != v.end())
		std::cout << *it << "\n";
}
