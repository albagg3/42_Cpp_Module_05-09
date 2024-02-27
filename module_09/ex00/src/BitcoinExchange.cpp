/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:11:31 by albagarc          #+#    #+#             */
/*   Updated: 2024/02/23 12:30:50 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool validYearMonthDay(const char *year, const char *month, const char *day)
{

	std::cout << "VAMOS A VALIDAR LA FECHA" << std::endl;
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
	std::cout << GREEN << "fechaa OK " << RESET << std::endl;
	return true;
}

bool validNum(std::string num)
{
	const char *cstr = num.c_str();
	float numDouble = atof(cstr);
	if (num != "0" && !numDouble)
	{
		std::cout << RED << "atof no puede convertirlo" << RESET << std::endl;
		return false;
	}
	if (numDouble > 1000)
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

bool validDate(std::string date)
{
	int hyphenCounter = howManyDelimiters(date, "-");
	if (hyphenCounter != 2)
	{

		std::cout << RED << "number of hyphens: " << hyphenCounter << RESET << std::endl;
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
	std::cout << "year: " << year << " month: " << month << " day: " << day << std::endl;
	if (validYearMonthDay(year_charptr, month_charptr, day_charptr))
		return true;
	return false;
}

bool validDataBase(std::ifstream &dataBase)
{
	std::string line;

	// this->_validDate("2200-33-42");

	// this->_validDate("2000-01-42");// WRONG YEAR
	// this->_validDate("2200-01-42");// WRONG DAY
	// this->_validDate("2008-01-20");// WRONG YEAR
	validDate("2009-02-30"); // WRONG DAY
	validDate("200--02-30"); // WRONG DATE
	// this->_validDate("2009-02-300"); // MAS DE 10 DIGITOS
	while (std::getline(dataBase, line))
	{
		if(line == "")
	}
	return true;
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
	if (!validDataBase(dataBase))
		throw BitcoinExchange::InvalidDataBase();
	// createDataBase()

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

//MEMBER FUNCTIONS



