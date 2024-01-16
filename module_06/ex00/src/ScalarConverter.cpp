/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:16:32 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/16 16:33:25 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

//Constructor default
ScalarConverter::ScalarConverter()
{
	std::cout << "Scalar converter default Constructor called" << std::endl;
}

//Copy Constructor
ScalarConverter::ScalarConverter(const ScalarConverter& original) 
{
	(void) original;
	std::cout << "Scalar converter copy Constructor called" << std::endl;
}

//Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

//Assignation operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void) rhs;
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

//Aux functions
bool	isChar(std::string input)
{
	if(input.length() != 1)
		return false;
	else
		return true;
}

//This function will parse the input to check if it could be a float
//It checks if there is an f in the idx that the number ends
//If there's only one point and if the f is the last character in the string
bool	isFloat(std::string input, std::size_t idx)
{
	try{
		if(input[idx] == 'f')
		{
			if(std::count(input.begin(), input.end(), '.') == 1)
			{
				int idx_point = input.find('.');
				if(isdigit(input[idx_point + 1]))
					return true;
				else
					return false;
			}
			if(input[idx + 1] == '\0')
				return true;
		}
		return false;
	}
	catch(std::exception &e){
		return false;
	}
}

//This function will parse the input to check if it could be an int a float or a double
bool	isIntOrFloatOrDouble(std::string input)
{
	long double int_input;
	std::size_t idx;

	try {
		int_input = std::stold(input, &idx);
		if (idx != input.length())
		{
			
			if (isFloat(input, idx))
				return true;
			return false;
		}
		return true;
	}
	catch (std::exception &e){
		return false;
	}
}

//This function identifies if it is possible to print a char if not it will write the correct output
bool	isPossibleToPrintChar(long double input)
{
	if (std::numeric_limits<double>::infinity() == input || -std::numeric_limits<double>::infinity() == input)
	{
		std::cout << "char: " << "Impossible" << std::endl;
		return false;
	}
	if (input <= 31 || input == 127)
	{
		std::cout << "char: " << "Non displayable" << std::endl;
		return false;
	}
	else if (input > 127)
	{
		std::cout << "char: " << "Impossible" << std::endl;
		return false;
	}
	else if (std::isnan(input))
	{
		std::cout << "char: " << "Impossible" << std::endl;
		return false;
	}
	else
		return true;
}

//This function identifies if it is possible to print an int if not it will write the correct output
bool	isPossibleToPrintInt(long double input)
{
	if (std::numeric_limits<double>::infinity() == input || -std::numeric_limits<double>::infinity() == input)
	{
		std::cout << "int: " << "Impossible" << std::endl;
		return false;
	}
	if (input < std::numeric_limits<int>::lowest() || input > std::numeric_limits<int>::max())
	{
		std::cout << "int: " << "Overflow" << std::endl;
		return false;
	}
	else if (std::isnan(input))
	{
		std::cout << "int: " << "Impossible" << std::endl;
		return false;
	}
	else
		return true;
}

//This function identifies if it is possible to print a float if not it will write the correct output
bool	isPossibleToPrintFloat(long double input)
{
	if (-std::numeric_limits<double>::infinity() == input)
	{
		std::cout << "float: " << "-inff" << std::endl;
		return false;
	}
	if (std::numeric_limits<double>::infinity() == input)
	{
		std::cout << "float: " << "inff" << std::endl;
		return false;
	}
	else if (input < std::numeric_limits<float>::lowest() || input > std::numeric_limits<float>::max())
	{
		std::cout << "float: " << "Overflow" << std::endl;
		return false;
	}
	else
		return true;
}

//This function identifies if it is possible to print a double if not it will write the correct output
bool	isPossibleToPrintDouble(long double input)
{
	if (-std::numeric_limits<double>::infinity() == input)
	{
		std::cout << "double: " << "-inf" << std::endl;
		return false;
	}
	if (std::numeric_limits<double>::infinity() == input)
	{
		std::cout << "double: " << "inf" << std::endl;
		return false;
	}
	else if (input < std::numeric_limits<double>::lowest() || input > std::numeric_limits<double>::max())
	{
		std::cout << "double: " << "Overflow" << std::endl;
		return false;
	}
	else
		return true;
}


//This function checks if the input introduced in the program can be a correct input or not
bool	isValidInput(std::string input)
{
	if (input[input.length() - 1]  == '.')
		return false;
	if (isChar(input))
		return true;
	else if (isIntOrFloatOrDouble(input))
		return true;
	return false;
}

//This function checks if it is possible to print the number and if it's positive will cast and print it 
void	ftPrintScalar(long double input)
{	
	if(isPossibleToPrintChar(input))
		std::cout << "char: " << static_cast<char>(input) << std::endl;
	if (isPossibleToPrintInt(input))
		std::cout << "int: " << static_cast<int>(input) << std::endl;
	if (isPossibleToPrintFloat(input))
		std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(input) << "f" <<std::endl;
	if (isPossibleToPrintDouble(input))
		std::cout << "double: " << std::setprecision(1) << std::fixed << static_cast<double>(input) << std::endl;			
}

//Static function
void ScalarConverter::convert(std::string input)
{
	long double input_long_double;
	try{
		if(input.length() == 1 && !isdigit(input[0]))
			input_long_double =  static_cast<double>(input[0]);
		else
			input_long_double = std::stold(input);
		if (isValidInput(input))
			ftPrintScalar(input_long_double);
		else
			std::cout << "Invalid input" << std::endl;
	}
	catch(std::exception &e){
		std::cout << "The number is not formatted well " << std::endl;
	}
	
}
