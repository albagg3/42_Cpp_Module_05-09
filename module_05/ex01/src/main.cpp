/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:13:28 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/12 12:19:21 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
int main ()
{
	std::cout << YELLOW << "Trying to create a form that is too low. Forms can have from grade 1 to grade 150 " << RESET << std::endl;
	try{
		Form form2("TOEFL", 152, 30);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}	
	std::cout << YELLOW << "Trying to sign a form grade 20 with a bureacrat grade 10 and another grade 40 " << RESET << std::endl;
	try{
		Form form1("visa", 20, 30);
		std::cout << form1;
		Bureaucrat buro1("Arturo", 10);
		Bureaucrat buro2("Olivia", 40);
		buro1.signForm(form1);	
		buro2.signForm(form1);	
		form1.beSigned(buro1);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}	
	std::cout << YELLOW << "Trying to sign a form  using beSigned with a bureaucrat that can sign" << RESET << std::endl;
	try{
		Form form1("visa", 20, 30);
		std::cout << form1;
		Bureaucrat buro1("Arturo", 10);
		form1.beSigned(buro1);
		std::cout << form1;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}