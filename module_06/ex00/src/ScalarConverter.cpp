/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:16:32 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/12 16:14:22 by albagarc         ###   ########.fr       */
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
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

//Aux functions
bool	is_char(std::string input)
{
	if()
}

void	check_input_type(std::string input)
{
	if(is_char(input))

}

//Static function
void ScalarConverter::convert(std::string input)
{
	// if (input == "-inff" || input == "+inff" || input == "nanf" || input == "-inf" || input == "nan")
	// {
	
	// }
	check_input_type(input);
}