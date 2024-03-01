/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:50:34 by albagarc          #+#    #+#             */
/*   Updated: 2024/03/01 19:04:11 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H


#include <iostream>
#include <exception>
#include <cstdlib>
#include <stack>

#define GREY "\e[90m"
#define RESET "\e[0m"
#define RED "\e[91m"
#define GREEN "\e[92m"

class	Rpn
{
	private:
		std::stack<float>	_rpn;
		
	public:
		Rpn();
		Rpn(const Rpn& original);
		Rpn(std::string input);
		~Rpn();


		Rpn&	operator=(const Rpn& rhs);

		bool	_validStructureAndResult(std::string input);
		void	_executeOperation(char operatorSign);

	class InvalidInputFormat : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class InvalidOrderOfOperandsAndOperators : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};


#endif