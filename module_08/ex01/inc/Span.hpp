/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:54:17 by albagarc          #+#    #+#             */
/*   Updated: 2024/02/06 15:03:37 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPAN_H
#define SPAN_H

#include<list>
#include <iostream>
// #include <iterator>
// #include <algorithm>

class Span
{
	private:
		unsigned int	_maximum;
		std::list<unsigned int>	_list;

	public:
		Span();
		Span(unsigned int max);
		Span(const Span& original);
		~Span();

		Span&	operator=(const Span& rhs);

		void					addNumber(unsigned int number);
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