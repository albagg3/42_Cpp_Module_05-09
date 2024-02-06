/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:17:46 by albagarc          #+#    #+#             */
/*   Updated: 2024/02/06 16:48:17 by albagarc         ###   ########.fr       */
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
void	Span::addNumber(int number)
{
	if (this->_list.empty() || number > this->_list.back()) 
	{
        this->_list.push_back(number);
		return;
	}
	if(this->_list.size() < this->_maximum)
	{
		std::list<int>::iterator it;
		for(it = this->_list.begin(); it != this->_list.end(); ++it)
		{
			if(*it >= number)
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

void	Span::addNumbers(std::list<int>::iterator begin, std::list<int>::iterator end)
{
	size_t elementsToAdd = std::distance(begin, end);
	if ((this->_list.size() + elementsToAdd) > this->_maximum)
		throw Span::SpanFullException();
	else
	{
		this->_list.insert(this->_list.end(), begin, end);
		//The iterators of a list are not aleatory and the sort function only accepts aleatory iterators 
		// Copy the elements to a vector
        std::vector<int> temp(this->_list.begin(), this->_list.end());

        // Sort the elements 
        std::sort(temp.begin(), temp.end());

        // Copy the elements of the vector to the list again;
        this->_list.assign(temp.begin(), temp.end());
	}
}



void Span::printList()
{
	std::list<int>::iterator it;
	
		
	for(it = this->_list.begin(); it != this->_list.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}


unsigned int	Span::shortestSpan()
{
	std::list<int>::iterator it;
	std::list<int>::iterator prevIt;
	unsigned int	shortestSpan = std::numeric_limits<int>::max();
	if (this->_list.size() > 1)
	{
		prevIt = this->_list.begin();	
		for(it = ++this->_list.begin(); it != this->_list.end(); ++it)
		{
			if ((unsigned int)(*it - *prevIt) < shortestSpan)
				shortestSpan = *it - *prevIt;
			prevIt = it;
		}

	}
	else
		throw Span::NotEnoughNumbersException();
	return shortestSpan;
}

unsigned int 	Span::longestSpan()
{
	unsigned int longestSpan;
	longestSpan = 0;
	if (this->_list.size() > 1)
	{
		// std::cout << "ultimo numero" <<this->_list.back() << std::endl;
		// std::cout << "primer numero" <<this->_list.front() << std::endl;
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

	return ("Please add more numbers to the Span");
}