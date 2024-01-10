/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:13:28 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/10 17:42:31 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"

int main ()
{
	//We create a pointer AForm so it can be any of the diferent forms we have???
	//*************************************//
	//				INTERN				   //
	//*************************************//
	std::cout << YELLOW << "Intern creates 3 forms and try to create one that can't create" << RESET << std::endl;
	try{
		Intern someRandomIntern;
		AForm* rrf;
		AForm* scf;
		AForm* ppf;
		AForm* notform;
		
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		scf = someRandomIntern.makeForm("shrubbery creation", "Tree");
		ppf = someRandomIntern.makeForm("presidential pardon", "Wiii");
		notform = someRandomIntern.makeForm("ddd", "no exist");
		delete rrf;
		delete scf;
		delete ppf;

	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}	
}
