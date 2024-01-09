/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:13:28 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/09 13:07:39 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main ()
{
//Simple canonical class testing
//ES ESTA LA UNICA FORMA DE CREAR UN FORM O SE PUEDE CREAR SIN PUNTERO??
	// Form *form1 = new Form();
	// std::cout << *form1;
	// delete form1;
std::cout << YELLOW << "Trying to sign a form grade 20 with a bureacrat grade 10 and another grade 40 " << RESET << std::endl;
try{
	// AForm form1("visa", 20, 30);
	
	ShrubberyCreationForm test("home");
	
	// Form form2("TOEFL", 152, 30);
	// std::cout << form1;
	// Bureaucrat buro1("Arturo", 10);
	// Bureaucrat buro2("Olivia", 40);
	// buro1.signForm(form1);	
	// buro2.signForm(form1);	
}
catch(std::exception &e)
{
	std::cout << e.what() << std::endl;
}	


//Trying to sign a form grade 20 with a bureacrat grade 10 
// std::cout << YELLOW << "Trying to sign a form grade 20 with a bureacrat grade 10 " << RESET << std::endl;
// 	try
// 	{
// 		form1.beSigned(buro1);	
// 	}
// 	catch(std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}

// std::cout << YELLOW << "Trying to sign a form grade 20 with a bureacrat grade 40 " << RESET << std::endl;
// 	try
// 	{
// 		form1.beSigned(buro2);	
// 	}
// 	catch(std::exception &e)
// 	{
// 		std::cout << e.what() << std::endl;
// 	}


}