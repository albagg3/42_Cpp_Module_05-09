/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:16:32 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/15 16:40:43 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"
#include <string> 
#include <iomanip>
#include <limits>
#include <cstdlib>// me la manda poner en gitcode
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
	// else if (input[0] <= 31 || input[0] >= 127)
	// 	return false;
	else
		return true;

}
bool	isPossibleToPrintChar(long double input)
{
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
	else
		return true;
}

bool	isFloat(std::string input, std::size_t idx)
{
	// long double float_input;
	// std::size_t idx;

	try{
		if(input[idx] == 'f')
		{
			std::cout << "Por aqu'i estoy" << std::endl;
			return true;
		}
		return false;

	}
	catch(std::exception &e){
		// std::cout << "Not an int" << std::endl;
		return false;
	}
}

bool	isIntOrFloatOrDouble(std::string input)
{
	long double int_input;
	std::size_t idx;

	try{
		int_input = std::stold(input, &idx);
		std::cout <<"en INT"<< int_input << " index:" << idx << std::endl;
		if(idx != input.length())
		{
			
			if(isFloat(input, idx))
				return true;
			return false;
		}
		return true;
	}
	catch(std::exception &e){
		// std::cout << "Not an int" << std::endl;
		return false;
	}
}

bool	isPossibleToPrintInt(long double input)
{
	if (input < std::numeric_limits<int>::lowest() || input > std::numeric_limits<int>::max())
	{
		std::cout << "int: " << "Overflow" << std::endl;
		return false;
	}
	else
		return true;
}


bool	isValidInput(std::string input)
{
	if (isChar(input))
	{
		std::cout << "Entra en char" << std::endl;
		return true;
	}
	else if (isIntOrFloatOrDouble(input))
	{
		std::cout << "Entra en int or float" << std::endl;
		return true;
	}
	// else if (isFloat(input))
	// {

	// }
	// else if (is_double(input))
	// else
	return false;


}

void	ftPrintScalar(std::string input)
{
	long double input_long_double;
	try{
		if(input.length() == 1)
			input_long_double =  static_cast<double>(input[0]);
		else
		{
			input_long_double = std::stold(input);
			std::cout << input_long_double << std::endl;
		}
		if (isValidInput(input))
		{
			if(isPossibleToPrintChar(input_long_double))
			{
				std::cout << "char: " << static_cast<char>(input_long_double) << std::endl;
			}
			if (isPossibleToPrintInt(input_long_double))
			{
				std::cout << "int: " << static_cast<int>(input_long_double) << std::endl;
			}
			std::cout << "float: " << std::setprecision(1) << std::fixed << static_cast<float>(input_long_double) << "f" <<std::endl;
			std::cout << "double: " << std::setprecision(1) << std::fixed << static_cast<double>(input_long_double) << std::endl;
			

		}
		else
			std::cout << "Invalid input" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "The number is not formatted well " << std::endl;
	}
}

//Static function
void ScalarConverter::convert(std::string input)
{
	
	ftPrintScalar(input);
}
