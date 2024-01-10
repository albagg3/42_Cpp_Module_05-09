/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:13:28 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/10 10:38:19 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main ()
{
	//*************************************//
	//				SHRUBBERY			   //
	//*************************************//
	std::cout << YELLOW << "Creating a SHRUBBERY form:\n1. with a bureacrat that is not allowed to execute it " << RESET << std::endl;
	try{
		ShrubberyCreationForm test("home");
		Bureaucrat buro1("Arturo", 140);
		buro1.signForm(test);	
		buro1.executeForm(test);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}	
	std::cout << YELLOW << "2. The form is not signed" << std::endl;
	try{

		ShrubberyCreationForm test("home");
		Bureaucrat buro2("Micaela", 14);
		buro2.executeForm(test);
	}
	catch(std::exception &e){	
		std::cout << e.what() << std::endl;
	}	
	std::cout << YELLOW << "3. The form is signed and the bureacrat's grade is good to sign." << std::endl;
	try{

		ShrubberyCreationForm test("home");
		Bureaucrat buro3("Olivia", 14);
		buro3.signForm(test);
		buro3.executeForm(test);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}	

	//*************************************//
	//				ROBOTOMY			   //
	//*************************************//
 	std::cout << YELLOW << "Creating a ROBOTOMY form:\n1. with a bureacrat that is not allowed to execute it " << RESET << std::endl;
 	try{
		RobotomyRequestForm test("homerobo");
		Bureaucrat buro1("Arturo", 70);
		// Bureaucrat buro1("Arturo", 5);
		buro1.signForm(test);	
		buro1.executeForm(test);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}	
	std::cout << YELLOW << "2. The form is not signed" << std::endl;
	try{

		RobotomyRequestForm test("home");
		Bureaucrat buro2("Micaela", 14);
		buro2.executeForm(test);
	}
	catch(std::exception &e){	
		std::cout << e.what() << std::endl;
	}	
	std::cout << YELLOW << "3. The form is signed and the bureacrat's grade is good to sign." << std::endl;
	try{

		RobotomyRequestForm test("home");
		Bureaucrat buro3("Olivia", 14);
		buro3.signForm(test);
		buro3.executeForm(test);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}	
	
	//*************************************//
	//		PRESIDENTIAL PARDON 		   //
	//*************************************//
	std::cout << YELLOW << "Creating a PRESIDENTIAL PARDON form:\n1. with a bureacrat that is not allowed to execute it " << RESET << std::endl;
	try{
		PresidentialPardonForm test("homerobo");
		Bureaucrat buro1("Arturo", 20);
		buro1.signForm(test);	
		buro1.executeForm(test);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}	
	std::cout << YELLOW << "2. The form is not signed" << std::endl;
	try{

		PresidentialPardonForm test("home");
		Bureaucrat buro2("Micaela", 14);
		buro2.executeForm(test);
	}
	catch(std::exception &e){	
		std::cout << e.what() << std::endl;
	}	
	std::cout << YELLOW << "3. The form is signed and the bureacrat's grade is good to sign." << std::endl;
	try{

		PresidentialPardonForm test("home");
		Bureaucrat buro3("Olivia", 3);
		buro3.signForm(test);
		buro3.executeForm(test);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}	
}
