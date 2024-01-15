/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:16:32 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/15 11:53:44 by albagarc         ###   ########.fr       */
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
	else if (input[0] <= 31 && input[0] >= 127)
		return false;
	//not displayable
	return true;


}

bool	checkInputValid(std::string input)
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
	long double input_to_num;
	input_to_num = std::stold(input);
	std::cout << "char: " << static_cast<char>(input[0]) << std::endl;
	std::cout << "int: " << static_cast<int>(input_to_num) << std::endl;
	std::cout << "float: " << static_cast<float>(input_to_num) << std::endl;
	std::cout << "double: " << static_cast<double>(input_to_num) << std::endl;

}

//Static function
void ScalarConverter::convert(std::string input)
{
	
	checkInputValid(input);
	ftPrintScalar(input);
}
