/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:50:34 by albagarc          #+#    #+#             */
/*   Updated: 2024/03/01 12:58:08 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H


#include <iostream>
#define GREY "\e[90m"
#define RESET "\e[0m"
#define RED "\e[91m"
#define GREEN "\e[92m"

class	Rpn
{
	private:

	public:
		Rpn();
		Rpn(const Rpn& original);
		~Rpn();

		Rpn&	operator=(const Rpn& rhs);
};


#endif