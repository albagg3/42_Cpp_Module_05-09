/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:40:25 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/09 17:17:07 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
//Default constructor
Bureaucrat::Bureaucrat() : _name(), _grade(0)
{
	std::cout << GREY << "Bureaucrat default constructor called" << RESET << std::endl;
	return ;
}

//Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& original) : _name(original._name), _grade(original._grade) //asi inicializamos el burocrata con este valor
{
	// esto esta mal porque se supone que ya se habria inicializado el valor con algo aunque fuera vacio y no podrias modificarlo
	// this->_name = original._name; 
	// this->_grade = original._grade;
	
	std::cout << GREY << "Copied Bureaucrat " << this->_name << " with grade: " << this->_grade << " copy constructor called" << RESET << std::endl;
}

//Name&Grade constructor
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << GREY << "Bureaucrat " << this->_name << " with grade: " << this->_grade << " constructor called" << RESET << std::endl;
	return ;
}

//Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << GREY << "Bureaucrat "<< this->_name << " with grade: " << this->_grade << " destructor was called" << RESET << std::endl;
}

//Assignation operator
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this == &rhs)// comparamos si los punteros son iguales y estamos intentando igualar un objeto a si mismo 
		return *this; //El compilador necesita que le devuelva un objeto concreto aunque luego es una referencia&
	// this->_name = rhs._name;
	this->_grade = rhs._grade;
	std::cout << GREY << "Bureaucrat asignation operator was called" << RESET << std::endl;
	std::cout << GREY << "Bureaucrat " << this->_name << " now have grade " << this->_grade << RESET << std::endl;
	return *this;
}

//Getters
const std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

//Member functions
void	Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
	std::cout << this->getName() << "'s new grade is " << this->_grade << std::endl;
	return ;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
	std::cout << this->getName() << "'s new grade is " << this->_grade << std::endl;
	return ;
}


void	Bureaucrat::signForm(AForm& form)
{
	try {
		form.beSigned(*this);
		std::cout << GREEN << this->getName() << " signed " << form.getName() << RESET << std::endl;
	}
	catch (AForm::GradeTooLowException &e){
		std::cout << RED << this->getName() << " couldn't sign " << form.getName() 
		<< " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form)
{
	 try {
        form.execute( *this );
    } catch ( std::exception& e ) {
        std::cout << RED << _name << " couldn't execute " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
}

//Exceptions

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The maximum grade for a bureaucrat is 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The minimum grade for a bureaucrat is 150");
}


std::ostream &	operator<<( std::ostream &out, const Bureaucrat  &object )
{
	out << object.getName() << ", bureaucrat grade " << object.getGrade() << "." << std::endl;;
    return out;
}