/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:11:31 by albagarc          #+#    #+#             */
/*   Updated: 2024/02/22 18:33:30 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	validYearMonthDay(std::string year, std::string month,std::day)
{

	if (!atoi(year) && !(atoi(year) > 2009))
		return false;
	if (!atoi(month) || !(atoi(month) > 0) ||| atoi(month) < 13)
		return false;
	if (atoi(day)  && atoi(day) > 0)
	{
		if (atoi(month) == 2)
		{
			if (atoi(day) < 30)
				return false
		}
		else if (atoi(month) == 1 || atoi(month) == 3 || atoi(month) == 5 || atoi(month) == 7 || atoi(month) == 8 || atoi(month) == 10 || atoi(month) == 12)
		{
			if (atoi(day < 32))
				return false
		}
		else
		{
			if (atoi(day) < 31)
				return false
		}
	}
	return true;
}

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::ifstream& inputFile, std::ifstream& dataBase) 
{
	// if(!validInputFile())
	// 	throw BitcoinExchange::InvalidInputFile();
	(void)inputFile;
	if (!_validDataBase(dataBase))
		throw BitcoinExchange::InvalidDataBase();
	// createDataBase()

	std::cout << " BitcoinExchange constructor with files called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& original) 
{
	*this = original;
}
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Default BitcoinExchange destructor called" << std::endl;

}


BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this == &rhs)
		return *this;
	// this->_file = rhs._file;
	// this->_dataBase = rhs._dataBase;
	return *this;
}


bool	BitcoinExchange::_validDataBase(std::ifstream& dataBase)
{
	std::string	line;
	// int i = 0;
	// bool flag_new_line = false;
	// std::string	date;
	// float 		number;

		// this->_validNum("-1");
		// this->_validNum("0");
		// this->_validNum("a3");
		// this->_validNum("t");
		// this->_validNum("21214132412341341341324132412");
		this->_validDate("2200-33-42");
		this->_validDate("2200-1-42");
	while(std::getline(dataBase,line))
	{
		std::cout << line << std::endl;
		// this->_howManyDelimiters(line, ",");
	// 	if(i % 2 == 0)
	// 	{
	// 		if (validDate(line))
	// 		{
	// 			date = line;
	// 		}
	// 		flag_new_line = false;
	// 	}
	// 	else
	// 	{
	// 		validNum(line);
	// 		flag_new_line = true;

	// 	}
	// 	if(flag_new_line)
	// 	{
			
	// 		this->_dataBase.insert(std::pair<std::string, float>(date,number));
	// 		date = "";
	// 		number = "";
	// 	}
	// 	i++;
	}
	return true;
}

//EXCEPTIONS
// const char *
// BitcoinExchange::InvalidInputFile::what() const throw()
// {
// 	return ("The input file is not formatted");
// }
const char *	BitcoinExchange::InvalidDataBase::what() const throw()
{
	return ("The dataBase file is not well formatted");
}

bool BitcoinExchange::_validNum(std::string num)
{
	const char * cstr = num.c_str();
	float	numDouble = atof(cstr);
	if(num != "0" && !numDouble)
	{
		std::cout << "atof no puede convertirlo" << std::endl;
		return false;
	}
	if(numDouble > std::numeric_limits<int>::max())
	{
		std::cout << "mayor que el max int" << std::endl;

		return false;
	}
	if(numDouble < 0)
	{
		std::cout << "menor que 0" << std::endl;
		return false;
	}
	return true;

}


bool BitcoinExchange::_validDate(std::string date)
{
	int hyphenCounter = this->_howManyDelimiters(date, "-");
	if (hyphenCounter != 2 )
		return false;
	if (date.length() != 10)
		return false;
	
	if()std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8,2);
	
	std::cout << "year: " << year << " month: " << month << " day: " << day << std::endl;
	return true;

}

int	BitcoinExchange::_howManyDelimiters(std::string str, std::string delimiter)
{
	int times = 0;
	std::string::size_type pos = 0;
   	while ((pos = str.find(delimiter, pos )) != std::string::npos) {
          ++ times;
          pos += delimiter.length();
   }
   std::cout << times << std::endl;
   return times;
}
