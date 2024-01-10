/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:43:26 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/10 16:24:09 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

//Constructor Default
Form::Form() : _name(), _isSigned(false), _grade_to_sign(0), _grade_to_execute(0) 
{
	std::cout << GREY << "Default Form constructor called" << RESET << std::endl;
	return ;
}

//Copy constructor
Form::Form(const Form& original) : 	_name(original._name),
									_isSigned(original._isSigned),
									_grade_to_sign(original._grade_to_sign),
									_grade_to_execute(original._grade_to_execute)
{
	std::cout << GREY << "Form Copy constructor called" << RESET << std::endl;
}

//Constructor 
Form::Form(const std::string name, const int grade_to_sign, const int grade_to_execute) :	_name(name),
																							_isSigned(false),
																							_grade_to_sign(grade_to_sign),
																							_grade_to_execute(grade_to_execute)
{
	if(grade_to_sign > 150 || grade_to_execute > 150)
		throw Form::GradeTooLowException();
	if(grade_to_sign < 1 || grade_to_execute < 1)
		throw Form::GradeTooHighException();
	std::cout << GREY << "Form constructor with name: " << this->_name << " is called" << RESET << std::endl;
}

//Destructor
Form::~Form()
{
	std::cout << GREY << "Form Destructor is called" << RESET << std::endl;
}

//Asignation operator
Form& Form::operator=(const Form&rhs)
{
	if( this == &rhs)
		return *this;
	this->_isSigned = rhs._isSigned;
	return *this;
}

//Getters
const std::string&	Form::getName() const
{
	return this->_name;
}

const bool&	Form::getIsSigned() const 
{
	return this->_isSigned;
}

const int& Form::getGradeToSign() const
{
	return this->_grade_to_sign;
}

const int& Form::getGradeToExecute() const
{
	return this->_grade_to_execute;
}

//Member Functions
void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
	{
		this->_isSigned = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

//Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return ("The grade of the form is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("The grade of the form is too low");
}

std::ostream& operator<<(std::ostream& out, const Form& object)
{
	out << "Form name: " << object.getName() << " , is it signed?: " << object.getIsSigned() 
	<< ". Only bureaucrats with grade " 
	<< object.getGradeToSign() << " can sign it and bureaucrats with grade " 
	<< object.getGradeToExecute() << "can execute it." << std::endl; 
	return out;
}