/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:12:20 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/09 13:05:07 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"
#include "fstream"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
		ShrubberyCreationForm(); 											//Constructor
		
	public:
		ShrubberyCreationForm(const std::string& target);					//Creates a ShrubberyForm with target
		ShrubberyCreationForm(const ShrubberyCreationForm& original);		//Copy constructor
		~ShrubberyCreationForm();											//Destructor

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs); // assignation operator

		void	execute(const Bureaucrat& executor) const;						//A bureacrat as an argument can or cannot execute the form no modifica datos por eso const

};

std::ostream&	operator<<(std::ostream &out, const ShrubberyCreationForm &object);

#endif
