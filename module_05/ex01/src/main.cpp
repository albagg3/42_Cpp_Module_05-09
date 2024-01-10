/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:13:28 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/10 17:18:45 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
int main ()
{
	std::cout << YELLOW << "Trying to sign a form grade 20 with a bureacrat grade 10 and another grade 40 " << RESET << std::endl;
	try{
		Form form1("visa", 20, 30);
		// Form form2("TOEFL", 152, 30);
		std::cout << form1;
		Bureaucrat buro1("Arturo", 10);
		Bureaucrat buro2("Olivia", 40);
		buro1.signForm(form1);	
		buro2.signForm(form1);	
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}	
}