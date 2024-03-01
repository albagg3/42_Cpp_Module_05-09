/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:50:34 by albagarc          #+#    #+#             */
/*   Updated: 2024/03/01 19:08:53 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
# define PMERGEME_H


#include <iostream>
#include <exception>
#include <cstdlib>
#include <stack>

#define GREY "\e[90m"
#define RESET "\e[0m"
#define RED "\e[91m"
#define GREEN "\e[92m"

class	PmergeMe
{
	private:
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& original);
		PmergeMe(std::string input);
		~PmergeMe();


		PmergeMe&	operator=(const PmergeMe& rhs);


	
	// class InvalidOrderOfOperandsAndOperators : public std::exception
	// {
	// 	public:
	// 		virtual const char* what() const throw();
	// };
};


#endif