/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:11:31 by albagarc          #+#    #+#             */
/*   Updated: 2024/03/01 12:23:57 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


//********* AUX FUNCTIONS *************//

//Transforms a std::string to float
float transformStrFloat(std::string value)
{
	const char *cstr = value.c_str();
	float numDouble = atof(cstr);
	return numDouble;
}

//Checks if a string is a valid number
bool strAreDigits(const char *number)
{
	for(size_t i = 0; i < strlen(number); i++)
	{
		if(!isdigit(number[i]))
			return false;
	}
	return true;
}

//Checks if the date is valid
bool validYearMonthDay(const char *year, const char *month, const char *day)
{
	if (!strAreDigits(year) || !strAreDigits(month) || !strAreDigits(day))
	{
		std::cout << RED << "Error: year, month and day should be numbers." << RESET << std::endl;
		return false;
	}
	if (!atoi(year) || !(atoi(year) >= 2009))
	{
		std::cout << RED << "Error: too low year, no data before 2009-01-02." << RESET << std::endl;
		return false;
	}
	if (!atoi(month) || !(atoi(month) > 0) || !(atoi(month) < 13))
	{
		std::cout << RED << "Error: the month should be between 1 and 12" << RESET << std::endl;
		return false;
	}
	if (atoi(day) && atoi(day) > 0)
	{
		if (atoi(month) == 2)
		{
			if (atoi(day) > 29)
			{
				std::cout << RED << "Error: this month only have 28 days max." << RESET << std::endl;
				return false;
			}
		}
		else if (atoi(month) == 1 || atoi(month) == 3 || atoi(month) == 5 || atoi(month) == 7 || atoi(month) == 8 || atoi(month) == 10 || atoi(month) == 12)
		{
			if (atoi(day) > 31)
			{
				std::cout << RED << "Error: this month only have 31 days max." << RESET << std::endl;
				return false;
			}
		}
		else
		{
			if (atoi(day) > 30)
			{
				std::cout << RED << "Error: this month only have 30 days max." << RESET << std::endl;
				return false;
			}
		}
	}
	return true;
}


//Checks if the numbers are valid the input and the dataBase have different requirements thats why you can turn on/off the flag dataBase
bool validNum(std::string num, bool dataBase)
{
	float numDouble = transformStrFloat(num);
	if (num != "0" && !numDouble)
	{
		std::cout << RED << "Error: not a number" << RESET << std::endl;
		return false;
	}
	if (numDouble > 1000 && !dataBase)
	{
		std::cout << RED << "Error: too large number." << RESET << std::endl;
		return false;
	}
	if (numDouble < 0)
	{
		std::cout << RED << "Error: not a positive number." << RESET << std::endl;
		return false;
	}
	return true;
}

//This function checks the number of delimiters in the dataBase the delimiter is "," in the input file is " | " in the dates is "-"
int howManyDelimiters(std::string str, std::string delimiter)
{
	int times = 0;
	std::string::size_type pos = 0;
	while ((pos = str.find(delimiter, pos)) != std::string::npos)
	{
		++times;
		pos += delimiter.length();
	}
	return times;
}

//This function checks if the amount of delimiters is valid. Depending on the type of delimiter the valid amount is different
bool	validNumberOfDelimiters(std::string line, std::string delimiter)
{
	int amount = 0;
	amount = howManyDelimiters(line, delimiter);
	
	if (delimiter == "," || delimiter == "|")
	{
		if (amount != 1)
			return false;
		if(delimiter == "|" && amount == 1)
		{
			if(!howManyDelimiters(line, " | "))
				return false;
		}
	}
	if (delimiter == "-")
	{
		if (amount != 2)
			return false;
	}
	return true;
}

//This function checks if the date has a valid format
bool validDate(std::string date)
{
	if (!validNumberOfDelimiters(date, "-"))
	{
		 std::cout << RED << "Error: wrong date format." << RESET << std::endl;
		return false;
	}
	
	if (date.length() != 10)
	{
		 std::cout << RED << "Error: wrong date format." << RESET << std::endl;
		return false;
	}

	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);

	const char *year_charptr = const_cast<char *>(year.c_str());
	const char *month_charptr = const_cast<char *>(month.c_str());
	const char *day_charptr = const_cast<char *>(day.c_str());

	if (validYearMonthDay(year_charptr, month_charptr, day_charptr))
		return true;
	return false;
}


//********* BITCOIN CLASS *************//

//CONSTRUCTOR
BitcoinExchange::BitcoinExchange()
{
	std::cout << GREY << "Default BitcoinExchange constructor called" << RESET << std::endl;
}

// CONSTRUCTOR WITH INPUT AND DATABASE
BitcoinExchange::BitcoinExchange(std::ifstream &inputFile, std::ifstream &dataBase)
{
	(void)inputFile;
	if (!this->_validDataBase(dataBase))
		throw BitcoinExchange::InvalidDataBase();
	this->_exchangeInput(inputFile);

	std::cout << GREY << "BitcoinExchange constructor with files called" << RESET << std::endl;
}

//COPY CONSTRUCTOR
BitcoinExchange::BitcoinExchange(const BitcoinExchange &original)
{
	*this = original;
}

//DESTRUCTOR
BitcoinExchange::~BitcoinExchange()
{
	std::cout << GREY << "Default BitcoinExchange destructor called" << RESET << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this == &rhs)
		return *this;
	this->_dataBase = rhs._dataBase;
	return *this;
}

//EXCEPTIONS

const char *BitcoinExchange::InvalidDataBase::what() const throw()
{
	return ("The dataBase file is not well formatted");
}

//MEMBER FUNCTIONS

//This function validates the DB and save the data in our class
bool BitcoinExchange::_validDataBase(std::ifstream &dataBase)
{
	std::string line;
	std::string	date;
	std::string	value;

	while (std::getline(dataBase, line))
	{
		if (line == "date,exchange_rate")
			continue;
		if (!validNumberOfDelimiters(line, ","))
			return false;
		date = line.substr(0,line.find(","));
		value = line.erase(0, line.find(",") + 1);
		if (validDate(date) && validNum(value, true))
		{
			float numDouble = transformStrFloat(value);
			this->_dataBase[date] = numDouble;
		}
		else
			return false;
	}
	return true;
}


//Takes line by line the input validate it and give a result or give an error message
void	BitcoinExchange::_exchangeInput(std::ifstream& inputFile)
{
	std::string line;
	int	empty = 1;
	std::string	date;
	std::string	value;
	std::map<std::string, float>::iterator it;
	std::map<std::string, float>::iterator prevIt;

	while (std::getline(inputFile, line) )
	{
		empty = 0;
		if (line == "date | value")
			continue;
		if (!validNumberOfDelimiters(line, "|"))
		{
			std::cout << RED << "Error: bad input => " << line << RESET << std::endl;
			continue;
		}

		date = line.substr(0,line.find("|") - 1);
		value = line.erase(0, line.find("|") + 2);
		
		if (validDate(date) && validNum(value, false))
		{
			float numDouble = transformStrFloat(value);
			it = this->_dataBase.find(date);
			if (it != this->_dataBase.end())
				std::cout << date << " => " << value << " * " << it->second << " = " << numDouble * it->second <<std::endl;
			else
			{
				prevIt = this->_dataBase.begin();
				for(it = this->_dataBase.begin(); it != this->_dataBase.end(); it++ )
				{
					if (date.compare(it->first) < 0)
					{
						std::cout << date << " => " << value << " * " << prevIt->second << " = " << numDouble * prevIt->second << std::endl;
						break;
					}
					prevIt = it;
				}
			}
		}
	}
	if(inputFile.eof() && empty)
		std::cout << RED << "Error: Empty input file" << line << RESET << std::endl;
}


