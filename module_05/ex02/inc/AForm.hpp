/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:43:13 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/10 12:43:31 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include <exception>
// #include "Bureaucrat.hpp"

#define RED "\e[91m"
#define GREEN "\e[92m"
#define YELLOW "\e[93m"
#define GREY "\e[90m"
#define RESET "\e[0m"

class Bureaucrat;

class AForm 
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_grade_to_sign;
		const int			_grade_to_execute;
		AForm();
	
	protected:
		virtual void			executingForm() const = 0;

	public:
		AForm(const AForm& original);
		AForm(const std::string name, const int grade_to_sign, const int _grade_to_execute);
		virtual ~AForm();

		AForm&		operator=(const AForm& rhs);

		const 	std::string& 	getName() const;	
		const	bool& 			getIsSigned() const;	
		const 	int& 			getGradeToSign() const;	
		const 	int& 			getGradeToExecute() const;
		void					beSigned(const Bureaucrat& bureaucrat);
		void					execute(const Bureaucrat& executor) const;
		

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
		class	FormNotSigned : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &out, const AForm &object);

#endif