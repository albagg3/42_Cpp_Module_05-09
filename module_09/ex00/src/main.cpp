#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main (int argc, char** argv)
{
	if(argc != 2)
	{
		std::cerr << "Please add an input file as an argument" << std::endl;
		return (1);
	}
	try
	{
		std::ifstream	inputFile(argv[1]);
		std::ifstream	dataBase("src/data.csv");
		if(!inputFile.is_open() || !dataBase.is_open())
		{
			std::cerr << "There was an error opening the files, review the paths." << std::endl;

		}
		else
		{
			BitcoinExchange one(inputFile, dataBase) ;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
};