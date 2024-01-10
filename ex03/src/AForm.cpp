/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:43:26 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/09 15:51:41 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

//Constructor Default
AForm::AForm() : _name(), _isSigned(false), _grade_to_sign(0), _grade_to_execute(0) 
{
	std::cout << GREY << "Default AForm constructor called" << RESET << std::endl;
	return ;
}

//Copy constructor
AForm::AForm(const AForm& original) : 	_name(original._name),
									_isSigned(original._isSigned),
									_grade_to_sign(original._grade_to_sign),
									_grade_to_execute(original._grade_to_execute)
{
	std::cout << GREY << "AForm Copy constructor called" << RESET << std::endl;
}

//Constructor 
AForm::AForm(const std::string name, const int grade_to_sign, const int grade_to_execute) :	_name(name),
																							_isSigned(false),
																							_grade_to_sign(grade_to_sign),
																							_grade_to_execute(grade_to_execute)
{
	if(grade_to_sign > 150 || grade_to_execute > 150)
		throw AForm::GradeTooLowException();
	if(grade_to_sign < 1 || grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	std::cout << GREY << "AForm constructor with name: " << this->_name << " is called" << RESET << std::endl;
}

//Destructor
AForm::~AForm()
{
	std::cout << GREY << "AForm Destructor is called" << RESET << std::endl;
}

//Asignation operator
AForm& AForm::operator=(const AForm&rhs)
{
	if( this == &rhs)
		return *this;
	this->_isSigned = rhs._isSigned;
	return *this;
}

//Getters
const std::string&	AForm::getName() const
{
	return this->_name;
}
//si es solo de lectura porque no me deja poner el const al final
const bool&	AForm::getIsSigned() const 
{
	return this->_isSigned;
}

const int& AForm::getGradeToSign() const
{
	return this->_grade_to_sign;
}

const int& AForm::getGradeToExecute() const
{
	return this->_grade_to_execute;
}

//Member Functions
void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
	{
		this->_isSigned = true;
	}
	else
	{
		throw AForm::GradeTooLowException();
	}
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if(!this->getIsSigned())
	{
		throw AForm::FormNotSigned();
	}
	if(executor.getGrade() > this->getGradeToExecute())
	{
		throw AForm::GradeTooHighException();
	}
	//llamar a executeForm
	
	this->executingForm();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}


//Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("The grade of the AForm is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("The grade of the AForm is too low");
}

const char *AForm::FormNotSigned::what() const throw()
{
	return("The form is not signed");
}

//Overload operand
std::ostream& operator<<(std::ostream& out, const AForm& object)
{
	out << "AForm name: " << object.getName() << " , is it signed?: " << object.getIsSigned() 
	<< ". Only bureaucrats with grade " 
	<< object.getGradeToSign() << " can sign it and bureaucrats with grade " 
	<< object.getGradeToExecute() << " can execute it." << std::endl; 
	return out;
}