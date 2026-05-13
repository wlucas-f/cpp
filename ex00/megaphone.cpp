#include <cctype>
#include <iostream>
#include <string>


int main(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for(int count{ 1 }; count < argc; ++count)
	{
		std::string phrase {};
		phrase = argv[count];
		if (count != 1)
			std::cout << ' ';
		for (auto& x : phrase) {
			x = toupper(x);
		}
		std::cout << phrase;
	}
	std::cout << '\n';
	return 0;
}
