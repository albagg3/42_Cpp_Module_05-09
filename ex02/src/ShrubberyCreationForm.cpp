/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:12:20 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/09 16:44:20 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137)
{
	std::cout << GREY << "Default Shrubbery Creation Form called" << RESET << std::endl;
}

//Constructor with target
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 	AForm("ShrubberyCreationForm", 145, 137),
																			_target(target) 	
{
	std::cout << GREY << "Constructor Shrubbery Creation Form with target: "<< this->_target << " called" << RESET << std::endl;
}

//Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& original): 	AForm(original),
																						_target(original._target)
{
	std::cout << GREY << "Copy Constructor Shrubbery Creation Form  with target: "<< this->_target << " called" << RESET << std::endl;
}

//Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << GREY << "Destructor ShrubberyCreationForm called" << RESET << std::endl;
}

//Assignation operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	// WHY IS NOT ALLOWED??
	(void) rhs;
	// if(this == &rhs)
	// 	return *this;
	// this->_target = rhs._target;
	// std::cout << GREY << "ShrubberyCreationForm asignation operator was called" << RESET << std::endl;
	return *this;
}


//Member function
void	ShrubberyCreationForm::executingForm() const
{
	std::ofstream file(this->_target + "_shrubbery");
	file << YELLOW << "     _\\/_" << RESET << std::endl;
	file << YELLOW << "      /\\ " << RESET << std::endl;
	file << GREEN << "      /\\ " << RESET << std::endl;
	file << GREEN << "     /~~\\o " << RESET << std::endl;
	file << GREEN << "    /o   \\ " << RESET << std::endl;
	file << GREEN << "   /~~*~~~\\ " << RESET << std::endl;
	file << GREEN << "  o/    o \\ " << RESET << std::endl;
	file << GREEN << "  /~~~~~~~~\\~` " << RESET << std::endl;
	file << GREEN << " /__*_______\\ " << RESET << std::endl;
	file << GREY << "      || " << RESET << std::endl;
	file << RED << "    \\====/ " << RESET << std::endl;
	file << RED << "     \\__/ " << RESET << std::endl;
	file.close();
}

//Overload operator
std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& object)
{
	out << "Form name: " << object.getName() << " , is it signed?: " << object.getIsSigned() 
	<< ". Only bureaucrats with grade " 
	<< object.getGradeToSign() << " can sign it and bureaucrats with grade " 
	<< object.getGradeToExecute() << " can execute it." << std::endl; 
	return out;
}