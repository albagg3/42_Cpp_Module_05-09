/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:11:31 by albagarc          #+#    #+#             */
/*   Updated: 2024/02/28 22:22:17 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

float transformStrFloat(std::string value)
{
	const char *cstr = value.c_str();
	float numDouble = atof(cstr);
	return numDouble;
}

bool validYearMonthDay(const char *year, const char *month, const char *day)
{

	// std::cout << "VAMOS A VALIDAR LA FECHA" << std::endl;
	if (!atoi(year) || !(atoi(year) >= 2009))
	{

		std::cout << RED << "ano menor que 2009" << RESET << std::endl;
		return false;
	}
	if (!atoi(month) || !(atoi(month) > 0) || !(atoi(month) < 13))
	{
		std::cout << RED << "el mes es > que 12 o < que 1" << RESET << std::endl;
		return false;
	}
	if (atoi(day) && atoi(day) > 0)
	{
		if (atoi(month) == 2)
		{
			if (atoi(day) > 29)
			{
				std::cout << RED << "febrero no tiene 30 dias" << RESET << std::endl;
				return false;
			}
		}
		else if (atoi(month) == 1 || atoi(month) == 3 || atoi(month) == 5 || atoi(month) == 7 || atoi(month) == 8 || atoi(month) == 10 || atoi(month) == 12)
		{
			if (atoi(day) > 31)
			{
				std::cout << RED << "meses con 31 dias max" << RESET << std::endl;
				return false;
			}
		}
		else
		{
			if (atoi(day) > 30)
			{
				std::cout << RED << "meses con 30 dias max" << RESET << std::endl;
				return false;
			}
		}
	}
	// std::cout << GREEN << "fechaa OK " << RESET << std::endl;
	return true;
}

bool validNum(std::string num, bool dataBase)
{
	float numDouble = transformStrFloat(num);
	if (num != "0" && !numDouble)
	{
		std::cout << RED << "atof no puede convertirlo" << RESET << std::endl;
		return false;
	}
	//SOLO PARA LOS INPUTS
	if (numDouble > 1000 && !dataBase)
	{
		std::cout << RED << "The subject says that the value can't be bigger than 1000" << RESET << std::endl;

		return false;
	}
	if (numDouble < 0)
	{
		std::cout << RED << "menor que 0" << RESET << std::endl;
		return false;
	}
	return true;
}

int howManyDelimiters(std::string str, std::string delimiter)
{
	int times = 0;
	std::string::size_type pos = 0;
	while ((pos = str.find(delimiter, pos)) != std::string::npos)
	{
		++times;
		pos += delimiter.length();
	}
	//    std::cout << times << std::endl;
	return times;
}


bool	validNumberOfDelimiters(std::string line, std::string delimiter)
{
	int amount = 0;
	amount = howManyDelimiters(line, delimiter);
	
	if (delimiter == "," || delimiter == "|")
	{
		if (amount != 1)
		{
			std::cout << "not a valid number of delimiter" << std::endl;
			return false;
		}
		if(delimiter == "|" && amount == 1)
		{
			if(!howManyDelimiters(line, " | "))
			{
				std::cout << "wrong format of delimiter" << std::endl;
				return false;
			}
		}
			


	}
	if (delimiter == "-")
	{
		if (amount != 2)
			return false;
	}
	std::cout << GREEN << "for this line: " << line << " VALID DELIMITER" << RESET << std::endl;
	return true;
}

bool validDate(std::string date)
{
	if (!validNumberOfDelimiters(date, "-"))
	{
		std::cout << RED << "wrong number of hyphens" <<  RESET << std::endl;
		return false;

	}
	
	if (date.length() != 10)
	{
		std::cout << RED << "no tiene 10 digitos:  " << date.length() << RESET << std::endl;
		return false;
	}

	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);

	const char *year_charptr = const_cast<char *>(year.c_str());
	const char *month_charptr = const_cast<char *>(month.c_str());
	const char *day_charptr = const_cast<char *>(day.c_str());
	// std::cout << "year: " << year << " month: " << month << " day: " << day << std::endl;
	if (validYearMonthDay(year_charptr, month_charptr, day_charptr))
		return true;
	return false;
}



BitcoinExchange::BitcoinExchange()
{
	std::cout << GREY << "Default BitcoinExchange constructor called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(std::ifstream &inputFile, std::ifstream &dataBase)
{
	// if(!validInputFile())
	// 	throw BitcoinExchange::InvalidInputFile();
	(void)inputFile;
	if (!this->_validDataBase(dataBase))
		throw BitcoinExchange::InvalidDataBase();
	this->_exchangeInput(inputFile);

	std::cout << GREY << "BitcoinExchange constructor with files called" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &original)
{
	*this = original;
}
BitcoinExchange::~BitcoinExchange()
{
	std::cout << GREY << "Default BitcoinExchange destructor called" << RESET << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this == &rhs)
		return *this;
	// this->_file = rhs._file;
	// this->_dataBase = rhs._dataBase;
	return *this;
}

//EXCEPTIONS
const char *BitcoinExchange::InvalidDataBase::what() const throw()
{
	return ("The dataBase file is not well formatted");
}

// const char *BitcoinExchange::InvalidInputLine::what() const throw()
// {
// 	return ("Bad Input");
// }

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
		{
			// std::cout << "BAD DB" << std::endl;
			return false;
		}	
	}
	return true;
}

void	BitcoinExchange::_exchangeInput(std::ifstream& inputFile)
{
	std::string line;
	int	empty = 1;
	std::string	date;
	std::string	value;
	std::map<std::string, float>::iterator it;

	while (std::getline(inputFile, line) )
	{
		empty = 0;
		if (line == "date | value")
			continue;
		if (!validNumberOfDelimiters(line, "|"))
			std::cout << RED << "Error: bad input => " << line << RESET << std::endl;
		date = line.substr(0,line.find("|") - 1);
		// std::cout << RED << "PRINTAME EL DATE: " << "[" << date << "]"<< RESET << std::endl;
		value = line.erase(0, line.find("|") + 2);
		// std::cout << RED << "PRINTAME EL VALUE: " << value << RESET << std::endl;
		if (validDate(date) && validNum(value, false))
		{
			float numDouble = transformStrFloat(value);
			it = this->_dataBase.find(date);
			if (it != this->_dataBase.end())
				std::cout << date << " => " << value << " * " << it->second << " = " << numDouble * it->second <<std::endl;
			else
			{
				// it = this->_dataBase.begin();
				// std::cout << it->first << std::endl;
			}
		}
	
	}
	if(inputFile.eof() && empty)
		std::cout << RED << "Error: Empty input file" << line << RESET << std::endl;
}


