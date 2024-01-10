/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:40:33 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/09 15:47:34 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <exception>
#include "AForm.hpp"

#define RED "\e[91m"
#define GREEN "\e[92m"
#define YELLOW "\e[93m"
#define GREY "\e[90m"
#define RESET "\e[0m"

class	Bureaucrat
{
	private:
		const std::string	_name;
		int 				_grade;
		Bureaucrat();									//Constructor lo ponemos privado para que nadie lo pueda llamar

	public:
		Bureaucrat(const Bureaucrat& original);			//Constructor copia
		Bureaucrat(const std::string name, int grade);	//Constructor name&grade
		~Bureaucrat();									//Destructor

		Bureaucrat&			operator=(const Bureaucrat& rhs);
		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm& form);
		void				executeForm(const AForm&  form); 

		class 				GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw(); 
		};
		class 				GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw(); 
		};
	
};

std::ostream&	operator<<(std::ostream&  out, const Bureaucrat& object);

#endif