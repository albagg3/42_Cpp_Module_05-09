/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:16:32 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/15 13:05:04 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"
#include <string> 

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
std::string	printChar(std::string input)
{
	if (input[0] <= 31 || input[0] == 127)
		return "Non displayable";
	else if (input[0] > 127)
		return "imposible";
	else
		return input;
}

bool	isValidInput(std::string input)
{
	if (isChar(input))
		return true;
	// else if (is_int(input))
	// else if (is_float(input))
	// else if (is_double(input))
	// else
	return false;


}

void	ftPrintScalar(std::string input)
{
	// long double input_to_num;
	// input_to_num = std::stold(input);
	std::string char_str;
	if (isValidInput(input))
	{
		char_str = printChar(input);

		std::cout << "char: " << char_str << std::endl;
		// std::cout << "int: " << static_cast<int>(input_to_num) << std::endl;
		// std::cout << "float: " << static_cast<float>(input_to_num) << std::endl;
		// std::cout << "double: " << static_cast<double>(input_to_num) << std::endl;

	}
	else
		std::cout << "Invalid input" << std::endl;

}

//Static function
void ScalarConverter::convert(std::string input)
{
	
	ftPrintScalar(input);
}
