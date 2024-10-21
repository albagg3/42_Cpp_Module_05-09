#include <iostream>
#include <fstream>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	try
	{
		if (argc < 2)
		{
			std::cerr << "Error: No sequence provided." << std::endl;
			return 1;
		}

		std::vector<int> vec;
		std::deque<int> deq;

		for (int i = 1; i < argc; ++i)
		{
			int num = std::atoi(argv[i]);
			if (num <= 0)
			{
				std::cerr << "Error: Invalid number '" << argv[i] << "'." << std::endl;
				return 1;
			}
			vec.push_back(num);
			deq.push_back(num);
		}

		PmergeMe sorter;

		std::cout << "Before: ";
		sorter.printContainerVec(vec);

		// Ordenar usando std::vector
		clock_t start_vec = clock();
		sorter.mergeInsertSortVector(vec);
		clock_t end_vec = clock();

		std::cout << "After: ";
		sorter.printContainerVec(vec);

		// Ordenar usando std::deque
		clock_t start_deq = clock();
		sorter.mergeInsertSortDeque(deq);
		clock_t end_deq = clock();

		double time_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;
		double time_deq = static_cast<double>(end_deq - start_deq) / CLOCKS_PER_SEC;

		std::cout << "Time to process with std::vector: " << time_vec << " s" << std::endl;
		std::cout << "Time to process with std::deque: " << time_deq << " s" << std::endl;

		return 0;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
};