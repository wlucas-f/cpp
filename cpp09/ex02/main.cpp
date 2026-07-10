#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>
#include <deque>
#include <cstring>
#include <cctype>

void displayResults(int argc, char **argv, std::vector<int> &vec)
{
    std::cout << "Before: ";
    for(int i = 0; i < argc - 1; i++)
    {
        std::cout << argv[1 + i];
       	if(i != argc - 1)
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

    std::cout << "Time to process a rage of " << argc - 1 << " elements with std::vector : <time>\n";
    std::cout << "Time to process a rage of " << argc - 1 << " elements with std::deque : <time>\n";
}

template<typename T>
void mergeInsertionSort(T cont){
    if (cont.size() <= 1)
        return ;

    typename T::iterator it = cont.begin();
    std::vector<std::pair<int, int>> pairs;
    pairs.push_back(std::make_pair(0, 0));
    std::vector<std::pair<int, int>>::iterator pit;

    for(; it+1 != cont.end(); it += 2)
    {
        if(*it > *(it+1))
            pairs.push_back(std::make_pair(*it, *(it+1)));
        else
            pairs.push_back(std::make_pair(*(it+1), *it));
    }

    mergeInsertionSort(pairs);

}

bool is_digits(char *arg)
{
    std::string str(arg);
    return(std::all_of(str.begin(), str.end(), ::isdigit));
}

int main(int argc, char **argv){
    if(argc < 3)
        return 1;

    std::vector<int> vec;
    std::deque<int> deq;
    int value;
    char *end = NULL;


    for(int i = 0; i < argc - 1; i++)
    {
        if(!is_digits(argv[i + 1]))
        {
            std::cerr << "Invalid input";
            return (1);
        }

        value = std::strtod(argv[i + 1], &end);
        if(std::find(vec.begin(), vec.end(), value) != vec.end())
        {
            std::cerr << "Duplicate input";
            return (1);
        }
        vec.push_back(value);
        deq.push_back(value);
    }

    mergeInsertionSort(vec);

    displayResults(argc, argv, vec);
}
