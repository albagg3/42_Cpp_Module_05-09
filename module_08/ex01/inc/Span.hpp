/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:54:17 by albagarc          #+#    #+#             */
/*   Updated: 2024/02/06 16:42:48 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_H
#define SPAN_H

#include<list>
#include <iostream>
// #include <iterator>
#include <algorithm> //sort
#include <vector> //sort

class Span
{
	private:
		unsigned int	_maximum;
		std::list<int>	_list;

	public:
		Span();
		Span(unsigned int max);
		Span(const Span& original);
		~Span();

		Span&	operator=(const Span& rhs);

		void					addNumber(int number);
		void					addNumbers(std::list<int>::iterator begin, std::list<int>::iterator end);
		void					printList();
		unsigned int			shortestSpan();
		unsigned int			longestSpan();

		class SpanFullException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		class NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

};

#endif