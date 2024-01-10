/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:42:29 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/10 16:06:26 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
	public:
		Intern();
		Intern(const Intern& original);
		~Intern();

		Intern&	operator=(const Intern& rhs);

		AForm*	makeForm(std::string name, std::string target);
		AForm* createShrubbery(const std::string& target) const;
		AForm* createRobotomy(const std::string& target) const;
		AForm* createPresidential(const std::string& target) const;
};

#endif