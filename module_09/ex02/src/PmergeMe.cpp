/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:50:44 by albagarc          #+#    #+#             */
/*   Updated: 2024/03/01 19:09:40 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"



//******* CLASS PmergeMe ************//

PmergeMe::PmergeMe() 
{
	std::cout << GREY << "Default PmergeMe constructor called" << RESET << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& original)
{
	*this = original;
}

PmergeMe::~PmergeMe()
{
	std::cout << GREY << "Default PmergeMe destructor called" << RESET << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	if(this == &rhs)
		return *this;
	return *this;
}




//EXCEPTIONS


// const char *PmergeMe::InvalidOrderOfOperandsAndOperators::what() const throw()
// {
// 	return ("Please review how an RPN works and write the input correctly");
// }