#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <cstring>

void displayResults(std::vector<int> &vec, int numArgs)
{
	std::cout << "Before: ";
	for(std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
	{
		std::cout << *it;
		if(it != vec.end() - 1)
			std::cout << " ";
	}
	std::cout << "\n";

	std::cout << "After: ";
	for(std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
	{
		std::cout << *it;
		if(it != vec.end() - 1)
			std::cout << " ";
	}
	std::cout << "\n";

	std::cout << "Time to process a rage of " << numArgs << " elements with std::vector : <time>\n";
	std::cout << "Time to process a rage of " << numArgs << " elements with std::deque : <time>\n";
}

template<typename T>
void mergeSort(T cont){
	if (cont.size() <= 1)
		return ;

	typename T::iterator it = cont.begin();
	int leftSize = cont.size() / 2;
	int rightSize = cont.size() - leftSize;
	int i, j;
	T left, right;

	for(; i < cont.size(); i++)
	{

	}


	std::pair<typename T1, typename T2>

}

int main(int argc, char **argv){
	if(argc < 3)
		return 1;

	std::vector<int> vec;
	std::deque<int> deq;

	for(int i = 0; i < argc - 1; i++)
	{
		vec.push_back(std::atoi(argv[i + 1]));
		deq.push_back(std::atoi(argv[i + 1]));
	}

//	mergeSort(vec);

	displayResults(vec, argc - 1);
}
