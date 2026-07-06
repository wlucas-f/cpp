#include "MutantStack.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
	std::cout << "---Subject test---\n";
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "---Extra test---\n";
	{
		MutantStack<int> mstack;

		srand((unsigned int)time(NULL));
		for(int i = 0; i < 10001; i++){
			int random = rand() % 100 + (i * 10);
			mstack.push(random);
		}
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		for(int i = 0; i < 10000; i++){
			mstack.pop();
		}
		std::cout << mstack.size() << std::endl;
	}
}
