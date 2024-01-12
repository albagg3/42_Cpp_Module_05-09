/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:13:28 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/12 15:15:22 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main ()
{
//Simple canonical class testing
	std::cout << YELLOW << "CANONICAL CLASS TESTING" << std::endl;
	Bureaucrat 	buro1("Matias", 10);
	std::cout << buro1;
	Bureaucrat	buro2(buro1);
	std::cout << buro2;
	Bureaucrat 	buro3("Regina", 20);
	std::cout << buro3;
	buro2 = buro3;
	std::cout << buro2;

//Trying to catch specific exceptions
	std::cout << YELLOW << "Trying to create a bureaucrat with level higher than 160 and lower than 1 catching the errors with specific exceptions" << RESET << std::endl;
	try
	{
		Bureaucrat 	buro4("Lola", 160);
		Bureaucrat 	buro5("Olivia", -1);

	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

//Calling any type of exception
	std::cout << YELLOW << "Trying to create a bureaucrat with level lower than 1 catching the error with standard exceptions" << RESET << std::endl;
	try
	{
		Bureaucrat 	buro6("Arturo", 0);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << YELLOW << "Trying to decrease a bureaucrat with level 2 lower than 1" << RESET << std::endl;
	try
	{
		Bureaucrat 	buro4("Lola", 2);
		buro4.incrementGrade();
		buro4.incrementGrade();
		// buro4.incrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << YELLOW << "Trying to decrease a bureaucrat with level 148 lower than 150" << RESET << std::endl;
	try
	{
		Bureaucrat 	buro4("Arturo", 148);
		buro4.decrementGrade();
		buro4.decrementGrade();
		buro4.decrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}