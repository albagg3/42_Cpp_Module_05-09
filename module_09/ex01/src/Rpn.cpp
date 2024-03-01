/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:50:44 by albagarc          #+#    #+#             */
/*   Updated: 2024/03/01 19:04:02 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rpn.hpp"

int transformStrToInt(std::string value)
{
	const char *cstr = value.c_str();
	int num = atoi(cstr);
	return num;
}

bool	isOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
	 	return true;
	return false;
}

bool	validCharacters(std::string input)
{

	for (unsigned long i = 0; i < input.length(); i++)
	{
		if(isdigit(input[i]) || isspace(input[i]) || isOperator(input[i]))
			continue;
		else
			return false;
	}
	return true;
}

void	Rpn::_executeOperation(char operatorSign)
{
	float result;

	float second = this->_rpn.top();
	this->_rpn.pop();
	float first = this->_rpn.top();	
	this->_rpn.pop();

	for(int i = 0; i < 2; i++)
	{
		if(operatorSign == '+')
			result = first + second;	
		if(operatorSign == '-')
			result = first - second;	
		if(operatorSign == '*')
			result = first * second;	
		if(operatorSign == '/')
			result = first / second;	
		
	}
	this->_rpn.push(result);
}

bool	Rpn::_validStructureAndResult(std::string input)
{
	for(size_t i = 0; i < input.length() ; i++)
	{
		std::string token;
		size_t start = input.find_first_not_of(" ");
    	size_t end = input.find_first_of(" ", start); 
		if(end > input.length())
			end = input.length();
		token = input.substr(start, end - start);
		
		if( token[0] != '0' && !transformStrToInt(token) && !isOperator(token[0]))
			return false;
		else if (isOperator(token[0]) && token.length() != 1)
			return false;
		else
		{
			if (isOperator(token[0]))
			{
				if(this->_rpn.size() >= 2)
				{
					this->_executeOperation(token[0]);
				}
				else
					return false;
			}
			else
			{
				int numToStack = transformStrToInt(token);
				this->_rpn.push(numToStack);
			}
		}
		input = input.substr(end);
		i = 0;
	}
	std::cout << this->_rpn.top() << std::endl;
	return true;
}

//******* CLASS RPN ************//

Rpn::Rpn() 
{
	std::cout << GREY << "Default Rpn constructor called" << RESET << std::endl;
}

Rpn::Rpn(const Rpn& original)
{
	*this = original;
}

Rpn::~Rpn()
{
	std::cout << GREY << "Default Rpn destructor called" << RESET << std::endl;
}

Rpn& Rpn::operator=(const Rpn& rhs)
{
	if(this == &rhs)
		return *this;
	return *this;
}


Rpn::Rpn(std::string input) 
{
	if(!validCharacters(input))
		throw Rpn::InvalidInputFormat();
	if(!this->_validStructureAndResult(input))
		throw Rpn::InvalidOrderOfOperandsAndOperators();
	std::cout << GREY << "Rpn constructor with input called" << RESET << std::endl;
}


//EXCEPTIONS
const char *Rpn::InvalidInputFormat::what() const throw()
{
	return ("The input is not well formatted");
}

const char *Rpn::InvalidOrderOfOperandsAndOperators::what() const throw()
{
	return ("Please review how an RPN works and write the input correctly");
}