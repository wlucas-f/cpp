#include <cctype>
#include <iostream>
#include <string>


int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	for (int count = 1; count < argc; ++count)
	{
		std::string str (argv[count]);
		if (count != 1)
			std::cout << ' ';
		size_t len = str.length();
		for (size_t i = 0; i < len; ++i)
			std::cout << (char) std::toupper(str[i]);
	}
	std::cout << '\n';
	return 0;
}
