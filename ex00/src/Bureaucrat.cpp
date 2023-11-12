/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:40:25 by albagarc          #+#    #+#             */
/*   Updated: 2023/11/12 17:28:32 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

//Default constructor
Bureaucrat::Bureaucrat() : _name(), _grade(0)
{
	std::cout << GREY << "Bureaucrat default constructor called" << RESET << std::endl;
}

//Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& original) : _name(original._name), _grade(original._grade) //asi inicializamos el burocrata con este valor
{
	// esto esta mal porque se supone que ya se habria inicializado el valor con algo aunque fuera vacio y no podrias modificarlo
	// this->_name = original._name; 
	// this->_grade = original._grade;
	std::cout << GREY << "Bureaucrat copy constructor called" << RESET << std::endl;
}

//Name&Grade constructor
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << GREY << "Bureaucrat " << this->_name << " with grade: " << this->_grade << " constructor called" << RESET << std::endl;
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
	return *this;
	std::cout << GREY << "Bureaucrat asignation operator was called" << RESET << std::endl;

}

