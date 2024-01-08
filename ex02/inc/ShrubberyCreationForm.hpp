/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:12:20 by albagarc          #+#    #+#             */
/*   Updated: 2023/11/19 19:25:27 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm(); 											//Constructor
		ShrubberyCreationForm(const std::string& target);					//Creates a ShrubberyForm with target
		ShrubberyCreationForm(const ShrubberyCreationForm& original);		//Copy constructor
		~ShrubberyCreationForm();											//Destructor

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs); // assignation operator

		void	execute(Bureaucrat const & executor);						//A bureacrat as an argument can or cannot execute the form

};

#endif


//     _\/_
//      /\
//      /\
//     /  \
//     /~~\o
//    /o   \
//   /~~*~~~\
//  o/    o \
//  /~~~~~~~~\~`
// /__*_______\
//      ||
//    \====/
//     \__/