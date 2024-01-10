/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagarc <albagarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 19:16:27 by albagarc          #+#    #+#             */
/*   Updated: 2024/01/10 16:10:24 by albagarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"
// #include "fstream.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;
		PresidentialPardonForm();
		void executingForm() const;

	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& original);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(const PresidentialPardonForm& rhs);
};

std::ostream&	operator<<(std::ostream &out, const PresidentialPardonForm &object);

#endif