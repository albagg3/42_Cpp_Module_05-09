/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:59:09 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/09 17:15:58 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

//Default Constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45)
{
	std::cout << GREY << "Default Presidential Pardon Form called" << RESET << std::endl;
}

//Constructor with target
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : 	AForm("RobotomyRequestForm", 72, 45),
																			_target(target) 	
{
	std::cout << GREY << "Constructor Presidential Pardon Form with target: "<< this->_target << " called" << RESET << std::endl;
}

//Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& original): 	AForm(original),
																						_target(original._target)
{
	std::cout << GREY << "Copy Constructor Presidential Pardon Form with target: "<< this->_target << " called" << RESET << std::endl;
}

//Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << GREY << "Destructor RobotomyRequestForm called" << RESET << std::endl;
}

//Assignation operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	// WHY IS NOT ALLOWED??
	(void) rhs;
	// if(this == &rhs)
	// 	return *this;
	// this->_target = rhs._target;
	// std::cout << GREY << "RobotomyRequestForm asignation operator was called" << RESET << std::endl;
	return *this;
}


//Member function
void	RobotomyRequestForm::executingForm() const
{
	srand(time(NULL));
	int random;
	random = 1 + (rand() % 100);

	std::cout << "~~~Drilling noises~~~" << std::endl;
	if(random % 2 == 0)
		std::cout << this->_target << " has been robotomized" << std::endl; 
	else
		std::cout << "Robotom failed" << std::endl;
}

//Overload operator
std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& object)
{
	out << "Form name: " << object.getName() << " , is it signed?: " << object.getIsSigned() 
	<< ". Only bureaucrats with grade " 
	<< object.getGradeToSign() << " can sign it and bureaucrats with grade " 
	<< object.getGradeToExecute() << " can execute it." << std::endl; 
	return out;
}