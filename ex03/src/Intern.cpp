/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:42:23 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/10 16:11:58 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

//Default Constructor
Intern::Intern()
{
	std::cout << GREY << "Default Intern Constructor called" << std::endl;
}

//Copy Constructor
Intern::Intern(const Intern& original)
{
	*this = original;
	std::cout << GREY << "Copy Intern Constructor called" << std::endl;
}

//Destructor
Intern::~Intern()
{
	std::cout << GREY << "Intern Destructor called" << std::endl;
}

//Assignation operator
Intern& Intern::operator=(const Intern& rhs)
{
	(void) rhs;
	return *this;
}


//Member functions
AForm* Intern::createShrubbery(const std::string& target) const
{
	AForm* form_created;
	form_created = new ShrubberyCreationForm(target);
	return (form_created);
}

AForm* Intern::createRobotomy(const std::string& target) const 
{
	AForm* form_created;
	form_created = new RobotomyRequestForm(target);
	return (form_created);
}

AForm* Intern::createPresidential(const std::string& target) const
{
	AForm* form_created;
	form_created = new PresidentialPardonForm(target);
	return (form_created);
}

//There are 2 arrays declared in the function, one with the names of the forms 
//the other one is an array of Intern functions that receive an string as a parameter.
AForm *Intern::makeForm(std::string name, const std::string target)
{
	std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*(Intern::*createForm[ 3 ])( const std::string& ) const = { &Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPresidential};

	for(int i = 0; i < 3; i++)
	{
		if(names[i] == name)
			return ((this->*createForm[ i ])( target ));
	}
	std::cout << "Intern not allowed to create that form" << std::endl;
	return nullptr;
}