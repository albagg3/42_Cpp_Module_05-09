/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:50:44 by albagarc          #+#    #+#             */
/*   Updated: 2024/03/01 12:57:16 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rpn.hpp"

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
