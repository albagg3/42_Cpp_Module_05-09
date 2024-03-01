#include <iostream>
#include <fstream>
#include "PmergeMe.hpp"

int main (int argc, char** argv)
{
	(void) argc;
	(void) argv;
	try
	{
		if (argc == 2)
			// Rpn test(argv[1]);
		else
			// std::cout << "Please provide input for example: '1 2 * 2 / 2 * 2 4 - +'" << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
};