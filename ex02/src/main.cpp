/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:13:28 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/09 15:54:33 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main ()
{
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
 
}