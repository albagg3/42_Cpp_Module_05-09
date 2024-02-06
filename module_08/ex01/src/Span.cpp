/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:17:46 by albagarc          #+#    #+#             */
/*   Updated: 2024/02/06 15:03:10 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"

//CONSTRUCTORS
Span::Span() : _maximum(0)
{
	return ;
}

Span::Span(unsigned int max) : _maximum(max)
{
	return ;
}

Span::Span(const Span& original) : _maximum(original._maximum), _list(original._list)
{
	return ;
}

//DESTRUCTOR
Span::~Span()
{
	
	return ;
}


//ASIGNATION OPERATOR
Span& Span::operator=(const Span& rhs)
{
	if (this == &rhs)
		return *this;
	this->_maximum = rhs._maximum;
	this->_list = rhs._list;
	return *this;
}

//MEMBER FUNCTIONS
void	Span::addNumber(unsigned int number)
{
	if (this->_list.empty() || number > this->_list.back()) 
	{
        this->_list.push_back(number);
	}
	if(this->_list.size() < this->_maximum)
	{
		std::list<unsigned int>::iterator it;
		for(it = this->_list.begin(); it != this->_list.end(); ++it)
		{
			if(*it > number)
			{
				this->_list.insert(it, number);
				return;
			}
		}
	}
	else
	{
		throw Span::SpanFullException();
	}
	
}

void Span::printList()
{
	std::list<unsigned int>::iterator it;
	
		
	for(it = this->_list.begin(); it != this->_list.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}


unsigned int	Span::shortestSpan()
{
	std::list<unsigned int>::iterator it;
	std::list<unsigned int>::iterator prevIt;
	unsigned int	shortestSpan = std::numeric_limits<unsigned int>::max();
	
	prevIt = this->_list.begin();	
	for(it = ++this->_list.begin(); it != this->_list.end(); ++it)
	{
		if ((*it - *prevIt) < shortestSpan)
			shortestSpan = *it - *prevIt;
		prevIt = it;
	}
	return shortestSpan;
}

unsigned int 	Span::longestSpan()
{
	unsigned int longestSpan;
	longestSpan = 0;
	if (this->_list.size() > 1)
	{
		longestSpan = this->_list.back() - this->_list.front();
	}
	else
	{
		throw Span::NotEnoughNumbersException();
	}
	return longestSpan;
}

//	EXCEPTIONS
const char * Span::SpanFullException::what() const throw()
{

	return ("The Span is full");
}
const char * Span::NotEnoughNumbersException::what() const throw()
{

	return ("The Span is full");
}