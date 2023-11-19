/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:43:13 by albagarc          #+#    #+#             */
/*   Updated: 2023/11/19 18:19:43 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <exception>
// #include "Bureaucrat.hpp"

#define RED "\e[91m"
#define GREEN "\e[92m"
#define YELLOW "\e[93m"
#define GREY "\e[90m"
#define RESET "\e[0m"

class Bureaucrat;

class Form 
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_grade_to_sign;
		const int			_grade_to_execute;
		Form();

	public:
		Form(const Form& original);
		Form(const std::string name, const int grade_to_sign, const int _grade_to_execute);
		~Form();

		Form&		operator=(const Form& rhs);

		const 	std::string& getName() const;	
		const	bool& 	getIsSigned() const;	
		const 	int& getGradeToSign() const;	
		const 	int& getGradeToExecute() const;
		void	beSigned(const Bureaucrat& bureaucrat);	

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &out, const Form &object);

#endif