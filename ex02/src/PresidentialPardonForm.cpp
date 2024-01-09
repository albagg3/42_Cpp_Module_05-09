/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:59:01 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/09 16:45:05 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

//Default Constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5)
{
	std::cout << GREY << "Default Presidential Pardon Form called" << RESET << std::endl;
}

//Constructor with target
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : 	AForm("PresidentialPardonForm", 25, 5),
																			_target(target) 	
{
	std::cout << GREY << "Constructor Presidential Pardon Form with target: "<< this->_target << " called" << RESET << std::endl;
}

//Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& original): 	AForm(original),
																						_target(original._target)
{
	std::cout << GREY << "Copy Constructor Presidential Pardon Form with target: "<< this->_target << " called" << RESET << std::endl;
}

//Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << GREY << "Destructor PresidentialPardonForm called" << RESET << std::endl;
}

//Assignation operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	// WHY IS NOT ALLOWED??
	(void) rhs;
	// if(this == &rhs)
	// 	return *this;
	// this->_target = rhs._target;
	// std::cout << GREY << "PresidentialPardonForm asignation operator was called" << RESET << std::endl;
	return *this;
}


//Member function
void	PresidentialPardonForm::executingForm() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

//Overload operator
std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& object)
{
	out << "Form name: " << object.getName() << " , is it signed?: " << object.getIsSigned() 
	<< ". Only bureaucrats with grade " 
	<< object.getGradeToSign() << " can sign it and bureaucrats with grade " 
	<< object.getGradeToExecute() << " can execute it." << std::endl; 
	return out;
}